#include "Oper.h"

class Div : public Oper {
  public:
	Div() : Oper();
	Div(Base* num1, Base* num2):Oper(num1,num2){};
    
        double evaluate() { return this->left->evaluate() / this->right->evaluate();};	

};
