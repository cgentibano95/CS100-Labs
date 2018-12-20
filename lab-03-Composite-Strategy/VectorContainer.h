
#include "container.h"
#include <vector>

class VectorContainer : public Container {
protected:
    Base* value;
    std::vector<Base*> expressions;
    
public:
    VectorContainer() : Container() {};
    
    void add_element(Base* element) { expressions.push_back(element); };
    void print() {
        for (int i = 0; i < expressions.size(); i++) {
            print_factory->generatePrint(expressions.at(i)->evaluate())->print();
            std::cout << " ";
        }
    }
    void sort() {sort_function->sort(this);}
    
    void swap(int i, int j)
    {
        Base* temp = expressions.at(i);
        expressions.at(i) = expressions.at(j);
        expressions.at(j) = temp;
    }
    Base* at(int i) { return expressions.at(i); };
    
    int size() { return  static_cast<int>(expressions.size()); };
    
}; 

