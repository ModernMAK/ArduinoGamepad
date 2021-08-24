// GamepadButtons.h

#ifndef _GAMEPADBUTTONS_h
#define _GAMEPADBUTTONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

//#include "string.h"

class GamepadButtons {
	private:
		uint8_t myPins[32];

	public:
		GamepadButtons();
		GamepadButtons(uint8_t size, uint8_t pins...);
		void setup();
		void setPins(uint8_t size, uint8_t pins...);
		uint32_t readPins();
		String toString();
		static String toString(uint32_t value);
};


#endif

