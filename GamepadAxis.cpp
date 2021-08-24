// 
// 
// 
#include <eRCaGuy_NewAnalogRead.h>
#include "GamepadAxis.h"
#include "string.h"

GamepadAxis::GamepadAxis() {

}
GamepadAxis::GamepadAxis(uint8_t pin) {
	setPin(pin);
}
void GamepadAxis::setPin(uint8_t pin) {
	myPin = pin + 1;
}
void GamepadAxis::setup() {
	if (myPin) {
		pinMode(myPin - 1, INPUT);
	}
}

uint16_t GamepadAxis::readPin() {
	return readPinBit10();
}
//Unaddulturated Value
uint16_t GamepadAxis::readPinBit10() {
	if (myPin) {
		analogRead(myPin - 1);
		delay(1);
	}
	return 1023 / 2;//Normal value
}
//Undersampled (well, we actually just divide by 4, trim takes care of that .75 remained)
uint8_t GamepadAxis::readPinBit8() {
	return readPinBit10() / 4;
}
//Oversammpled (We use the fancy math library (link later) to oversample
uint16_t GamepadAxis::readPinBit16() {
	if (!(myPin)) {
		uint16_t ret = 1;
		return (ret << 15) - 1;
	}

	//Oversample
	return adc.newAnalogRead(myPin - 1,16,1,ADC_DEFAULT);
}
String GamepadAxis::toString() {
	return toString(readPinBit10());
}
String GamepadAxis::toString(uint16_t value) {
	return String(value);
}