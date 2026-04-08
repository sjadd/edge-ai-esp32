#ifndef SMART_FARM_CONTROLLER_H
#define SMART_FARM_CONTROLLER_H

#include <Arduino.h>
#include "DecisionEngine.h"

class SmartFarmController {
public:
    explicit SmartFarmController(uint8_t irrigationRelayPin);

    void begin();
    void update();

    void setSensorValues(float soilMoisturePercent, float temperatureCelsius, float humidityPercent);

    float getDecisionScore() const;
    bool isIrrigationOn() const;

    float getSoilMoisture() const;
    float getTemperature() const;
    float getHumidity() const;

private:
    uint8_t _irrigationRelayPin;
    bool _irrigationOn;
    float _decisionScore;

    DecisionEngine _decisionEngine;
    DecisionEngine::InputData _inputData;

    void processDecision();
    void applyActuation();
};

#endif  // SMART_FARM_CONTROLLER_H
