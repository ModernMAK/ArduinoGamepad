// GamepadDirectionalPad.h

#ifndef _GAMEPADDIRECTIONALPAD_h
#define _GAMEPADDIRECTIONALPAD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "GamepadAxis.h"

class GamepadDirectionalPad {
	private:
		GamepadAxis
			myAxis[2];

	public:
		GamepadDirectionalPad();
		GamepadDirectionalPad(uint8_t xPin, uint8_t yPin);

		void setup();
		void setPins(uint8_t xPin, uint8_t yPin);
		uint8_t readPins();
		static String toString(uint8_t pad);
		String toString();

		static uint8_t axisToPad(uint16_t axis, uint16_t axisScale) {
			if (axis < axisScale / 3) {
				return 0;
			}
			else if (axis > (axisScale / 3) * 2) {
				return 2;
			}
			else return 1;
		}
		static uint8_t lookupReferencePad(uint8_t xValue, uint8_t yValue) {
			return REFERENCE_PAD[xValue][yValue];
		}
		static String lookupReferencePadOutput(uint8_t xValue, uint8_t yValue) {
			return lookupReferencePadOutput(lookupReferencePad(xValue, yValue));
		}
		static String lookupReferencePadOutput(uint8_t padValue) {
			return REFERENCE_PAD_OUTPUT[padValue];
		}

	private:
		static uint8_t REFERENCE_PAD[3][3];
		static String REFERENCE_PAD_OUTPUT[9];
};

#endif

