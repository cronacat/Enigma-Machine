#include "wheel.h"
#include<random>


using namespace std;

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
};

void Wheel::loadLToR() {

    for (short i = 0; i < nRec; ++i) {
        lToR.push_back(i);
    }
    for (short i = 0; i < nRec; ++i) {

        short j = rand() % nRec;
        swap(lToR[i], lToR[j]);
    }

}

void Wheel::loadRToL() {
    const int rRange = nRec - 1;
    for (short i = 0; i < nRec; ++i) {
        rToL.push_back(0);
    }
    for (short i = 0; i < nRec; ++i) {
        rToL[lToR[i]] = i;
    }
}

void Wheel::convertToOffset() {
    for (short i = 0; i < nRec; ++i) {
        short offsett = lToR.at(i) - i;
        lToR[i] = offsett;
        offsett = rToL.at(i) - i;
        rToL[i] = offsett;
    }
}

short Wheel::getLtoR(short i) {
    const short index = (curPos + i) % nRec;
    short val = lToR.at(index);
    val += i;
    if (val < 0) val += nRec;
    else if (val >= nRec) val -= nRec;
    return val;

}

short Wheel::getRtoL(short i) {
    const short index = (curPos + i) % nRec;
    short val = rToL.at(index);
    val += i;
    if (val < 0) val += nRec;
    else if (val >= nRec) val -= nRec;
    return val;

}


Wheel::~Wheel() {
    lToR.clear();
    rToL.clear();
}
