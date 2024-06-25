#include "RedFileInterface.h"

using namespace std;

bool RedFileInterface::openForRead()
{
   if (fileOpen)       return false;
   infile.open   (RedInFN,ios::in);
   fileOpen   =    infile.is_open();
   fileOFRead =            fileOpen;
   return                  fileOpen;
}

bool RedFileInterface::openForWrite()
{
   if (fileOpen)    return false;
   outfile.open
      (RedOutFN, ios::out | 
       ios::trunc);
   fileOpen  = outfile.is_open();
   fileOFRead =            false;
   return               fileOpen;
}

bool RedFileInterface::eof()
{
   if (fileOpen == false)
                      return true;
   const bool b = 
       fileOFRead && infile.eof();
   return b;
}

bool RedFileInterface::close()
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

unsigned char RedFileInterface::getNextChar()
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

bool RedFileInterface::putNextChar
   (unsigned char c)
{
   if (fileOpen && (fileOFRead == false))
      outfile << c;
 
   const bool b = outfile.good();

   return b;
}