// GamepadAxis.h

#ifndef _GAMEPADAXIS_h
#define _GAMEPADAXIS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "eRCaGuy_NewAnalogRead.h"

class GamepadAxis {
	private:
		uint8_t myPin;
	public:
		GamepadAxis();
		GamepadAxis(uint8_t pin);
		void setPin(uint8_t pin);
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

