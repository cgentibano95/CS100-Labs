#include "Oper.h"

#ifndef ADD_H
#define ADD_H
class Add : public Oper {
  public:
	// Constructors
	Add(): Oper() {};
	Add(Base* num1, Base* num2):Oper(num1,num2){};
	
	double evaluate() {return this->left->evaluate()  + this->right->evaluate();};
};

#endif
