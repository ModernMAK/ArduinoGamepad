#include "Pad4Buttons.h"
#include "Pad8Buttons.h"
#include <DirtyValue.h>
#include <DirtyButton.h>

const int
	A_BUTTON_PIN = 2,
	B_BUTTON_PIN = 3,
	X_BUTTON_PIN = 4,
	Y_BUTTON_PIN = 5,
	DU_BUTTON_PIN = 6,
	DL_BUTTON_PIN = 7,
	DR_BUTTON_PIN = 8,
	DD_BUTTON_PIN = 9;
/*
void loopDelay100();
void loopDelay500();

int
	buttonPins[4] = { A_BUTTON_PIN,B_BUTTON_PIN,X_BUTTON_PIN,Y_BUTTON_PIN };

DirtyButton
	buttons[4] = { buttonPins[0],buttonPins[1],buttonPins[2],buttonPins[3] };
*/

Pad4Buttons buttons = NULL;//{ A_BUTTON_PIN,B_BUTTON_PIN, X_BUTTON_PIN, Y_BUTTON_PIN,  DU_BUTTON_PIN, DL_BUTTON_PIN, DR_BUTTON_PIN, DD_BUTTON_PIN };
void setup(){
	buttons = { A_BUTTON_PIN, B_BUTTON_PIN,X_BUTTON_PIN,Y_BUTTON_PIN };
	buttons.setup();
	/*
	for (int i = 0; i < 4; i++) {
		//buttons[i] = { buttonPins[i] };
		buttons[i].setup();
	}
	*/
}
void loopDelay100();
//void loopDelay200();
//void loopDelay300();
//void loopDelay400();
void loopDelay500();
//void loopDelay600();
//void loopDelay700();
//void loopDelay800();
//void loopDelay900();
void loopDelay1000();

void serializeButtons(bool readable = false);
int i = 0;
void loop() {
	loopDelay100();

	if (i % 5 == 0) {
		loopDelay500();
	}
	if (i % 10 == 0) {
		loopDelay1000();
	}

	delay(100);
	i++;
	i %= 10;
}
void loopDelay100() {
	buttons.loop();
	if (buttons.shouldSerialize(false)) {
		serializeButtons(true);
	}
}
void loopDelay500() {
	//	buttons.loop();
}
void loopDelay1000() {
	if (buttons.shouldSerialize(true)) {
		serializeButtons(true);
	}
}
void serializeButtons(bool readable) {
	Serial.begin(9600);
	if (readable) {
		Serial.println();
		Serial.print(buttons.getDirty());
		Serial.print(buttons.getValue());
		Serial.println();

		byte buttonsBits = buttons.getValue();
		if (bitRead(buttonsBits, 0)) {
			Serial.print("A");
		}
		if (bitRead(buttonsBits, 1)) {
			Serial.print("B");
		}
		if (bitRead(buttonsBits, 2)) {
			Serial.print("X");
		}
		if (bitRead(buttonsBits, 3)) {
			Serial.print("Y");
		}
		if (bitRead(buttonsBits, 4)) {
			Serial.print("U");
		}
		if (bitRead(buttonsBits, 5)) {
			Serial.print("R");
		}
		if (bitRead(buttonsBits, 6)) {
			Serial.print("D");
		}
		if (bitRead(buttonsBits, 7)) {
			Serial.print("L");
		}
		Serial.println();

	}
	else {
		Serial.write(buttons.getDirty());
		Serial.write(buttons.getValue());
	}
	buttons.setSerialized(true);
	Serial.end();
}

/*
for (int i = 1; i <= 10; i++) {
	loopDelay100();
	if (i % 5) {
		loopDelay500();
	}
delay(100);
}*/
/*
void loopDelay100() {
	for (int i = 0; i < 4; i++) {
		buttons[i].loop();

	}
}
void loopDelay500() {
}
*/

//#include "DirtyButton.h"
//#include "DirtyValue.cpp"
//#include <SoftwareSerial.h>
//
//
//void serialEvent();
//void updateState();
//void updateLcd();
//void serializeState();
//void serializeState(bool);
//void deserializeSerial();
//void deserializeState();
//void flushBuffer();
//
//const int 
//  A_BUTTON_PIN = 2,
//  B_BUTTON_PIN = 3,
//  X_BUTTON_PIN = 4,
//  Y_BUTTON_PIN = 5,
//  LCD_PIN = 6;
//  
//DirtyValue<bool>
//  buttons[4];
//int 
//  buttonPins[4] = {A_BUTTON_PIN,B_BUTTON_PIN,X_BUTTON_PIN,Y_BUTTON_PIN};
// /*
//SoftwareSerial 
//  lcdScreen = SoftwareSerial(255,LCD_PIN);
//*/
//void setup() {
//  Serial.begin(9600);
//  while(!Serial){
//    ;
//  }
//  //lcdScreen.begin(9600);
//
//  for(int i = 0; i < 4; i ++){
//    buttons[i] = {false};
//    pinMode(buttonPins[i],INPUT);
//  }
////  pinMode(LCD_PIN,OUTPUT);  
////  lcdScreen.write(17);
//}
//
//int loopCounter = 0;
//void loop() {
//      updateState();
//      serializeState(loopCounter == 9);
////    updateLcd();
//      delay(10);
//      loopCounter++;
//      loopCounter %= 10;
//    
//}
//
//void serialEvent(){
//  if(Serial.available()){
//    deserializeSerial();
//  }
//}
//void updateState(){
//  for(int i = 0; i < 4; i++){
//    buttons[i].setValue(digitalRead(buttonPins[i]));  
//  }
//}
//
//void updateLcd(){
//}
//const byte DESERIALIZE_CODE = 0;
//void serializeState(){
//  serializeState(false);  
//}
//void serializeState(bool ignoreSerialize){
//  byte 
//    dirtyBits,
//    newBits,
//    counter = 0;
//  
//  for(int i = 0; i < 4; i++){
//    if(buttons[i].shouldSerialize(ignoreSerialize)){
//      bitSet(dirtyBits,i);        
//      bitWrite(newBits,counter,buttons[i].getValue());
//      counter++;
//    }
//  }
//
//  if(counter > 0){
//    Serial.write(DESERIALIZE_CODE);
//    Serial.write(dirtyBits);
//    Serial.write(newBits);
//  }
//}
//void deserializeSerial(){
//    byte actionCode = Serial.read();
//    switch(actionCode){
//      case DESERIALIZE_CODE:
//        deserializeState();
//      default:
//        flushBuffer();
//    }
//}
//void deserializeState(){
//  byte 
//    dirtyBits = Serial.read(),
//    serializedBits = Serial.read(),
//    counter = 0;
//
//    for(int i = 0; i < 4; i++){
//      if(bitRead(dirtyBits,i)){
//        if(bitRead(serializedBits,counter) == buttons[i].getValue()){
//          buttons[i].cleanDirty();
//        }
//        counter ++;
//      }  
//    }
//}
//void flushBuffer(){
//  while(Serial.available())
//    Serial.read();  
//}
