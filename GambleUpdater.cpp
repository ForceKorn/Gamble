#include "GambleUpdater.h"

GambleUpdater::GambleUpdater(Gamble& container, Gamble::container_t::value_type predictionToInsert)
    : gamble(container), prediction(predictionToInsert) {}


void GambleUpdater::updateGamble()
{
    const auto& [name, predictionValue] = prediction;
    gamble.makePrediction(name, predictionValue);
}
