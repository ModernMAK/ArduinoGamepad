
#ifndef _DIGITLAXIS_h
#define _DIGITLAXIS_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "arduino.h"
#else
  #include "WProgram.h"
#endif

#include "eRCaGuy_NewAnalogRead.h"

class DigitalAxis {
  private:
    uint8_t myPins[];
    
  public:
    DigitalAxis();
    DigitalAxis(uint8_t pin);
    void setPositivePin(uint8_t pin);
    void setNegativePin(uint8_t pin);
    void setPins(uint8_t positivePin, uint8_t negativePin);
    void setup();
    //Same as readPinBit10
    uint16_t readPin();
    uint16_t readPinBit10();
    uint8_t readPinBit8();
    uint16_t readPinBit16();
    String toString();

    static String toString(uint16_t value);
};

#endif

//DigitalPins
  //DigitalAxis
  //Button
  //DigitalDirectionalPad
//AnalogPins
  //AnalogAxis
  //AnalogDirectionalPad

//All
  //setup()
  //setPins(int size, int vardic)
  //toString()
class GamepadBase{
  public:
    GamepadBase();
    virtual void setup() = 0;
    virtual void setPins(uint8_t size, uint8_t pins...) = 0;
    virtual String toString() = 0;    
};

//Axis  
  //read(precision);
class AxisBase : public GamepadBase{
  public:
    //Gamepad as of now, only supports messages of 16 bits or less, so we won't read precision higher than 16
    virtual uint16_t read(uint8_t bitPrecision) = 0;
};

//DirPad
  //read();
class DirectionalPadBase : public GamepadBase{
  public:
    virtual uint8_t read();
};
  

//Button
  //read();
class ButtonBase : public GamepadBase{
  public:
    virtual uint32_t read();
};

class DigitalAxis : public AxisBase{
  public:
    
}

  
