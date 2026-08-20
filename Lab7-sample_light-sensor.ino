#include "src/HeptaSat.h"
#include "src/drv/light_temt6000.h"

HeptaCdh cdh;
HeptaEps eps;
LightTemt6000 light;

// V4.1.1 payload ADC: USER1 / USER2 / USER3 -> MCP3208 CH5 / CH6 / CH7
constexpr uint8_t kUserChannel = 1;  // set to 1, 2, or 3
constexpr uint8_t kMcp3208CsPin = 17;

constexpr uint8_t mcp_channel_from_user(uint8_t user) {
  return static_cast<uint8_t>(4 + user);
}

void setup() {
  cdh.begin();
  eps.init();
  eps.switch_3V3_on();

  if (kUserChannel < 1 || kUserChannel > 3) {
    cdh.println("kUserChannel must be 1, 2, or 3");
    while (true) {
      delay(1000);
    }
  }

  const uint8_t mcp_channel = mcp_channel_from_user(kUserChannel);
  if (!light.begin(kMcp3208CsPin, mcp_channel)) {
    cdh.println("Light sensor init failed");
    while (true) {
      delay(1000);
    }
  }

  cdh.printf("TEMT6000 ready (USER%u / MCP3208 ch%u)\r\n", kUserChannel,
             mcp_channel);
}

void loop() {
  float voltage = light.get_voltage();
  float lux = light.get_lux();

  cdh.printf("Voltage: %.3f [V]\r\n", voltage);
  cdh.printf("Illuminance (approx): %.1f [lux]\r\n", lux);

  delay(1000);
}
