#include "DirtyValue.cpp"

/*
 * 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
*/


const int 
  A_BUTTON_PIN = 2,
  B_BUTTON_PIN = 3,
  X_BUTTON_PIN = 4,
  Y_BUTTON_PIN = 5;
  
DirtyValue<bool> 
  aButton = NULL,
  bButton = NULL,
  xButton = NULL,
  yButton = NULL;


void setup() {
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  aButton = {false};
  bButton = {false};
  xButton = {false};
  yButton = {false};
  pinMode(A_BUTTON_PIN,INPUT);
  pinMode(B_BUTTON_PIN,INPUT);
  pinMode(X_BUTTON_PIN,INPUT);
  pinMode(Y_BUTTON_PIN,INPUT);
}

void loop() {
    updateState();
    serializeState();
    delay(10);
}

void serialEvent(){
  if(Serial.available()){
    deserializeState();
  }
}

void updateState(){
  aButton.setValue((digitalRead(A_BUTTON_PIN) == 0 ? false : true));
  bButton.setValue((digitalRead(B_BUTTON_PIN) == 0 ? false : true));  
  xButton.setValue((digitalRead(X_BUTTON_PIN) == 0 ? false : true));  
  yButton.setValue((digitalRead(Y_BUTTON_PIN) == 0 ? false : true));  
}
void serializeState(){
  int dirtyBits = 0;
  bool wasBitSet = false;
  if(aButton.shouldSerialize()){
    bitSet(dirtyBits,0);
    wasBitSet = true;
  }
  if(bButton.shouldSerialize()){
    bitSet(dirtyBits,1);
    wasBitSet = true;
  }
  if(xButton.shouldSerialize()){
    bitSet(dirtyBits,2);
    wasBitSet = true;
  }
  if(yButton.shouldSerialize()){
    bitSet(dirtyBits,3);
    wasBitSet = true;
  }
  if(wasBitSet){
    Serial.println("Dirty");
    Serial.println(dirtyBits);
    if(aButton.shouldSerialize()){
      Serial.println("A");
      Serial.println(aButton.getValue()); 
      aButton.setSerialized();
    }
    if(bButton.shouldSerialize()){
      Serial.println("B");
      Serial.println(bButton.getValue()); 
      bButton.setSerialized();
    }
    if(xButton.shouldSerialize()){
      Serial.println("X");
      Serial.println(xButton.getValue()); 
      xButton.setSerialized();
    }
    if(yButton.shouldSerialize()){
      Serial.println("Y");
      Serial.println(yButton.getValue()); 
      yButton.setSerialized();
    }
    Serial.println("");
  }
  
  /*
  Serial.print(buttonState.getDirty());  
  Serial.print(buttonState.getValue()); 
  Serial.print("\n");
  */

}
void deserializeState(){
  /*
  bool val = (bool)Serial.read();
  if(val){
    buttonState.cleanDirty();  
  }
  */
}

