// 
// 
// 

#include "Pad8Buttons.h"

Pad8Buttons::Pad8Buttons(int pin0, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7) {
	myPins[0] = pin0;
	myPins[1] = pin1;
	myPins[2] = pin2;
	myPins[3] = pin3;
	myPins[4] = pin4;
	myPins[5] = pin5;
	myPins[6] = pin6;
	myPins[7] = pin7;
	myDirtyBits = 0x0;
	myValue = 0x0;
	hasSetup = false;
	hasSerialized = false;
}
Pad8Buttons::Pad8Buttons(int pins[]) {
	for (int i = 0; i < 8; i++) {
		myPins[i] = pins[i];
	}
	myDirtyBits = 0x0;
	myValue = 0x0;
	hasSetup = false;
	hasSerialized = false;
}
void Pad8Buttons::setup() {
	for (int i = 0; i < 8; i++) {
		pinMode(myPins[i], INPUT);
	}
	hasSetup = true;
}
void Pad8Buttons::loop() {
	if (!hasSetup) {
		return;
	}
	setValue(readPins());
}

void Pad8Buttons::setValue(int buttonIndex, bool nValue) {
	byte 
		prevDirty = getDirty(),
		prevValue = getValue();
	setDirty(buttonIndex, bitRead(prevDirty,buttonIndex) || getValue(buttonIndex) == nValue);
	bitWrite(myValue, buttonIndex, (nValue ? 1 : 0));
	hasSerialized = hasSerialized && (prevValue == getValue());
}
void Pad8Buttons::setDirty(int buttonIndex, bool dirty) {
	bitWrite(myDirtyBits, buttonIndex, (dirty ? 1 : 0));
}

void Pad8Buttons::setSerialized(bool serialized) {
	hasSerialized = serialized;
}

void Pad8Buttons::setValue(byte nValue) {
	byte 
		prevDirty = getDirty(),
		prevValue = getValue();

	for (int i = 0; i < 8; i++) {
		setDirty(i,bitRead(prevDirty,i) || bitRead(nValue, i) == bitRead(getValue(), i));
	}
	myValue = nValue;
	hasSerialized = hasSerialized && (prevValue == getValue());
}
void Pad8Buttons::setDirty(byte dirty) {
	myDirtyBits = dirty;
}
bool Pad8Buttons::readPin(int buttonIndex) {
	return hasSetup ? digitalRead(myPins[buttonIndex]) : false;
}
byte Pad8Buttons::readPins() {
	byte pins = 0x0;
	if (hasSetup) {
		return pins;
	}
	for (int i = 0; i < 8; i++) {
		bitWrite(pins, i, readPin(i));
	}
	return pins;
}

byte Pad8Buttons::getValue() {
	return myValue;
}
byte Pad8Buttons::getDirty() {
	return myDirtyBits;
}
bool Pad8Buttons::getValue(int buttonIndex) {
	return bitRead(myValue, buttonIndex);
}
bool Pad8Buttons::getDirty(int buttonIndex) {
	return bitRead(myDirtyBits, buttonIndex);
}
bool Pad8Buttons::getSerialized() {
	return hasSerialized;
}
bool Pad8Buttons::getDirtyOverall() {
	for (int i = 0; i < 8; i++) {
		if (bitRead(myDirtyBits, i)) {
			return true;
		}
	}
	return false;
}
bool Pad8Buttons::shouldSerialize(bool ignoreSerialized) {
	return getDirtyOverall() && (ignoreSerialized || !hasSerialized);
	//return hasSerialized;
}

/*
class Pad8Buttons {
private:
	int myPins[8];
	bool hasSetup;
	byte
		myValue,
		myDirtyBits;
	bool
		hasSerialized;

protected:

public:
};
*/