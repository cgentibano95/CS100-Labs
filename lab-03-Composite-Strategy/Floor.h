#include <cmath>
#include "UOP.h"

class Floor : public UOP {
public:
    Floor() : UOP() {};
    Floor(Base* num) : UOP(num) {};
    
    double evaluate() {return ::floor(this->left->evaluate());};
    int floor() { return ::floor(this->left->evaluate()); };
};


