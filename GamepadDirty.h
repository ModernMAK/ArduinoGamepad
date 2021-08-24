// GamepadDirty.h

#ifndef _GAMEPADDIRTY_h
#define _GAMEPADDIRTY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "GamepadMediator.h"
class GamepadDirty : public GamepadMediator {
	
	private:
		uint32_t 
			myButtons;

		uint16_t
			myAxisX,
			myAxisY,
			myAxisRotX,
			myAxisRotY;

		uint8_t
			myAxisZ,
			myAxisRotZ,

			myDirPadA,
			myDirPadB;

		bool isDirty;
	public:
		GamepadDirty();
		void update();
		
		bool getDirty();
		void setDirty(bool dirty);

		String toString() override;
};

#endif

