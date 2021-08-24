
#include <eRCaGuy_NewAnalogRead.h>
#include "GamepadDirty.h"
//#include <eRCaGuy_NewAnalogRead.h>

GamepadDirty gamePad = {};
void setup()
{
	gamePad.setButtonPins(4, 8, 9, 10, 11);
	Serial.begin(9600);
	while (!Serial) {
		; // wait for serial port to connect. Needed for native USB port only
	}
	gamePad.setup();
	Serial.println("Setup");
}

void loop()
{
	gamePad.update();
	if (gamePad.getDirty()) {
		Serial.println(gamePad.toString()); 
		gamePad.setDirty(false);
	}
	delay(100);
}
