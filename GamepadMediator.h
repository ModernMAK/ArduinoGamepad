// GamepadMediator.h

#ifndef _GAMEPADMEDIATOR_h
#define _GAMEPADMEDIATOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "GamepadAxis.h"
#include "GamepadButtons.h"
#include "GamepadDirectionalPad.h"

class GamepadMediator {
	private:
		GamepadButtons
			myButtons;
		GamepadDirectionalPad
			myPadA,
			myPadB;
		GamepadAxis
			myAxisX,
			myAxisY,
			myAxisZ,
			myAxisRotX,
			myAxisRotY,
			myAxisRotZ;
			
	public:
		GamepadMediator();
		void setButtonPins(uint8_t size, uint8_t pins...);

		void setup();

		void setPadAPins(uint8_t xPin, uint8_t yPin);
		void setPadBPins(uint8_t xPin, uint8_t yPin);

		void setAxisXPin(uint8_t pin);
		void setAxisYPin(uint8_t pin);
		void setAxisZPin(uint8_t pin);

		void setAxisRotXPin(uint8_t pin);
		void setAxisRotYPin(uint8_t pin);
		void setAxisRotZPin(uint8_t pin);

		uint32_t readButtons();

		uint8_t readPadA();
		uint8_t readPadB();

		uint16_t readAxisX();
		uint16_t readAxisY();
		uint8_t readAxisZ();

		uint16_t readAxisRotX();
		uint16_t readAxisRotY();
		uint8_t readAxisRotZ();

		virtual String toString();
};

#endif

