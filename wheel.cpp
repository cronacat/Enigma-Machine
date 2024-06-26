#include "wheel.h"
#include<cstdlib>


using namespace std;

//wheel constructor initializer for number of entries, seed, and current position
Wheel::Wheel(
    const short       nEnts,
    const unsigned int seed,
    const short        cPos) : nRec(nEnts), curPos(cPos)
{

    srand(seed);

    notch = rand() % nRec;


    loadLToR();
    loadRToL();
    convertToOffset();

}

// initializes the ltoR vector with random values from 0 to 9
void Wheel::loadLToR() {

    for (short i = 0; i < nRec; ++i) {
        lToR.push_back(i);
    }
    for (short i = 0; i < nRec; ++i) {

        short j = rand() % nRec;
        swap(lToR[i], lToR[j]);
    }

}

// initializes the rtoL vector with random values from 0 to 9
void Wheel::loadRToL() {

    for (short i = 0; i < nRec; ++i) {
        rToL.push_back(0);
    }
    for (short i = 0; i < nRec; ++i) {
        rToL[lToR[i]] = i;
    }
}


// gets absolute values in ltoR and rToL to offsett realtive to their indices
void Wheel::convertToOffset() {
    for (short i = 0; i < nRec; ++i) {
        short offsett = lToR.at(i) - i;
        lToR[i] = offsett;
        offsett = rToL.at(i) - i;
        rToL[i] = offsett;
    }
}


//computes the transformed value from ltoR using the current position and index
short Wheel::getLtoR(short i) {
    const short index = (curPos + i) % nRec;
    short val = lToR.at(index);
    val += i;
    if (val < 0) val += nRec;
    else if (val >= nRec) val -= nRec;
    return val;

}

//computes the transformed value from rtoL using the current position and index
short Wheel::getRtoL(short i) {
    const short index = (curPos + i) % nRec;
    short val = rToL.at(index);
    val += i;
    if (val < 0) val += nRec;
    else if (val >= nRec) val -= nRec;
    return val;

}


// clear the vector
Wheel::~Wheel() {
    lToR.clear();
    rToL.clear();
}
