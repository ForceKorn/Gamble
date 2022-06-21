#include "utils.h"


int rnd::generateNumber()
{
    return gsk_distribution(gs_generator);
}

std::string readName()
{
    std::string name;

    std::cout << "Enter name: ";

    std::getline(std::cin, name);
    return name;
}

int readPrediction()
{
    int prediction = 0;

    std::cout << "Enter prediction: ";

    std::cin >> prediction;
    std::cin.get();

    return prediction;
}

bool isTimeUp()
{
    return std::chrono::high_resolution_clock::now() > gsk_finishTime;
}
