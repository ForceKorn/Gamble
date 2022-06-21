#pragma once

#include <windows.h>

class CriticalSectionWrapper
{
public:
    CriticalSectionWrapper();
    ~CriticalSectionWrapper();

    void lock();
    void try_lock();
    void unlock();

    CriticalSectionWrapper(const CriticalSectionWrapper&) = delete;
    CriticalSectionWrapper& operator=(const CriticalSectionWrapper&) = delete;

private:
    CRITICAL_SECTION m_section = {};
};