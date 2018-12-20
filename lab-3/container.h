#ifndef CONTAINER_H
#define CONTAINER_H
#include "BaseFactory.h"

class Sort;
class Container;


class Sort
{
public:
    /* Constructors */
    Sort(){};

    /* Pure Virtual Functions */
    virtual void sort(Container* container) = 0;
};

class Container {
    protected:
        Sort* sort_function;
        BaseFactory* print_factory;
    public:
	    /* Constructors */
        Container() : sort_function(NULL){};
        Container(Sort* function) : sort_function(function) {};
        Container(BaseFactory* factory) : print_factory(factory) {};
        /* Non Virtual Functions */
        void set_sort_function(Sort* sort_function) {
          this->sort_function = sort_function; 
        }; // set the type of sorting algorithm

	void set_print_factory(BaseFactory* print_factory) {
	  this->print_factory = print_factory;
	};
        /* Pure Virtual Functions */
	    // push the top pointer of the tree into container
        virtual void add_element(Base* element) = 0;
        // iterate through trees and output values
        virtual void print() = 0;
        // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
        virtual void sort() = 0;

        /* Essentially the only functions needed to sort */
        //switch tree locations
        virtual void swap(int i, int j) = 0;
        // get top ptr of tree at index i
        virtual Base* at(int i) = 0;
        // return container size
        virtual int size() = 0;
};

#endif /* Container_h */
