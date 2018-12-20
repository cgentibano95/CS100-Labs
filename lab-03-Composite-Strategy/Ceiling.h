#include <cmath>
#include "UOP.h"

class Ceiling : public UOP {
public:
    Ceiling(): UOP(){};
    Ceiling(Base* num) : UOP(num) {};
    
    double evaluate() {return ::ceil(this->left->evaluate());};
    int ceil() { return ::ceil(this->left->evaluate()); };
    
};



