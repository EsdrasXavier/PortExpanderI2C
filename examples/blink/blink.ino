#include <PortExpanderI2C.hpp>

PortExpanderI2C pe(0x20);

void setup() {
  pe.init();
  pe.pinMode(P0, OUTPUT);
}

void loop() {
  pe.digitalWrite(P0, HIGH);
  delay(500);
  pe.digitalWrite(P0, LOW);
  delay(500);
}