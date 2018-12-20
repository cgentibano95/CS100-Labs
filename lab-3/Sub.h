#include "Oper.h"

class Sub : public Oper
{
public:
    Sub(): Oper() {};
    Sub(Base* num1, Base* num2):Oper(num1,num2){};
    
    double evaluate() {return left->evaluate() - right->evaluate();};
};
