#include "UOP.h"

class Sqr : public UOP
{
public:
    Sqr() : UOP(){};
    Sqr(Base* left) : UOP(left){};
    
    double evaluate(){return this->left->evaluate() * this->left->evaluate();};
        
};
