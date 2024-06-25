#pragma once

class Plugboard {

    enum { DEBUG = false };

    // Constructor is private.
    Plugboard();

public:
    // Meyer's Singletonpattern.
    static Plugboard& Instance() {
        static Plugboard pB;
        return           pB;
    }

    unsigned char getPBC(unsigned char c);

    ~Plugboard();
   };




