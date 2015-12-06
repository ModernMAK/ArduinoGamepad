/*
class Button{
  Button(bool state){
    myPreviousState = state;
    myCurrentState = state;
  }
  Button(bool prevState, bool curState){
    myPreviousState = prevState;
    myCurrentState = curState;
  }
  private:
  bool
    myPreviousState,
    myCurrentState;

  public:
  bool getPreviousState(){
    return myPreviousState;  
  }
  bool getCurrentState(){
    return myCurrentState;  
  }

  void setState(bool state){
    myPreviousState = myCurrentState;
    myCurrentState = state;  
  }
  inline bool operator == (const Button& a, const Button& b){
      return (a.getPreviousState() == b.getPreviousState() && a.getCurrentState() == b.getCurrentState());
  }

  inline bool operator != (const Button& a, const Button& a){
      return !(a == b);
  }

};
*/
//DO REASEARCH ON HID for GMAEPAD
