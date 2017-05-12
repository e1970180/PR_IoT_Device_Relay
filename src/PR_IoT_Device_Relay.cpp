#include "PR_IoT_Device_Relay.h"

    #include <arduino.h>    

	void PR_IoT_Relay::setupHW(uint8_t pin, bool onValue) {
		_pin = pin;
		_offValue = !onValue;
		pinMode(_pin, OUTPUT);
		_relay();
	}             
	void PR_IoT_Relay::announce() {
		postMsg("relay", "HELLO"); 
	}
	void PR_IoT_Relay::update() {
		String	s;
		if (_state)	s = "ON"; else s = "OFF";
		postMsg ("relay", s );
	}
	void PR_IoT_Relay::inMsgCallback() {

		PR_DBGTLN("r1: Msg got")
		PR_DBGVLN(inMsg.payload)
		
		if (inMsg.payload == "ON") 		 _state = true; 
		else if (inMsg.payload == "OFF") _state = false; 
		
		_relay();
	}
	
