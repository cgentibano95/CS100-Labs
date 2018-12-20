#ifndef BINARYPRINT_H
#define BINARYPRINT_H

#include "BasePrint.h"
#include <bitset>

class BinaryPrint : public BasePrint { 
  public:
   BinaryPrint() : BasePrint() {};
   BinaryPrint(double value) : BasePrint(value) {};

   void print() {
     std::cout << std::bitset<16>(this->getVal());

   }


}; 

#endif
