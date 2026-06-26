# Lab7-sample_light-sensor

HEPTA-SAT training sample: **SparkFun TEMT6000** ambient light sensor.

## Sensor Specifications

| Item | Value |
|------|-------|
| Part | **TEMT6000** (visible-light phototransistor) |
| Example product | SparkFun SEN-08654, etc. |
| Interface | Analog output → **MCP3208 channel 7** |
| Supply | 3.3 V |
| Output | Voltage proportional to light level (higher = brighter) |
| Illuminance | Approx. `lux ≈ voltage [V] × 200` (uncalibrated) |

## Analog Input Selection

Set `kUseMcp3208` in the sketch:

| `kUseMcp3208` | Connection |
|---------------|------------|
| `true` | **MCP3208 channel 7** (CS = GP17) |
| `false` | **MCU GP28** (ADC2) |

## Wiring (HEPTA-SAT)

| Sensor | HEPTA-SAT |
|--------|-----------|
| Analog output | MCP3208 ch7 **or** GP28 (see above) |
| MCP3208 CS | GP17 (when using MCP3208) |
| VCC | 3.3 V payload |
| GND | GND |

## Build and Upload

1. Open `Lab7-sample_light-sensor.ino` in the Arduino IDE
2. Board: **Raspberry Pi Pico**
3. Set `kUseMcp3208` to match your wiring
4. Compile and upload
5. Serial monitor at **9600 baud**

## Example Serial Output

```
TEMT6000 ready (MCP3208 ch7)
Voltage: 0.825 [V]
Illuminance (approx): 165.0 [lux]
Voltage: 1.650 [V]
Illuminance (approx): 330.0 [lux]
```

## Driver

- `src/drv/light_temt6000.h` / `.cpp`
- Details: `src/docs/drivers/light-temt6000.md`
