#include "src/HeptaSat.h"

HeptaCdh cdh;
HeptaEps eps;
HeptaLightTemt6000 light;

void setup() {
  cdh.begin();
  eps.init();
  eps.switch_3V3_on();

  if (!light.begin(USER1)) {
    cdh.println("Light sensor init failed");
    while (true) {
      delay(1000);
    }
  }

  cdh.println("TEMT6000 ready");
}

void loop() {
  float voltage = light.get_voltage();
  float lux = light.get_lux();

  cdh.printf("Voltage: %.3f [V]\r\n", voltage);
  cdh.printf("Illuminance (approx): %.1f [lux]\r\n", lux);

  delay(1000);
}
