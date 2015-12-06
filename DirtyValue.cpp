
template<typename T>
class  DirtyValue{
  public:
    DirtyValue(T initialValue){
      myValue = initialValue;
      isDirty = true;
      hasSerialized = false; 
    }
  
  private:
    T 
      myValue;
    bool 
      isDirty,
      hasSerialized;

  public:
    void setValue(T value){
      isDirty = isDirty || (myValue != value);
      hasSerialized = (myValue == value && hasSerialized);
      myValue = value;  
    }
    T getValue(){
      return myValue;  
    }
    bool getDirty(){
      return isDirty;
    }
    void cleanDirty(){
      isDirty = false;
      hasSerialized = false;
    }
    bool getSerialized(){
      return hasSerialized;
    }
    void setSerialized(){
      hasSerialized = true;
    }
    bool shouldSerialize(){
      return !getSerialized() && getDirty();
    }
};
