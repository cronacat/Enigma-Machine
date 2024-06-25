#if !defined (NESEncryptortFacade____INCL)
#define NESEncryptortFacade____INCL

#include <iostream>

class NESEncryptortFacade {
    // Constructor is private.
    NESEncryptortFacade();

public:
    // Meyer's Singleton pattern.
    static NESEncryptortFacade& Instance() {
        static NESEncryptortFacade nef;
        return                     nef;
    }

    bool encrypt() { return false; }

    bool decrypt() { return false; }

    ~NESEncryptortFacade() {};
};

#endif
