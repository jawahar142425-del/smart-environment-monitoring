# ESP32 Sensor Circuit Connections

## DHT22

* VCC: 3.3V (check sensor module specifications)
* GND: ESP32 GND
* DATA: GPIO 4

## MQ135

* VCC: As specified by the sensor module
* GND: ESP32 GND
* AO: GPIO 34 (ADC input)

## MQ-2

* VCC: As specified by the sensor module
* GND: ESP32 GND
* AO: GPIO 35 (ADC input)

## Safety Note

Verify the sensor module's analog output voltage before connecting it to the ESP32. Keep the ESP32 ADC input within its permitted voltage range.
