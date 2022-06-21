#pragma once

#include <string>
#include <map>

class Gamble
{
public:
    using container_t = std::map<std::string, int>;

public:
    Gamble();

    void makePrediction(std::string userName, int prediction);
    void printDebugInfo() const noexcept;
    bool empty() const noexcept;
    container_t::const_iterator getClosestPrediction() const noexcept;
    
private:
    container_t m_predictions;
    const int   m_secretNumber;
};