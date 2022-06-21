#include <iostream>
#include <algorithm>

#include "Gamble.h"
#include "utils.h"

Gamble::Gamble() 
    : m_predictions(), m_secretNumber(rnd::generateNumber()) {}

void Gamble::makePrediction(std::string userName, int prediction)
{
    m_predictions.emplace(userName, prediction);
}

Gamble::container_t::const_iterator Gamble::getClosestPrediction() const noexcept
{
    return std::min_element(m_predictions.begin(), m_predictions.end(),
        [secret = m_secretNumber](const auto& lhs, const auto& rhs)
        {
            return std::abs(lhs.second - secret) < std::abs(rhs.second - secret);
        });
}

void Gamble::printDebugInfo() const noexcept
{
    std::cout << "Gamble debug info\n";
    for (const auto& [key, value] : m_predictions)
    {
        std::cout << "{ " << key << ", " << value << " }\n";
    }
}

bool Gamble::empty() const noexcept
{
    return m_predictions.empty();
}