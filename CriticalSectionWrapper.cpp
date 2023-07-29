#include "CriticalSectionWrapper.h"

CriticalSectionWrapper::CriticalSectionWrapper() : m_section()
{ 
    InitializeCriticalSection(&m_section); 
}

CriticalSectionWrapper::~CriticalSectionWrapper() 
{ 
    DeleteCriticalSection(&m_section); 
}

void CriticalSectionWrapper::lock() 
{ 
    EnterCriticalSection(&m_section); 
}

void CriticalSectionWrapper::try_lock() 
{ 
    TryEnterCriticalSection(&m_section); 
}

void CriticalSectionWrapper::unlock() 
{ 
    LeaveCriticalSection(&m_section); 
}
