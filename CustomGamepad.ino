//#define USBCON

//#define USBCON
//#define USBSetup
#include <Arduino.h>

//#include "arduino.h"
//#include "HID.h"
#include "GamepadHidMediator.h"
//#include "HID-Settings.h"
//#include "HID-Project.h"
GamepadMediator mediator;

void setup()
{
  
  /* add setup code here */
	Serial.begin(9600);
  //Gamepad.begin();


  while(!Serial){
  ;
  }
  Serial.println("Started");
  
  mediator = {};
  mediator.setButtonPins(4, 2, 3, 4, 5);
  mediator.setAxisXPin(A0);
  mediator.setAxisYPin(A1);
  mediator.setAxisXrPin(A2);
  mediator.setAxisYrPin(A3);
  mediator.setup();
  Serial.println("Setup");
}

void loop()
{
  //Serial.println("Hit");
  Serial.println(mediator.display());
  delay(10);
  /* add main program code here */

}
