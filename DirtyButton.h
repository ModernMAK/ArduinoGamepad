// DirtyButton.h

#ifndef _DIRTYBUTTON_h
#define _DIRTYBUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <DirtyValue.h>
class DirtyButton : DirtyValue<bool> {
	public:
		DirtyButton(int button);
	private:
		int myPin;
		bool hasSetup;

		bool readPin();
	public:
		void setup();
		void loop();
};
#endif

