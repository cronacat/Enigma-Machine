#pragma once

#include <vector>
using namespace std;

class Wheel
{
   vector<short>        lToR;
   vector<short>        rToL;

   const short          nRec;
   short               notch;
   short              curPos;

   void loadLToR          ();
   void loadRToL          ();
   void convertToOffset   ();

public:

   Wheel
   (
      const short       nEnts,
      const unsigned int seed,
      const short        cPos
   );

   //
   // Returns true
   // if wheel is at
   // notch, false otherwise.
   //
   inline bool atNotch() const  
        { return (curPos == notch); }

   //
   // Set top of wheel
   // to the specified
   // value.
   //
   inline void resetCur(short cP) 
                     { curPos = cP; }

   //
   // Get translated 
   // value at index, i.
   //
   short getLtoR           (short i);
   short getRtoL           (short i);

   //
   // Get current top
   // of wheel position.
   //
   inline short getCurPos()
                   { return curPos; }

   //
   // Advance the
   // wheel one position.
   //
   inline void  advance()
   { 
      curPos = (++curPos >= nRec) ?
                          0 : curPos;
   }

   ~Wheel();
   
};
