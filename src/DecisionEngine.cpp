#include "DecisionEngine.h"

float DecisionEngine::computeScore(const InputData& input) const {
    const float moistureFactor = normalizeMoisture(input.soilMoisturePercent);
    const float temperatureFactor = normalizeTemperature(input.temperatureCelsius);
    const float humidityFactor = normalizeHumidity(input.humidityPercent);

    const float score =
        (0.50f * moistureFactor) +
        (0.30f * temperatureFactor) +
        (0.20f * humidityFactor);

    return constrain(score, 0.0f, 1.0f);
}

bool DecisionEngine::shouldIrrigate(float decisionScore) const {
    return decisionScore >= 0.60f;
}

float DecisionEngine::normalizeMoisture(float soilMoisturePercent) const {
    const float dryness = 100.0f - constrain(soilMoisturePercent, 0.0f, 100.0f);
    return dryness / 100.0f;
}

float DecisionEngine::normalizeTemperature(float temperatureCelsius) const {
    const float minTemp = 15.0f;
    const float maxTemp = 45.0f;
    const float normalized = (temperatureCelsius - minTemp) / (maxTemp - minTemp);
    return constrain(normalized, 0.0f, 1.0f);
}

float DecisionEngine::normalizeHumidity(float humidityPercent) const {
    const float dryness = 100.0f - constrain(humidityPercent, 0.0f, 100.0f);
    return dryness / 100.0f;
}
