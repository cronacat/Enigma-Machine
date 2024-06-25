#if !defined (WheelAssy____INCL)
#define WheelAssy____INCL

class WheelAssy {
    // Constructor is private.
    WheelAssy();
    
public:
    // Meyer's Singleton pattern.
    static WheelAssy& Instance() {
        static WheelAssy ref;
        return           ref;
    }

    void advance() {}

    void reset() {}

    unsigned char lToR(unsigned char c) { return c; }

    unsigned char rToL(unsigned char c) { return c; }

    ~WheelAssy() {};
};

#endif
