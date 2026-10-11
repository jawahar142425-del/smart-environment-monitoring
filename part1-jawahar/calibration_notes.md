# Sensor Calibration Notes

## Sensors

* MQ135 (air quality, CO2-equivalent)
* MQ-2 (smoke / LPG)
* DHT22 (temperature and humidity)

## Calibration Method

MQ sensors give a resistance (Rs) that changes with gas concentration. Calibration finds R0, the sensor resistance in clean air, so the firmware can convert Rs/R0 into ppm.

1. Burn-in: power new sensors for 24 to 48 hours once.
2. Warm-up: wait at least 5 minutes after every power-on.
3. Take the node to clean, well ventilated air.
4. Send `c` in the Serial Monitor. The firmware averages 50 samples and stores R0 in flash.
5. Send `r` to read the stored R0, `d` to reset to defaults.

Formulas used in the firmware:

* Vout = Vadc x 1.5 (undo the 10k/20k voltage divider)
* Rs = RL x (5 - Vout) / Vout
* MQ135: ppm = 116.6 x (Rs/R0)^-2.769, calibrated so clean air reads about 420 ppm
* MQ-2 smoke: ppm = 3.0e7 x (Rs/R0)^-8.308, with Rs/R0 = 9.83 in clean air

## Testing Procedure

1. Record sensor readings after the required warm-up period.
2. Record readings under normal indoor conditions.
3. Record readings under different safe test conditions.
4. Compare readings and observe changes.
5. Document sensor limitations.

## Calibration Results

To be filled after actual sensor testing.

| Item | Value |
|---|---|
| MQ135 R0 (kOhm) | |
| MQ-2 R0 (kOhm) | |
| Warm-up time used | |
| Date and place of calibration | |

| Test condition | MQ135 CO2 (ppm) | MQ-2 smoke (ppm) | Temp (C) | Humidity (%) | Air quality |
|---|---|---|---|---|---|
| Clean air (outdoors / ventilated) | | | | | |
| Normal indoor | | | | | |
| Closed room with people | | | | | |
| Incense or matchstick smoke near MQ-2 (safe distance) | | | | | |

## Limitations

Raw MQ sensor values alone do not provide an accurate gas concentration in ppm without appropriate calibration.
MQ sensors also respond to several gases and change with temperature and humidity, so the ppm values are estimates suitable for trends and threshold alerts, not laboratory-grade measurement.
