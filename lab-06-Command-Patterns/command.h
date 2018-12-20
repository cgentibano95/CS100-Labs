#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	//OpCommand Code Here
	public:
		OpCommand() : Command() {};
		OpCommand(double value) {
			root = new Op(value);
		};
};

class AddCommand : public Command {
	//AddCommand Code Here
public:
    AddCommand() : Command() {};
    AddCommand(Command* subtree, double value) {
        Base* newChild = new Op(value);
        root = new Add(subtree->get_root(), newChild);
    };
};


class SubCommand : public Command {
	//SubCommand Code Here
public:
    SubCommand() : Command() {};
    SubCommand(Command* subtree, double value) {
        Base* newChild = new Op(value);
        root = new Sub(subtree->get_root(), newChild);
    };
};

class MultCommand : public Command {
	public:
    MultCommand() : Command() {};
    MultCommand(Command* subtree, double value) {
        Base* newChild = new Op(value);
        root = new Mult(subtree->get_root(), newChild);
    };
};
class SqrCommand : public Command {
	//SqrCommand Code Here
	public:
    SqrCommand() : Command() {};
    SqrCommand(Command* subtree) {
        root = new Sqr(subtree->get_root());
    };
};
	
#endif //__COMMAND_CLASS__
