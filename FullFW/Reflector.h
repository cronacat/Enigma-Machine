#if !defined (Reflector____INCL)
#define Reflector____INCL

#include <iostream>

class Reflector {
    enum { DEBUG  = false };
    const static unsigned char OFFSET = 32;
    const static unsigned char LAST = 126;

    const unsigned char getRefChar(const unsigned char ch) const;

    // Constructor is private.
    Reflector();

public:
    // Meyer's Singleton pattern.
    static Reflector &Instance() {
        static Reflector ref;
        return ref;
    }
    
    const unsigned char reflect(const unsigned char c) const;

    ~Reflector() {};
};

#endif