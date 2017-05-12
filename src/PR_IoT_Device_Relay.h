#ifndef PR_IoT_Device_Relay_h
#define PR_IoT_Device_Relay_h

    #include <arduino.h>
    #include <PR_IoT.h>

class PR_IoT_Relay : public PR_IoT_DeviceClass {
        public:
            PR_IoT_Relay(String name) : PR_IoT_DeviceClass(name) { }
            
            void 	announce();
            void 	update();
            void 	inMsgCallback(); 
            void 	setupHW(uint8_t pin, bool onValue);
			
			bool	getState()			{	return _state; }
        protected:
		
			bool	_offValue;				// false means DEenergiesed is LOW
			uint8_t	_pin;
			bool	_state = 0;				// true mean "on". false mean "off"
		
		    void 	_relay() 	{	digitalWrite(_pin, _state ^ _offValue);	 } 
    };
	
#endif