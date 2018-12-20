#include "Oper.h"

class Mult : public Oper {
public:
    Mult() : Oper(){};
    Mult(Base* num1, Base* num2) : Oper(num1, num2) {};
    
    double evaluate() { return this->left->evaluate() * this->right->evaluate();};
};
