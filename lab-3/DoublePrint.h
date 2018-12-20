#ifndef DOUBLEPRINT_H
#define DOUBLEPRINT_H


#include "BasePrint.h"

class DoublePrint : public BasePrint
{
public:
    DoublePrint() : BasePrint(){};
    DoublePrint(double x) : BasePrint(x)
    {};
    
    void print() { std::cout << getVal();}
};

#endif
