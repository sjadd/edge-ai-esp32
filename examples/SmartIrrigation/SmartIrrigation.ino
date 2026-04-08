#include <SmartFarmController.h>

constexpr uint8_t IRRIGATION_RELAY_PIN = 5;

SmartFarmController controller(IRRIGATION_RELAY_PIN);

static float simulatedSoilMoisture = 38.0f;
static float simulatedTemperature = 33.0f;
static float simulatedHumidity = 42.0f;

void printSystemState() {
    Serial.println("========================================");
    Serial.print("Soil Moisture (%): ");
    Serial.println(controller.getSoilMoisture(), 1);

    Serial.print("Temperature (C): ");
    Serial.println(controller.getTemperature(), 1);

    Serial.print("Humidity (%): ");
    Serial.println(controller.getHumidity(), 1);

    Serial.print("Decision Score: ");
    Serial.println(controller.getDecisionScore(), 2);

    Serial.print("Action: ");
    Serial.println(controller.isIrrigationOn() ? "IRRIGATION ON" : "IRRIGATION OFF");
}

void updateSimulatedInputs() {
    static unsigned long lastSimulationUpdate = 0;

    if (millis() - lastSimulationUpdate < 6000) {
        return;
    }

    lastSimulationUpdate = millis();

    simulatedSoilMoisture -= 2.5f;
    if (simulatedSoilMoisture < 18.0f) {
        simulatedSoilMoisture = 52.0f;
    }

    simulatedTemperature += 0.7f;
    if (simulatedTemperature > 39.0f) {
        simulatedTemperature = 29.0f;
    }

    simulatedHumidity -= 1.8f;
    if (simulatedHumidity < 28.0f) {
        simulatedHumidity = 55.0f;
    }
}

void setup() {
    Serial.begin(115200);
    delay(1000);

    controller.begin();
    controller.setSensorValues(simulatedSoilMoisture, simulatedTemperature, simulatedHumidity);
    controller.update();

    Serial.println("SmartFarm Edge AI Irrigation Demo Started");
    printSystemState();
}

void loop() {
    updateSimulatedInputs();

    controller.setSensorValues(simulatedSoilMoisture, simulatedTemperature, simulatedHumidity);
    controller.update();

    static unsigned long lastReportTime = 0;
    if (millis() - lastReportTime >= 3000) {
        lastReportTime = millis();
        printSystemState();
    }
}
