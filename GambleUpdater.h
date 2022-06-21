#pragma once

#include "Gamble.h"

class GambleUpdater
{
public:
    GambleUpdater(Gamble& container, Gamble::container_t::value_type predictionToInsert);
    void updateGamble();
       
private:
    Gamble& gamble;
    Gamble::container_t::value_type prediction;
};
