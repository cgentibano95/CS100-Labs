#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "Sqr.h"
#include "Abs.h"
#include "Add.h"
#include "Sub.h"
#include "Mult.h"
#include "Op.h"
#include "menu.h"

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
	public:
		OpCommand() : Command() {};
		OpCommand(double value) {
			root = new Op(value)
		};
};

class AddCommand : public Command {
	//AddCommand Code Here
	public:
		AddCommand() : Command() {};
		AddCommand(Base* subtree, double value) {
			Base* newChild = new Op(value);
			root = new Add(subtree, newchild);
		};
};

class SubCommand : public Command {
	//SubCommand Code Here
	public:
		SubCommand() : Command() {};
		SubCommand(Base* subtree, double value) {
			Base* newChild = new Op(value);
			root = new Sub(subtree, newChild);
		};
};

class MultCommand : public Command {
	//MultCommand Code Here
	public:
		MultCommand() : Command() {};
		MultCommand(Base* subtree, double value) {
			Base* newChild = new Op(value);
			root = new Mult(subtree, newChild);
		};
};

class SqrCommand : public Command {
	//SqrCommand Code Here
	public:
		SqrCommand() : Command() {};
		SqrCommand(Base* subtree) {
			root = new Sqr(subtree);
		};
};

#endif //__COMMAND_CLASS__:
