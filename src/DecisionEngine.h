#ifndef DECISION_ENGINE_H
#define DECISION_ENGINE_H

#include <Arduino.h>

class DecisionEngine {
public:
    struct InputData {
        float soilMoisturePercent;
        float temperatureCelsius;
        float humidityPercent;
    };

    float computeScore(const InputData& input) const;
    bool shouldIrrigate(float decisionScore) const;

private:
    float normalizeMoisture(float soilMoisturePercent) const;
    float normalizeTemperature(float temperatureCelsius) const;
    float normalizeHumidity(float humidityPercent) const;
};

#endif  // DECISION_ENGINE_H
