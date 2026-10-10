# Part 1: IoT-Based Real-Time Environmental Sensing and Data Acquisition Unit

**Project:** Smart Environmental Monitoring & Automated Alert System
**Author:** Jawahar S (25BIT0343)

## Overview
This part covers the sensing node of the project: measuring temperature, humidity, air quality and smoke/gas with an ESP32 and three sensors, calibrating the gas sensors, and transmitting the readings in real time to the other modules (dashboard and alert system).

## Hardware
| Component | Purpose |
|---|---|
| ESP32 DevKit V1 | Microcontroller with Wi-Fi |
| DHT22 | Temperature and humidity |
| MQ135 | Air quality (CO2-equivalent) |
| MQ-2 | Smoke / LPG |
| 10k and 20k resistors | Voltage dividers (5 V sensor output to 3.3 V ADC) and DHT22 pull-up |

## Files in this folder
| File | Description |
|---|---|
| circuit_connections.md | Pin connections between ESP32 and sensors |
| diagram.json | Wokwi circuit simulation configuration |
| calibration_notes.md | Sensor calibration procedure |
| sensor_data_sample.csv | Sample sensor readings (simulated data) |

## Data transmission
- Protocol: MQTT over Wi-Fi
- Interval: every 5 seconds
- Format: JSON

Example fields: temperature_c, humidity_pct, mq135_co2_ppm, mq2_smoke_ppm, air_quality

## Air quality levels (CO2-equivalent)
| Level | ppm |
|---|---|
| GOOD | below 600 |
| MODERATE | 600 to 999 |
| POOR | 1000 to 1999 |
| HAZARDOUS | 2000 and above |

## Note
The readings in sensor_data_sample.csv are simulated sample data used for testing the data format and the downstream modules. MQ sensor ppm values are approximate and suitable for trend and threshold alerts, not for laboratory-grade measurement.
