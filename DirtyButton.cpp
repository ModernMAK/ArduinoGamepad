// 
// 
// 

#include "Arduino.h"
#include "DirtyButton.h"

DirtyButton::DirtyButton(int nPin) : DirtyValue::DirtyValue() {
	myPin = nPin;
	hasSetup = false;
}
void DirtyButton::setup() {
	pinMode(myPin, OUTPUT);
	hasSetup = true;
}
void DirtyButton::loop() {
	if (!hasSetup) {
		return;
	}	
	//Do Stuff
	setValue(readPin());

}
bool DirtyButton::readPin() {
	if (!hasSetup) {
		return false;
	}
	return digitalRead(myPin);
}