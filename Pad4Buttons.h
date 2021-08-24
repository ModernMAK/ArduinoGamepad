// Pad4Buttons.h

#ifndef _PAD4BUTTONS_h
#define _PAD4BUTTONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Pad4Buttons {
public:
	Pad4Buttons(int pins[4]);
	Pad4Buttons(int pin0, int pin1, int pin2, int pin3);

private:
	int myPins[4];
	bool hasSetup;

public:
	void setup();
	void loop();

private:
	byte
		myValue,
		myDirtyBits;
	bool
		hasSerialized;

protected:
	void setValue(int buttonIndex, bool nValue);
	void setDirty(int buttonIndex, bool dirty);

	void setValue(byte nValue);
	void setDirty(byte dirty);
	bool readPin(int buttonIndex);
	byte readPins();

public:
	void setSerialized(bool serialized);

	byte getValue();
	byte getDirty();
	bool getValue(int buttonIndex);
	bool getDirty(int buttonIndex);
	bool getSerialized();
	bool getDirtyOverall();
	bool shouldSerialize(bool ignoreSerialized = false);
};


#endif

