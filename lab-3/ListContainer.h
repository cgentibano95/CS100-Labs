#include "container.h"
#include <list>

using namespace std;

class ListContainer : public Container
{
protected:
   list <Base*> list_container;
    
public:

    ListContainer() : Container(){};
   
    void add_element(Base* element)
    {
        list_container.push_back(element);
    };
    
    void print()
    {
        list<Base*>::iterator iter;
        for (iter = list_container.begin(); iter != list_container.end(); ++iter)
        {
            print_factory->generatePrint((*iter)->evaluate())->print();
            std::cout << " ";
        }
    };
void sort() {sort_function->sort(this);}
    
    Base* at(int i)
    {
        list<Base*> :: iterator iter = list_container.begin();
        for (int j=0; j<i; ++j)
        {
            ++iter;
        }
        return *iter;
    }
    
    void swap(int i, int j)
    {
        list<Base*> :: iterator iter1 = list_container.begin();
        list<Base*> :: iterator iter2 = list_container.begin();
        
        for (int k=0; k<i; ++k)
        {
            ++iter1;
        }
    	// used so iter1 and iter2 can go to values provided
    	for (int z=0; z<j; ++z)
        {
            ++iter2;
        }
	Base* temp = *iter2;
        *iter2 = *iter1;
        *iter1 = temp;
    }

    int size() { return  static_cast<int>(list_container.size()); };
};
