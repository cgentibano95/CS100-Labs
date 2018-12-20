#ifndef UOP_H
#define UOP_H
#include "base.h"

class UOP : public Base
{
	protected:
	Base *left;

	UOP():Base(){};
    	UOP(Base* first) :Base(), left(first) {};

	public:
    	virtual double evaluate() = 0;
};
#endif

