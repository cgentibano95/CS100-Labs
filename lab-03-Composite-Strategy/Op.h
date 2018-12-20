#include "base.h"

class Op : public Base
{
public:
    Base* operand;
    double data;
    
    // Constructors
    Op() : Base() {};
    Op(double x) : Base()
    {
        data = x;
    }
    virtual double evaluate() {return data;};
};
