#include "SmartFarmController.h"

SmartFarmController::SmartFarmController(uint8_t irrigationRelayPin)
    : _irrigationRelayPin(irrigationRelayPin),
      _irrigationOn(false),
      _decisionScore(0.0f) {
    _inputData.soilMoisturePercent = 0.0f;
    _inputData.temperatureCelsius = 0.0f;
    _inputData.humidityPercent = 0.0f;
}

void SmartFarmController::begin() {
    pinMode(_irrigationRelayPin, OUTPUT);
    digitalWrite(_irrigationRelayPin, LOW);
}

void SmartFarmController::update() {
    processDecision();
    applyActuation();
}

void SmartFarmController::setSensorValues(float soilMoisturePercent,
                                          float temperatureCelsius,
                                          float humidityPercent) {
    _inputData.soilMoisturePercent = soilMoisturePercent;
    _inputData.temperatureCelsius = temperatureCelsius;
    _inputData.humidityPercent = humidityPercent;
}

float SmartFarmController::getDecisionScore() const {
    return _decisionScore;
}

bool SmartFarmController::isIrrigationOn() const {
    return _irrigationOn;
}

float SmartFarmController::getSoilMoisture() const {
    return _inputData.soilMoisturePercent;
}

float SmartFarmController::getTemperature() const {
    return _inputData.temperatureCelsius;
}

float SmartFarmController::getHumidity() const {
    return _inputData.humidityPercent;
}

void SmartFarmController::processDecision() {
    _decisionScore = _decisionEngine.computeScore(_inputData);
    _irrigationOn = _decisionEngine.shouldIrrigate(_decisionScore);
}

void SmartFarmController::applyActuation() {
    digitalWrite(_irrigationRelayPin, _irrigationOn ? HIGH : LOW);
}
