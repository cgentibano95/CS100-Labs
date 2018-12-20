#include <iostream>
#include "base.h"
#include "container.h"
#include "SelectionSort.h"
#include "Oper.h"
#include "Op.h"
#include "UOP.h"
#include "Mult.h"
#include "Add.h"
#include "Abs.h"
#include "Ceiling.h"
#include "Floor.h"
#include "Sub.h"
#include "Sqr.h"
#include "VectorContainer.h"
#include "ListContainer.h"
#include "BubbleSort.h"
#include "BaseFactory.h"
#include "DoubleFactory.h"
#include "HexFactory.h"
#include "BinaryFactory.h"

using namespace std;
int main(int argc, char** argv)
{
    BaseFactory* printfac;

    if (argc < 2) {
      std::cout << "Please input one flag (d, h, or b)" << endl;
      return 0;
    }  

    if (std::string(argv[1]) == "d") {
      cout << "Print Factory set to Double." << endl;
      printfac = new DoubleFactory();
    }

    else if (std::string(argv[1]) == "h") {
      cout << "Print Factory set to Hex." << endl;
      printfac = new HexFactory();
    }

    else if (std::string(argv[1]) == "b") {
      cout << "Print Factory set to Binary." << endl;
      printfac = new BinaryFactory();
    }
     else {
      std::cout << "Your input was " << argv[1] << ". Please input the flags (d, h, or b)" << endl;
      return 0;
    }


    Op* op7 = new Op(7);
    Op* op4 = new Op(4);
    
    Op* op3 = new Op(3);
    Op* op2 = new Op(2);
    
    Mult* A = new Mult(op7, op4);
    Add* B = new Add(op3, op4);
    Sub* C = new Sub(B, op2);
    Sqr* D = new Sqr(C);
    
    
    cout << "7 * 4 = " << A->evaluate() << "\n";
    cout << "3 + 4 = " << B->evaluate() << "\n";
    cout << "7 - 2 = " << C->evaluate() << "\n";
    cout << "Square of 5 = " <<D->evaluate() << "\n";

    VectorContainer* container = new VectorContainer();
    container->add_element(A);
    container->add_element(B);
    container->add_element(C);
    container->add_element(D);
    
    cout << "\nVector Container Before Sort: " << endl;
    container->set_print_factory(printfac);
    container->print();
    
    cout << "\nVector Container After Sort: " << endl;
    
    container->set_sort_function(new SelectionSort());
    container->sort();
    container->print();
    
    ListContainer* l_container= new ListContainer();
    l_container->add_element(D);
    l_container->add_element(C);
    l_container->add_element(B);
    l_container->add_element(A);
    
    cout << "\n\nList Container Before Sort: " << endl;
    l_container->set_print_factory(printfac);
    l_container->print();
    
    cout << "\nList Container After Sort: " << endl;
    
    l_container->set_sort_function(new BubbleSort());
    l_container->sort();
    l_container->print();

    cout << "\n\nTESTING DECORATORS\n\n";
    
    Op* abs_tester = new Op(-5.8);
    Abs* test_Abs = new Abs(abs_tester);
    cout << "Before abs(): ";
    cout << abs_tester->evaluate() << endl;
    cout << "Testing Abs\n";
    cout << "After abs(): \n";
    cout << test_Abs->abs() << endl << endl;
    
    Op* ceil_tester = new Op(3.45);
    Ceiling* test_ceil = new Ceiling(ceil_tester);
    cout << "Before ceil(): ";
    cout << ceil_tester->evaluate() << endl;
    cout << "Testing Ceiling\n";
    cout << "After ceil(): \n";
    cout << test_ceil->ceil() << endl << endl;
    
    Op* floor_tester = new Op(1.75);
    Floor* test_floor = new Floor(floor_tester);
    cout << "Before floor(): ";
    cout << floor_tester->evaluate() << endl;
    cout << "Testing Floor\n";
    cout << "After floor(): \n";
    cout << test_floor->floor() << endl << endl;
}

