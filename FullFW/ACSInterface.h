#pragma once

#include <string>
#include <iostream>

class ACSInterface {

   // Constructor is private.
   ACSInterface() {}

public:
   // Meyer's Singleton pattern.
   static ACSInterface& Instance() {
      static ACSInterface aI;
      return              aI;
   }

   inline bool authorize() {
      cout << "Authorization OK\n\n";
      return true; 
   }

   ~ACSInterface() {}
};

