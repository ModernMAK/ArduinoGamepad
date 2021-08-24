// 
// 
// 

#include "GamepadHidMediator.h"


GamepadMediator::GamepadMediator() {
}

void GamepadMediator::setup() {
	for (int i = 0; i < 32; i++) {
		if (myButtonPins[i]) {
			pinMode(myButtonPins[i]-1, INPUT);
		}
	}
	for (int i = 0; i < 2; i++) {
		if (myAxisXPins[i]) {
			pinMode(myAxisXPins[i] - 1, INPUT);
		}
		if (myAxisXrPins[i]) {
			pinMode(myAxisXrPins[i] - 1, INPUT);
		}
		if (myAxisYPins[i]) {
			pinMode(myAxisYPins[i] - 1, INPUT);
		}
		if (myAxisYrPins[i]) {
			pinMode(myAxisYrPins[i] - 1, INPUT);
		}
	}
}

void GamepadMediator::setButtonPins(int size, byte params ...) {
	byte i = 0;
	while (i < size && i < 32) {
		//0 is null, and a negative pin is an odd concept (so no -1 to screw that up)
		myButtonPins[i] = params + 1;
		params++;
		i++;
	}
	//Reset the rest of the pins
	while (i < 32) {
		myButtonPins[i] = 0;
		i++;
	}
}
int32_t GamepadMediator::readButtons() {
	int32_t bits = 0x0;
	byte index = 0;
	while (index < 32) {
		byte pin = myButtonPins[index];
		//We go under the assumption that if we hit an unset button, there aren't anymore buttons.
		//An unset button is 0,
		//A set buttons pin is 1 less then whatever the set button value is
		if (pin) {
			bitWrite(bits, index, digitalRead(pin - 1));
		}
		else {
			index = 32;
		}
		index++;
	}?
	return bits;
}
String GamepadMediator::displayButtons() {
	int32_t bits = readButtons();
	String display = "";
	byte buttonsPressed = 0x0;
	for (int i = 0; i < 32; i++) {
		if (bitRead(bits, i)) {
			display += "Button";
			display += i;
			display += "\n";
			buttonsPressed++;
		}
	}
	display += "Buttons Pressed : ";
	display += buttonsPressed;
	display += "\n";
	//display += "\n";

	return display;
}

void GamepadMediator::setAxisXPin(byte pin) {
	myAxisXPins[0] = pin + 1;
	myAxisXPins[1] = 0;
	myAxisXButtons = false;
}
void GamepadMediator::setAxisXPin(byte pos, byte neg) {
	myAxisXPins[0] = pos + 1;
	myAxisXPins[1] = neg + 1;
	myAxisXButtons = true;
}
uint16_t GamepadMediator::readAxisX() {
	if (myAxisXButtons) {
		uint8_t
			pos = digitalRead(myAxisXPins[0]-1),
			neg = digitalRead(myAxisXPins[1]-1);
		if (neg > pos) {
			return 0;
		}
		else if (neg < pos) {
			return 64 * 64 - 1;
		}
		else return (64 * 32) - 1;
	}
	else {
		return analogRead(myAxisXPins[0] - 1) * 4;
	}
}
String GamepadMediator::displayAxisX() {

	uint16_t bits = readAxisX();
	String displayBits = String(bits);
	String display = "";

	display += "X : " + displayBits;
	display += "\n";
	//display += "\n";

	return display;
}


void GamepadMediator::setAxisYPin(byte pin) {
	myAxisYPins[0] = pin + 1;
	myAxisYPins[1] = 0;
	myAxisYButtons = false;
}
void GamepadMediator::setAxisYPin(byte pos, byte neg) {
	myAxisYPins[0] = pos + 1;
	myAxisYPins[1] = neg + 1;
	myAxisYButtons = true;
}
uint16_t GamepadMediator::readAxisY() {
	if (myAxisYButtons) {
		uint8_t
			pos = digitalRead(myAxisYPins[0]-1),
			neg = digitalRead(myAxisYPins[1]-1);
		if (neg > pos) {
			return 0;
		}
		else if (neg < pos) {
			return 64 * 64 - 1;
		}
		else return (64 * 32) - 1;
	}
	else {
		return analogRead(myAxisYPins[0] - 1) * 4;
	}
}
String GamepadMediator::displayAxisY() {

	uint16_t bits = readAxisY();
	String displayBits = String(bits);
	String display = "";

	display += "Y : " + displayBits;
	display += "\n";
	//display += "\n";

	return display;
}

void GamepadMediator::setAxisXrPin(byte pin) {
	myAxisXrPins[0] = pin + 1;
	myAxisXrPins[1] = 0;
	myAxisXrButtons = false;
}
void GamepadMediator::setAxisXrPin(byte pos, byte neg) {
	myAxisXrPins[0] = pos + 1;
	myAxisXrPins[1] = neg + 1;
	myAxisXrButtons = true;
}
uint16_t GamepadMediator::readAxisXr() {
	if (myAxisXrButtons) {
		uint8_t
			pos = digitalRead(myAxisXrPins[0] - 1),
			neg = digitalRead(myAxisXrPins[1] - 1);
		if (neg > pos) {
			return 0;
		}
		else if (neg < pos) {
			return 64 * 64 - 1;
		}
		else return (64 * 32) - 1;
	}
	else {
		return analogRead(myAxisXrPins[0] - 1) * 4;
	}
}
String GamepadMediator::displayAxisXr() {

	uint16_t bits = readAxisXr();
	String displayBits = String(bits);
	String display = "";

	display += "Rot X : " + displayBits;
	display += "\n";
	//display += "\n";

	return display;
}

void GamepadMediator::setAxisYrPin(byte pin) {
	myAxisYrPins[0] = pin + 1;
	myAxisYrPins[1] = 0;
	myAxisYrButtons = false;
}
void GamepadMediator::setAxisYrPin(byte pos, byte neg) {
	myAxisYrPins[0] = pos + 1;
	myAxisYrPins[1] = neg + 1;
	myAxisYrButtons = true;
}
uint16_t GamepadMediator::readAxisYr() {
	if (myAxisYrButtons) {
		uint8_t
			pos = digitalRead(myAxisYrPins[0] - 1),
			neg = digitalRead(myAxisYrPins[1] - 1);
		if (neg > pos) {
			return 0;
		}
		else if (neg < pos) {
			return 64 * 64 - 1;
		}
		else return (64 * 32) - 1;
	}
	else {
		return analogRead(myAxisYrPins[0] - 1) * 4;
	}
}
String GamepadMediator::displayAxisYr() {

	uint16_t bits = readAxisYr();
	String displayBits = String(bits);
	String display = "";

	display += "Rot Y : " + displayBits;
	display += "\n";
	//display += "\n";

	return display;
}

String GamepadMediator::display() {
	return
		displayButtons() +
		displayAxisX() +
		displayAxisY() + 
		displayAxisXr() +
		displayAxisYr();
}