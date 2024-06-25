#pragma once
#include <string>
#include <iostream>

class AASInterface {
    // Constructor is private.
    AASInterface() {}

public:
    // Meyer's Singleton pattern.
    static AASInterface& Instance() {
        static AASInterface aI;
        return              aI;
    }

    inline void sendEncryptOK() { std::cout << "Encrypt OK (AAS)\n\n"; }

    inline void sendDecryptOK() { std::cout << "Decrypt OK (AAS)\n\n"; }

    ~AASInterface() {}
};

