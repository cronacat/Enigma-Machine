#include "UserInput.h"

#include <iostream>
#include <string>
#include <sstream>

UserInput::Action UserInput::getUserAction() { 

    static std::string input;
    
    std::cout << "Encrypt(E) or Decrypt(D) ?";
    std::cout << "\n(anything else exits): ";

    getline(std::cin, input);
    const char c = input[0];

    if ((c == 'D') || (c == 'd'))
        return DEC;
    if ((c == 'E') || (c == 'e'))
        return ENC;

    std::cout << "Program exiting\n";
    exit(0);
}
