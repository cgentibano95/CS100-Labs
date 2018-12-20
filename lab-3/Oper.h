#include "base.h"
#ifndef OPER_H
#define OPER_H

class Oper : public Base { 

	protected:
		//Variables
		Base *left;
		Base *right;
	
		// Constructors
		Oper():Base(){};
   		Oper(Base* first, Base* second) :Base(), left(first), right(second) {};

	public:
		virtual double evaluate() {};
 };
#endif

