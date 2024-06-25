#include "WheelAssy.h"


//Set w2AtNotch to true if wheel2 is at notch
//If wheel 1 is at notch advance() wheel 2
//If w2AtNotch AND wheel 2 is NOT at notch advance() wheel 3
//advance() wheel 1
void advance() {

}

// Resets the wheels to their initial positions
void reset() {

}

//Set c1 to Wheel 1 rToL(c)
//Set c2 to Wheel 2 rToL(c1)
//Set c3 to Wheel 3 rToL(c2)
//Return c3
unsigned char rToL(unsigned char c) {
	return c;
}

//Set c3 to Wheel 3 lToR(c)
//Set c2 to Wheel 2 lToR(c3)
//Set c1 to Wheel 1 lToR(c2)
//Return c1
unsigned char lToR(unsigned char c) {
	return c;
}
