#include "src/HeptaSat.h"
#include "src/drv/light_temt6000.h"

HeptaCdh cdh;
HeptaEps eps;
LightTemt6000 light;

// true: MCP3208 channel 7, false: MCU GP28 (ADC2)
constexpr bool kUseMcp3208 = true;
constexpr uint8_t kMcp3208CsPin = 17;
constexpr uint8_t kMcp3208Channel = 7;
constexpr uint8_t kDirectAdcPin = 28;

void setup() {
  cdh.begin();
  eps.init();
  eps.switch_3V3_on();

  if (!light.begin(kUseMcp3208, kDirectAdcPin, kMcp3208Channel, kMcp3208CsPin)) {
    cdh.println("Light sensor init failed");
    while (true) {
      delay(1000);
    }
  }

  if (kUseMcp3208) {
    cdh.println("TEMT6000 ready (MCP3208 ch7)");
  } else {
    cdh.println("TEMT6000 ready (GP28)");
  }
}

void loop() {
  float voltage = light.get_voltage();
  float lux = light.get_lux();

  cdh.printf("Voltage: %.3f [V]\r\n", voltage);
  cdh.printf("Illuminance (approx): %.1f [lux]\r\n", lux);

  delay(1000);
}
