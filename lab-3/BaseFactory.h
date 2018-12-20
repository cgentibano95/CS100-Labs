#ifndef BaseFactory_h
#define BaseFactory_h

#include "BasePrint.h"

class BaseFactory {
public:
    /* Constructor */
    BaseFactory(){};
    
    /* Pure Virtual Generate Function */
    virtual  BasePrint* generatePrint(double value) = 0;
};

#endif /* BaseFactory_h */
