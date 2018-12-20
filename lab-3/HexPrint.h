#ifndef HexPrint_h
#define HexPrint_h

#include "BasePrint.h"
#include <iostream>

class HexPrint : public BasePrint {
  public:
    HexPrint() : BasePrint() {};
    HexPrint(double value) : BasePrint(value) {}; 
    
    void print() { 
      std::cout << std::scientific << getVal();
      std::cout.unsetf(std::ios::floatfield); 
    };
};

#endif /* HexPrint_h */
