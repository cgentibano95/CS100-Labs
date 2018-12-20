#ifndef DoubleFactory_h
#define DoubleFactory_h

#include "BaseFactory.h"
#include "DoublePrint.h"

class DoubleFactory : public BaseFactory
{
public:    
    BasePrint* generatePrint(double value){
        
        DoublePrint* doubleprinter = new DoublePrint(value);
        return doubleprinter;
    };
    
};

#endif /* DoubleFactory_h */
