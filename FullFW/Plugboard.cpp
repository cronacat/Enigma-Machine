#include "Plugboard.h"

Plugboard::Plugboard() {
}

Plugboard::~Plugboard() {
}

unsigned char Plugboard::getPBC(unsigned char c) {

   // If 3 is connected to 1 then
   //	if (c==3) return 1;
   //	if (c==1) return 3;
   //   etc.
   return c;

}