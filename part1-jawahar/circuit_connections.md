# ESP32 Sensor Circuit Connections

## DHT22

* VCC: 3.3V
* GND: ESP32 GND
* DATA: GPIO 4, with a 10k pull-up resistor from DATA to 3.3V

## MQ135

* VCC: 5V (ESP32 VIN pin), the heater needs 5V
* GND: ESP32 GND
* AO: through a voltage divider to GPIO 34 (ADC input)

## MQ-2

* VCC: 5V (ESP32 VIN pin), the heater needs 5V
* GND: ESP32 GND
* AO: through a voltage divider to GPIO 35 (ADC input)

## Voltage Divider (for each MQ sensor)

The MQ modules output up to 5V, but the ESP32 ADC accepts a maximum of 3.3V.

```
MQ AO ---[10k]---+--- GPIO 34 (or 35)
                 |
               [20k]
                 |
                GND
```

Vadc = Vao x 20 / (10 + 20) = Vao / 1.5. The firmware multiplies the ADC voltage by 1.5 to recover the sensor voltage.

## Pin Summary

| Sensor | Pin | ESP32 GPIO |
|---|---|---|
| DHT22 | DATA | 4 |
| MQ135 | AO (via divider) | 34 |
| MQ-2 | AO (via divider) | 35 |

## Notes

* Use only ADC1 pins (32 to 39). ADC2 pins do not work while Wi-Fi is on.
* Join all grounds (ESP32, DHT22, MQ135, MQ-2).
* Power from USB or a 5V supply that can give at least 1A. Both MQ heaters together draw about 300 mA.

## Safety Note

Verify the sensor module's analog output voltage before connecting it to the ESP32. Keep the ESP32 ADC input within its permitted voltage range. Never connect an MQ AO pin directly to an ESP32 pin.
