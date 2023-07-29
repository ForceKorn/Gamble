#include <iostream>
#include <mutex>

#include <windows.h>

#include "utils.h"
#include "Gamble.h"
#include "GambleUpdater.h"
#include "CriticalSectionWrapper.h"


CriticalSectionWrapper gambleAccess;

DWORD WINAPI updateGambleCallback(LPVOID data)
{
    GambleUpdater* updater = reinterpret_cast<GambleUpdater*>(data);
    if (updater)
    {
        const std::lock_guard<CriticalSectionWrapper> lock(gambleAccess);
        updater->updateGamble();
    }
    else
    {
        std::cout << "Error: updater object is empty\n";
    }
    
    return 0;
}


int main()
{
    Gamble predictionStorage;
    
    while (!isTimeUp())
    {
        GambleUpdater updater {
            predictionStorage, 
            { readName(), readPrediction() }
        };

        UniquePtrHandle threadWrapeer {
            CreateThread(0, 0, updateGambleCallback, reinterpret_cast<LPVOID>(&updater), 0, 0),
            HandleWrapperDeleter
        };

        if (threadWrapeer.get())
        {
            WaitForSingleObject(threadWrapeer.get(), INFINITE);
        }
        else
        {
            std::cout << "Error: " << GetLastError() << '\n';
        }
    }

    predictionStorage.printDebugInfo();

    if (!predictionStorage.empty())
    {
        const auto& closestIter = predictionStorage.getClosestPrediction();

        std::cout << "User <" << closestIter->first 
                    << "> has the closest <" << closestIter->second << "> value!\n";
    }
    
    system("pause");
    return 0;
}
