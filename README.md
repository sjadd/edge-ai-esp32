# SmartFarm Edge AI for ESP32

SmartFarm Edge AI is a modular Arduino ESP32 project for smart irrigation decision-making in precision agriculture.

This repository demonstrates a lightweight edge intelligence workflow that:
- ingests environmental sensor values
- computes an irrigation decision score
- activates irrigation based on local logic
- runs fully on-device using ESP32-compatible C++

The current release uses simulated input values to keep the project easy to understand, easy to test, and ready for public GitHub presentation.

## Project objective

The objective of this project is to show how edge-side agricultural intelligence can be implemented in a structured and reusable embedded software design. Rather than using a heavy machine learning model, this project applies a clean weighted decision engine that is practical for low-power IoT deployments.

## Why this project is useful

In smart farming environments, irrigation decisions are often influenced by multiple variables, not a single threshold. Soil moisture, air temperature, and humidity all affect how quickly water stress can develop in crops.

This project reflects that engineering reality with a professional embedded design that can later be extended to real sensors, MQTT publishing, dashboards, and cloud integration.

## Features

- Modular C++ architecture for Arduino/ESP32
- Simulated smart farming sensor inputs
- Weighted edge decision engine
- Automatic irrigation actuation logic
- Clear serial monitoring output
- Public GitHub-ready project structure

## System architecture

The repository is organized into two main modules:

### 1. DecisionEngine
Calculates an irrigation decision score using:
- soil moisture
- temperature
- humidity

### 2. SmartFarmController
Manages:
- sensor input updates
- decision processing
- relay actuation
- system state reporting

## Decision model

The irrigation score is calculated using a weighted formula:

```text
score =
    (0.50 × moisture_factor) +
    (0.30 × temperature_factor) +
    (0.20 × humidity_factor)
```

Irrigation is enabled when:

```text
score >= 0.60
```

This provides a lightweight edge-AI style approach suitable for embedded systems.

## Repository structure

```text
smartfarm-edge-ai-esp32/
├── src/
│   ├── DecisionEngine.h
│   ├── DecisionEngine.cpp
│   ├── SmartFarmController.h
│   └── SmartFarmController.cpp
├── examples/
│   └── SmartIrrigation/
│       └── SmartIrrigation.ino
├── README.md
├── library.properties
├── LICENSE
└── RELEASE_NOTES_v1.0.0.md
```

## Installation

1. Clone or download this repository.
2. Copy the project folder into your Arduino `libraries` directory.
3. Restart the Arduino IDE.
4. Open the example sketch:
   `examples/SmartIrrigation/SmartIrrigation.ino`

## Example serial output

```text
SmartFarm Edge AI Irrigation Demo Started
========================================
Soil Moisture (%): 38.0
Temperature (C): 33.0
Humidity (%): 42.0
Decision Score: 0.61
Action: IRRIGATION ON
```

## Professional value

This project is suitable for a public engineering portfolio because it demonstrates:
- embedded system architecture
- practical edge intelligence for agriculture
- readable and reusable Arduino C++ development
- direct relevance to IoT and precision farming applications

## Roadmap

Planned next improvements:
- real DHT and soil sensor integration
- MQTT communication support
- Wi-Fi integration with SmartFarmWiFiGuard
- cloud synchronization support
- dashboard integration
- configurable thresholds and weights

## Suggested GitHub topics

`esp32` `arduino` `smart-farming` `iot` `edge-ai` `precision-agriculture` `embedded-systems` `irrigation` `agriculture`

## License

MIT License
