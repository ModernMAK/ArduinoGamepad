// 
// 
// 

#include "DirtyValue.h"

template<typename T>
DirtyValue<T>::DirtyValue() {
}
template<typename T>
DirtyValue<T>::DirtyValue(T initial) {
	myValue = initial;
}

template<typename T>
T DirtyValue<T>::getValue() {
	return myValue;
}

template<typename T>
void DirtyValue<T>::setValue(T nValue) {
	isDirty = isDirty || (nValue != myValue);
	hasSerialized = (myValue == nValue && hasSerialized);
	myValue = nValue;
}

template<typename T>
bool DirtyValue<T>::getDirty() {
	return 	isDirty;

}

template<typename T>
void DirtyValue<T>::setDirty(bool dirty) {
	isDirty = dirty;
}

template<typename T>
bool DirtyValue<T>::getSerialized() {
	return hasSerialized;
}

template<typename T>
void DirtyValue<T>::setSerialized(bool serialized) {
	hasSerialized = serialized;
}