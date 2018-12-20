#ifndef VISITOR_H
#define VISITOR_H
#include <iostream>
#include <string>
#include "composite.h"

//#include "composite.h"

//#include "visitor.cpp"
using namespace std;

class Op;
class Visitor{
	public:
		Visitor(){};
	
		virtual void rootNode() = 0;
		virtual void sqrNode() = 0;
		virtual void multNode() = 0;
		virtual void subNode() = 0;
		virtual void addNode() = 0;
		virtual void opNode(Op* op) = 0;
		virtual void execute() = 0;
}; // end class visitor
class PrintVisitor : public Visitor {
    private:
        std::string output;

    public:
        PrintVisitor() : Visitor(){};

        void rootNode(); //For visiting a root node (do nothing)
        void sqrNode(); //For visiting a square node
        void multNode(); //For visiting a multiple node
        void subNode(); //For visiting a subtraction node
        void addNode(); //For visiting an add node
        void opNode(Op* op); //For visiting a leaf node

        void execute(); //Prints all visited nodes
};

#endif
