#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class BlackFileInterface {
    const std::string  BlackInFN;
    const std::string BlackOutFN;
    
    bool    fileOpen;
    bool  fileOFRead;    // What's this for?

    fstream MyInFile;

    // Constructor is private.
    BlackFileInterface() : BlackInFN("MyOutFile.dat"), BlackOutFN("MyOutFile.dat"), fileOpen(false) {}

public:
    // Meyer's Singleton pattern.
    static BlackFileInterface& Instance() {
        static BlackFileInterface fB;
        return                    fB;
    }

    // Implement the following operations for both the Black and black files.
    // All return true if OK, otherwise false.
    bool openForRead();
    unsigned char getNextChar();
    bool openForWrite();
    bool putNextChar (unsigned char c);
    bool eof();
    bool close();

    ~BlackFileInterface() {}
};


