// 
// 
// 

#include "GamepadDirectionalPad.h"

GamepadDirectionalPad::GamepadDirectionalPad() {
	myAxis[0] = {};
	myAxis[1] = {};
}
GamepadDirectionalPad::GamepadDirectionalPad(uint8_t xPin, uint8_t yPin) {
	//We could also use setPins, but why bother?
	myAxis[0] = {xPin};
	myAxis[1] = {yPin};
}

void GamepadDirectionalPad::setup() {
	myAxis[0].setup();
	myAxis[1].setup();
}
void GamepadDirectionalPad::setPins(uint8_t xPin, uint8_t yPin) {
	myAxis[0].setPin(xPin);
	myAxis[1].setPin(yPin);
}
uint8_t GamepadDirectionalPad::readPins() {
	return lookupReferencePad(
		axisToPad(myAxis[0].readPin(), 1023), //Read X, Normalize to 0-2
		axisToPad(myAxis[1].readPin(), 1023) //Read Y, Normalize to 0-2
	);
}
String GamepadDirectionalPad::toString(uint8_t pad) {
	return lookupReferencePadOutput(pad);
}
String GamepadDirectionalPad::toString() {
	return toString(readPins());
}

uint8_t GamepadDirectionalPad::REFERENCE_PAD[3][3] = { {8,7,6}, {1,0,5}, {2,3,4} };
String GamepadDirectionalPad::REFERENCE_PAD_OUTPUT[9] = { "Center","Up","Up-Right","Right","Down-Right","Down","Down-Left","Left","Up-Left"};