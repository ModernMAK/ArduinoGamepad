// GamepadHidMediator.h


#ifndef _GAMEPADHIDMEDIATOR_h
#define _GAMEPADHIDMEDIATOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "string.h"

class GamepadMediator {//: public Gamepad_{
	public:
		GamepadMediator();
		void setup();
		void setButtonPins(int, byte...);
		int32_t readButtons();
		String displayButtons();

		void setAxisXPin(byte);
		void setAxisXPin(byte, byte);
		uint16_t readAxisX();
		String displayAxisX();

		void setAxisYPin(byte);
		void setAxisYPin(byte, byte);
		uint16_t readAxisY();
		String displayAxisY();


		void setAxisXrPin(byte);
		void setAxisXrPin(byte, byte);
		uint16_t readAxisXr();
		String displayAxisXr();

		void setAxisYrPin(byte);
		void setAxisYrPin(byte, byte);
		uint16_t readAxisYr();
		String displayAxisYr();

		String display();

	private:
		//Both the Board and the Comp count from 0
		//But we need a Not set or Null bit, so we will use 0
		byte 
			myButtonPins[32], //32
		//Same problem, but we will either be using
		//2 Potentiometers
		//4 buttons (Cardinal)
		//8 buttons (Cardinal + Ordinal)
			myDirectionalPadAxPins[8], //16
			myDirectionalPadBPins[8],
		//Same problem, but we will either be using
		//1 Potentiometers 
		//2 buttons (+ / 0 / -)
			myAxisXPins[2], //12
			myAxisYPins[2],
			myAxisZPins[2],
			myAxisXrPins[2],
			myAxisYrPins[2],
			myAxisZrPins[2];

		bool
			myDireectionalPadAButtons,
			myDireectionalPadBButtons,
			myAxisXButtons,
			myAxisYButtons,
			myAxisZButtons,
			myAxisXrButtons,
			myAxisYrButtons,
			myAxisZrButtons;

};
#endif

