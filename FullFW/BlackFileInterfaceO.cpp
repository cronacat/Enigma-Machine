#include "BlackFileInterface.h"

using namespace std;

bool BlackFileInterface::openForRead()
{
   if (fileOpen)       return false;
   infile.open(BlackInFN, ios::in);
   fileOpen = infile.is_open();
   fileOFRead = fileOpen;
   return                  fileOpen;
}

bool BlackFileInterface::openForWrite()
{
   if (fileOpen)    return false;
   outfile.open
   (BlackOutFN, ios::out |
      ios::trunc);
   fileOpen = outfile.is_open();
   fileOFRead = false;
   return               fileOpen;
}

bool BlackFileInterface::eof()
{
   if (fileOpen == false)
      return true;
   const bool b =
      fileOFRead && infile.eof();
   return b;
}

bool BlackFileInterface::close()
{
   if (fileOpen == false)
      return true;
   bool result;
   if (fileOFRead)
   {
      infile.close();
      result =
         infile.good();
   }
   else
   {
      outfile.close();
      result =
         outfile.good();
   }

   fileOpen = (result == false);

   return result;
}

unsigned char BlackFileInterface::getNextChar()
{
   if (fileOpen && fileOFRead)
   {
      if (eof() == false)
      {
         unsigned char c;
         infile >> c;
         return c;
      }
   }
   return 0;
}

bool BlackFileInterface::putNextChar
(unsigned char c)
{
   if (fileOpen && (fileOFRead == false))
      outfile << c;

   const bool b = outfile.good();

   return b;
}