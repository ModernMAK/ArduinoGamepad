// DirtyValue.h

#ifndef _DIRTYVALUE_h
#define _DIRTYVALUE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
template<typename T>
class DirtyValue {
	private:
		T 
			myValue;
		bool 
			isDirty,
			hasSerialized;

	public:
		DirtyValue();
		DirtyValue(T initial);

		T getValue();
		void setValue(T nValue);

		bool getDirty();
		void setDirty(bool dirty);

		bool getSerialized();
		void setSerialized(bool serialized);
};

#endif

