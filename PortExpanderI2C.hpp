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

#ifndef PortExpanderI2C_h
#define PortExpanderI2C_h

#include <Wire.h>

#define P0 0
#define P1 1
#define P2 2
#define P3 3
#define P4 4
#define P5 5
#define P6 6
#define P7 7

class PortExpanderI2C {
public:

  /**
   * @constructor
   * @abstract     Class constructor
   * @discussion   Initialize the class and set all the pins as off
   * @param address: i2c chip address
  */
  PortExpanderI2C(uint8_t addr);

  /**
   * @desconstructor
   * @abstract     Destroy the object and ends the trasmission
  */
  ~PortExpanderI2C();

  /**
   * @method
   * @abstract     Object initializer
   * @discussion   This method exists because on arduino you must to fallow
   * an order of initialization, and to be able to conect using i2c you have
   * to wait until the setup be called, otherwise the arduino will crash. So
   * call this method on setup
  */
  void init();


  /**
   * @method
   * @abstract     Define the pin port mode
   * @discussion   Will define the port to input or output
   * @param port: The port to use as input or output. Use P0...P7
   * @param mode: The mode to the port works as input or output
  */
  void pinMode(uint8_t port, uint8_t mode);


  /**
   * @method
   * @abstract     Set the port to high or low
   * @discussion   Will turn on or off the port
   * @param port: The port to change the state. Use P0...P7
   * @param level: The level of the port, HIGH or LOW
  */
  void digitalWrite(uint8_t port, uint8_t level);


  /**
   * @method
   * @abstract     Configure all ports
   * @discussion   This method will change all ports states
   * at same time
   * @param levels: The level of the port, HIGH or LOW
  */
  void digitalWriteAll(uint8_t levels);

  /**
   * @method
   * @abstract     Invert the port state
   * @discussion   Change the actual state of a port, case is HIGH
   * set to LOW, case LOW set to HIGH
   * @param port: The port to change the state. Use P0...P7
  */
  void digitalToggle(uint8_t port);

  /**
   * @method
   * @abstract     Turn on a port
   * @discussion   Will turn the port to HIGH
   * @param port: The port to change the state. Use P0...P7
  */
  void on(uint8_t port);

  /**
   * @method
   * @abstract     Turn off a port
   * @discussion   Will turn the port to LOW
   * @param port: The port to change the state. Use P0...P7
  */
  void off(uint8_t port);

  /**
   * @method
   * @abstract     Get the port state
   * @discussion   Read the port and return the state
   * @param port: The port to read. Use P0...P7
   * @return Will return HIGH or LOW
  */
  uint8_t digitalRead(uint8_t port);

  /**
   * @method
   * @abstract     Get the port state
   * @discussion   Read the all the ports port and return the state
   * @return Will return HIGH or LOW
  */
  uint8_t digitalReadAll();

private:
  void i2cWrite(uint8_t);
  uint8_t _addr;
  uint8_t _portValues;

};

#endif