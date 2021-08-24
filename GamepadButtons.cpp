
// 
// 
// 

#include "GamepadButtons.h"


GamepadButtons::GamepadButtons() {

}
GamepadButtons::GamepadButtons(uint8_t size, uint8_t pins...) {
	setPins(size, pins);
}
void GamepadButtons::setPins(uint8_t size, uint8_t pins...) {
	uint8_t index = 0;
	//First set pins to non-zero pin value.
	while (index < size && index < 32) {
		myPins[index] = pins + 1;
		pins++;
		index++;
	}
	//Then set the rest of the pins to zero.
	while (index < 32) {
		myPins[index] = 0x0;
		index++;
	}
}
uint32_t GamepadButtons::readPins() {
	uint32_t bits = 0;
	for (uint8_t i = 0; i < 32; i++) {
		uint8_t pin = myPins[i];
		//non zero means true, and any pin we set is non zero
		if (pin) {
			bitWrite(bits, i, digitalRead(pin - 1));
		}
		else {
			i = 32;
		}
	}
	return bits;
}
void GamepadButtons::setup() {
	for (uint8_t i = 0; i < 32; i++) {
		uint8_t pin = myPins[i];
		//non zero means true, and any pin we set is non zero
		if (pin) {
			pinMode(pin - 1, INPUT);
		}
		else {
			i = 32;
		}
	}
}
String GamepadButtons::toString() {
	return toString(readPins());
};
String GamepadButtons::toString(uint32_t value) {
	String output = "Button(s)";
	bool hit = false;
	for (uint8_t i = 0; i < 32; i++) {
		if (bitRead(value, i)) {
			if (hit) {
				output += ",";
			}
			output += " ";

			output += (i + 1);

			hit = true;
		}
	}
	if (!hit) {
		output += " NONE";
	}
	return output;
};
