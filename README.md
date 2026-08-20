# Lab7-sample_light-sensor

HEPTA-SAT training sample: **SparkFun TEMT6000** ambient light sensor.

## Sensor Specifications

| Item | Value |
|------|-------|
| Part | **TEMT6000** (visible-light phototransistor) |
| Example product | SparkFun SEN-08654, etc. |
| Interface | Analog output → **MCP3208 USER1 / USER2 / USER3** (V4.1.1) |
| Supply | 3.3 V |
| Output | Voltage proportional to light level (higher = brighter) |
| Illuminance | Approx. `lux ≈ voltage [V] × 200` (uncalibrated) |

## Analog Input Selection

Set `kUserChannel` in the sketch to match the board USER pin:

| `kUserChannel` | Board pin | MCP3208 |
|----------------|-----------|---------|
| `1` | **USER1** | CH5 |
| `2` | **USER2** | CH6 |
| `3` | **USER3** | CH7 |

## Wiring (HEPTA-SAT V4.1.1)

| Sensor | HEPTA-SAT |
|--------|-----------|
| Analog output | USER1 / USER2 / USER3 (see `kUserChannel`) |
| VCC | 3.3 V payload (`eps.switch_3V3_on()`) |
| GND | GND |

## Build and Upload

1. Open `Lab7-sample_light-sensor.ino` in the Arduino IDE
2. Board: **Raspberry Pi Pico**
3. Check out the `src/` submodule (`git submodule update --init`)
4. Set `kUserChannel` to match your wiring (`1`, `2`, or `3`)
5. Compile and upload
6. Serial monitor at **9600 baud**

## Example Serial Output

```
TEMT6000 ready (USER1 / MCP3208 ch5)
Voltage: 0.825 [V]
Illuminance (approx): 165.0 [lux]
Voltage: 1.650 [V]
Illuminance (approx): 330.0 [lux]
```

## Driver

- `src/drv/light_temt6000.h` / `.cpp`
- Details: `src/docs/drivers/light-temt6000.md`
