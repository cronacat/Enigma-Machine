#include "Wheel.h"
#include <random>


void Wheel::loadLToR()
{
   const static short 
	              rRange = nRec - 1;

   //
   // Initialize
   //
   for (short i = 0; i<nRec; ++i) 
	              lToR.push_back(i); 

   for (short i = 0; i<nRec; ++i)
   {
	  //
	  // Get a random
	  // number in range
	  // and exchange.
	  //
	  const short j = rand() % nRec;
	  const short iSav =    lToR[i];
	  const short jSav =    lToR[j];
	  lToR[i]          =       jSav;
	  lToR[j]          =       iSav;
   }

}

void Wheel::loadRToL()
{
   const short rRange = nRec - 1;

   //
   // Initialize
   //
   for (short i = 0; i < nRec; ++i)
                  rToL.push_back(0);

   for (short i = 0; i < nRec; ++i)
   {
      const short jSav =   lToR[i];
      rToL[jSav]       =         i;
   }

}

void Wheel::convertToOffset()
{
   for (short i = 0; i < nRec; ++i)
   {
      short offset =   lToR[i] - i;
      lToR[i]      =        offset;
	  offset       =   rToL[i] - i;
	  rToL[i]      =        offset;
   }
}

short Wheel::getLtoR(short i)
{
	const short index =
               (curPos + i) % nRec;
	short val    = lToR[index] + i;

	if (val < 0)       val += nRec;
	else if (val >= nRec)
		               val -= nRec;
	return                     val;
}

short Wheel::getRtoL(short i)
{
	const short index =
		       (curPos + i) % nRec;
	short val    = rToL[index] + i;

	if (val < 0)       val += nRec;
	else if (val >= nRec)
		               val -= nRec;
	return                     val;
}

Wheel::Wheel
(
   const short               nEnts,
   const unsigned int         seed,
   const short                cPos
) : nRec(nEnts), curPos(cPos) 
{
   //
   // Seed the random
   // number generator,
   // set the notch position,
   // generate the wiring
   // vectors and convert to
   // offsets.
   //
   srand                   (seed);
   notch      =     rand() % nRec;
   loadLToR                    ();
   loadRToL                    ();
   convertToOffset             ();
}

Wheel::~Wheel()
{
   lToR.clear();
   rToL.clear();
}