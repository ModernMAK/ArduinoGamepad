// 
// 
// 

#include "GamepadMediator.h"

GamepadMediator::GamepadMediator() {
}
void GamepadMediator::setup() {
	myButtons.setup();

	myPadA.setup();
	myPadB.setup();

	myAxisX.setup();
	myAxisY.setup();
	myAxisZ.setup();

	myAxisRotX.setup();
	myAxisRotY.setup();
	myAxisRotZ.setup();
}

void GamepadMediator::setButtonPins(uint8_t size, uint8_t pins...) {
	myButtons.setPins(size, pins);
}

void GamepadMediator::setPadAPins(uint8_t xPin, uint8_t yPin) {
	myPadA.setPins(xPin, yPin);
}
void GamepadMediator::setPadBPins(uint8_t xPin, uint8_t yPin) {
	myPadB.setPins(xPin, yPin);
}

void GamepadMediator::setAxisXPin(uint8_t pin) {
	myAxisX.setPin(pin);
}
void GamepadMediator::setAxisYPin(uint8_t pin) {
	myAxisY.setPin(pin);
}
void GamepadMediator::setAxisZPin(uint8_t pin) {
	myAxisZ.setPin(pin);
}

void GamepadMediator::setAxisRotXPin(uint8_t pin) {
	myAxisRotX.setPin(pin);
}
void GamepadMediator::setAxisRotYPin(uint8_t pin) {
	myAxisRotY.setPin(pin);
}
void GamepadMediator::setAxisRotZPin(uint8_t pin) {
	myAxisRotZ.setPin(pin);
}

uint32_t GamepadMediator::readButtons() {
	return myButtons.readPins();
}

uint8_t GamepadMediator::readPadA() {
	return myPadA.readPins();
}
uint8_t GamepadMediator::readPadB() {
	return myPadB.readPins();
}

uint16_t GamepadMediator::readAxisX() {
	return myAxisX.readPinBit16();
}
uint16_t GamepadMediator::readAxisY() {
	return myAxisY.readPinBit16();
}
uint8_t GamepadMediator::readAxisZ() {
	return myAxisZ.readPinBit8();
}

uint16_t GamepadMediator::readAxisRotX() {
	return myAxisRotX.readPinBit16();
}
uint16_t GamepadMediator::readAxisRotY() {
	return myAxisRotY.readPinBit16();
}
uint8_t GamepadMediator::readAxisRotZ() {
	return myAxisRotZ.readPinBit8();
}
String GamepadMediator::toString() {
	String output = "";

	output += GamepadButtons::toString(readButtons()) + "\n";
	output += "X " + GamepadAxis::toString(readAxisX()) + "\n";
	output += "Y " + GamepadAxis::toString(readAxisY()) + "\n";
	output += "Z " + GamepadAxis::toString(readAxisZ()) + "\n";
	output += "Rot X " + GamepadAxis::toString(readAxisRotX()) + "\n";
	output += "Rot Y " + GamepadAxis::toString(readAxisRotY()) + "\n";
	output += "Rot Z " + GamepadAxis::toString(readAxisRotZ()) + "\n";
	output += "Left Pad " + GamepadDirectionalPad::toString(readPadA()) + "\n";
	output += "Right Pad " + GamepadDirectionalPad::toString(readPadB()) + "\n";

	return output;
}

