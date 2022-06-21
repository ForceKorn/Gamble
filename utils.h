#pragma once

#include <iostream>
#include <string>
#include <random>
#include <chrono>

#include <windows.h>

namespace rnd
{
    inline std::random_device gs_generator;
    inline static const std::uniform_int_distribution<int> gsk_distribution(INT_MIN, INT_MAX);

    int generateNumber();
}


inline static constexpr size_t gsk_LoopTime = 20;
const auto gsk_finishTime = std::chrono::high_resolution_clock::now() + std::chrono::seconds(gsk_LoopTime);
bool isTimeUp();


std::string readName();
int readPrediction();


inline auto HandleWrapperDeleter = [] (HANDLE threadHandle)
{
    if (threadHandle)
    {
        CloseHandle(threadHandle);
    }
};

using UniquePtrHandle = std::unique_ptr<std::remove_pointer_t<HANDLE>, decltype(HandleWrapperDeleter)>;