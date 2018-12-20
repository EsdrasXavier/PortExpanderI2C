/**
 * Created by Esdras Xavier Raimundo on 13/05/2018
 * @brief This lib is an implementation of port expander using I2C protocol
 * @author Esdras Xavier <esdrasxa@gmail.com>
 * @version 1.0 13/05/2018
 *
 * @reference:
 *  Library based on:
 *  - https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
 *  - http://blog.iharder.net/2014/08/08/msp430-or-arduino-library-for-pcf8574-i2c-port-expander/
*/


#include "PortExpanderI2C.hpp"

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


PortExpanderI2C::PortExpanderI2C(uint8_t addr) {
  this->_addr = addr;
}

PortExpanderI2C::~PortExpanderI2C() {
  Wire.endTransmission();
}

void PortExpanderI2C::init() {
  this->_portValues = 0x00;
  Wire.begin();
  i2cWrite(this->_portValues);
}
void PortExpanderI2C::pinMode(uint8_t port, uint8_t mode) {
  if (mode == INPUT) { // In case be input set the chip HIGH and wait until be pulled to ground
    digitalWrite(port, HIGH);
  }
}

void PortExpanderI2C::digitalWrite(uint8_t port, uint8_t level) {
  if( level == LOW ) {
    this->_portValues &= ~(1 << port);    // Clear the bit.
  } else {
    this->_portValues |= (0x01 << port);  // Set the bit.
  }
	i2cWrite(this->_portValues);
}

void PortExpanderI2C::digitalWriteAll(uint8_t levels) {
  this->_portValues = levels;
  i2cWrite(this->_portValues);
}

void PortExpanderI2C::digitalToggle(uint8_t port) {
  this->_portValues ^= (1 << port);
  i2cWrite(this->_portValues);
}

void PortExpanderI2C::on(uint8_t port) {
  digitalWrite(port, HIGH);
}

void PortExpanderI2C::off(uint8_t port) {
  digitalWrite(port, LOW);
}

uint8_t PortExpanderI2C::digitalRead(uint8_t port){
  Wire.requestFrom(this->_addr, (uint8_t) 1);
  uint8_t resp = Wire.read();
  return (resp & (1 << port)) > 0 ? HIGH : LOW;
}

uint8_t PortExpanderI2C::digitalReadAll(){
  Wire.requestFrom(this->_addr, (uint8_t) 1);
  uint8_t resp = Wire.read();
  return resp;
}

void PortExpanderI2C::i2cWrite(uint8_t data){
	Wire.beginTransmission(this->_addr);
  Wire.write(data);
	Wire.endTransmission();
}

