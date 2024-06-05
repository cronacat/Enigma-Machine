#include <iostream>
#include "Wheel.h"

using namespace std;

void dumpV
(
   const short n, 
   Wheel* w, 
   short nE
)
{
   cout << "Left to Right" << endl;
   const short cP = w->getCurPos();

   cout << "cur: "   << cP << endl;

   for (short i = 0; i < n; ++i)
   {
      const short j = w->getLtoR(i);
      cout           << i << " -> ";
      cout             << j << endl;
   }

   cout << endl << 
             "Right to Left" << endl;

   for (short i = 0; i < n; ++i)
   {
       const short j = w->getRtoL(i);
       cout << i << " -> ";
       cout << j << endl;
   }
   cout << endl;
}

int main()
{
   short          cPos = 0;
   short        nEnts = 10;
   unsigned int seed = 787;

   //
   // Create a Wheel
   // object.
   //
   Wheel* w =
      new  Wheel(nEnts, seed, cPos);

   //
   // Test all wheel
   // positions.
   //
   for (short i = 0; i < nEnts; ++i)
   {

      //
      // If at the
      // notch, so
      // indicate.
      //
      if (w->atNotch())
         cout << "At notch " <<
         w->getCurPos() << endl;

      //
      // Dump values
      // and advance
      // the wheel.
      //
      dumpV   (nEnts, w, nEnts);
      w->advance();

   }

   delete w;

}





