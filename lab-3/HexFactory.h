#include "BaseFactory.h"
#include "HexPrint.h"	

class HexFactory : public BaseFactory {
  public:
    HexFactory() : BaseFactory() {};
    BasePrint* generatePrint(double value) {
      HexPrint* hexPrinter =  new HexPrint(value);
      return hexPrinter;
    };
};
