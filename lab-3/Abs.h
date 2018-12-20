#include <cmath>
#include "UOP.h"

class Abs : public UOP
{
public:
    Abs() : UOP() {};
    Abs(Base* num) : UOP(num) {};
    
    double evaluate() {return std::abs( this->left->evaluate());};
    double abs() { return std::abs(this->left->evaluate()); };
    
};



