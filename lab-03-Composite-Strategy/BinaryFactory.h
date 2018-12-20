#ifndef BINARYFACTORY_H
#define BINARYFACTORY_H

#include "BaseFactory.h"
#include "BinaryPrint.h"

class BinaryFactory : public  BaseFactory {
  public:
    BinaryFactory() : BaseFactory() {};
    BasePrint* generatePrint(double value) {
      BinaryPrint* binaryPrinter = new BinaryPrint(value);
      return binaryPrinter;
    };
};

#endif
