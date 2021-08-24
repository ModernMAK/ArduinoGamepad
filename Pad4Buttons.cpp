// 
// 
// 

#include "Pad4Buttons.h"


Pad4Buttons::Pad4Buttons(int pin0, int pin1, int pin2, int pin3) {
	myPins[0] = pin0;
	myPins[1] = pin1;
	myPins[2] = pin2;
	myPins[3] = pin3;
	myDirtyBits = 0x0;
	myValue = 0x0;
	hasSetup = false;
	hasSerialized = false;
}
Pad4Buttons::Pad4Buttons(int pins[]) {
	for (int i = 0; i < 4; i++) {
		myPins[i] = pins[i];
	}
	myDirtyBits = 0x0;
	myValue = 0x0;
	hasSetup = false;
	hasSerialized = false;
}
void Pad4Buttons::setup() {
	for (int i = 0; i < 4; i++) {
		pinMode(myPins[i], INPUT);
	}
	hasSetup = true;
}
void Pad4Buttons::loop() {
	if (!hasSetup) {
		return;
	}
	setValue(readPins());
}

void Pad4Buttons::setValue(int buttonIndex, bool nValue) {
	byte
		prevDirty = getDirty(),
		prevValue = getValue();
	setDirty(buttonIndex, bitRead(prevDirty, buttonIndex) || getValue(buttonIndex) == nValue);
	bitWrite(myValue, buttonIndex, (nValue ? 1 : 0));
	hasSerialized = hasSerialized && (prevValue == getValue());
}
void Pad4Buttons::setDirty(int buttonIndex, bool dirty) {
	bitWrite(myDirtyBits, buttonIndex, (dirty ? 1 : 0));
}

void Pad4Buttons::setSerialized(bool serialized) {
	hasSerialized = serialized;
}

void Pad4Buttons::setValue(byte nValue) {
	byte
		prevDirty = getDirty(),
		prevValue = getValue();

	for (int i = 0; i < 4; i++) {
		setDirty(i, bitRead(prevDirty, i) || bitRead(nValue, i) == bitRead(getValue(), i));
	}
	myValue = nValue;
	hasSerialized = hasSerialized && (prevValue == getValue());
}
void Pad4Buttons::setDirty(byte dirty) {
	myDirtyBits = dirty;
}
bool Pad4Buttons::readPin(int buttonIndex) {
	return hasSetup ? digitalRead(myPins[buttonIndex]) : false;
}
byte Pad4Buttons::readPins() {
	byte pins = 0x0;
	if (hasSetup) {
		return pins;
	}
	for (int i = 0; i < 4; i++) {
		bitWrite(pins, i, readPin(i));
	}
	return pins;
}

byte Pad4Buttons::getValue() {
	return myValue;
}
byte Pad4Buttons::getDirty() {
	return myDirtyBits;
}
bool Pad4Buttons::getValue(int buttonIndex) {
	return bitRead(myValue, buttonIndex);
}
bool Pad4Buttons::getDirty(int buttonIndex) {
	return bitRead(myDirtyBits, buttonIndex);
}
bool Pad4Buttons::getSerialized() {
	return hasSerialized;
}
bool Pad4Buttons::getDirtyOverall() {
	for (int i = 0; i < 4; i++) {
		if (bitRead(myDirtyBits, i)) {
			return true;
		}
	}
	return false;
}
bool Pad4Buttons::shouldSerialize(bool ignoreSerialized) {
	return getDirtyOverall() && (ignoreSerialized || !hasSerialized);
	//return hasSerialized;
}
