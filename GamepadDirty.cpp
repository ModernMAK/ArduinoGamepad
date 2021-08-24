// 
// 
// 

#include "GamepadDirty.h"
GamepadDirty::GamepadDirty() {
	
}
void GamepadDirty::update() {
	uint32_t bit32;
	uint16_t bit16;
	uint8_t bit8;

	bit32 = readButtons();
	isDirty |= (bit32 != myButtons);
	myButtons = bit32;
	//
	bit16 = readAxisX();
	isDirty |= (bit16 != myAxisX);
	myAxisX = bit16;

	bit16 = readAxisY();
	isDirty |= (bit16 != myAxisY);
	myAxisY = bit16;

	bit16 = readAxisRotX();
	isDirty |= (bit16 != myAxisRotX);
	myAxisRotX = bit16;

	bit16 = readAxisRotY();
	isDirty |= (bit16 != myAxisRotY);
	myAxisRotY = bit16;
	//
	bit8 = readAxisZ();
	isDirty |= (bit8 != myAxisZ);
	myAxisZ = bit8;

	bit8 = readAxisRotZ();
	isDirty |= (bit8 != myAxisRotZ);
	myAxisRotZ = bit8;
	//
	bit8 = readPadA();
	isDirty |= (bit8 != myDirPadA);
	myDirPadA = bit8;

	bit8 = readPadA();
	isDirty |= (bit8 != myDirPadB);
	myDirPadB = bit8;
}

bool GamepadDirty::getDirty() {
	return isDirty;
}
void GamepadDirty::setDirty(bool dirty) {
	isDirty = dirty;
}

String GamepadDirty::toString() {
	String output = "";

	output += GamepadButtons::toString(myButtons) + "\n";
	output += "X " + GamepadAxis::toString(myAxisX) + "\n";
	output += "Y " + GamepadAxis::toString(myAxisY) + "\n";
	output += "Z " + GamepadAxis::toString(myAxisZ) + "\n";
	output += "Rot X " + GamepadAxis::toString(myAxisRotX) + "\n";
	output += "Rot Y " + GamepadAxis::toString(myAxisRotY) + "\n";
	output += "Rot Z " + GamepadAxis::toString(myAxisRotZ) + "\n";
	output += "Left Pad " + GamepadDirectionalPad::toString(myDirPadA) + "\n";
	output += "Right Pad " + GamepadDirectionalPad::toString(myDirPadB) + "\n";

	return output;
}

