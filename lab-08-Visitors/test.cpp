#include <iostream>
#include <sstream>

#include "composite.h"
#include "visitor.h"

#include "gtest/gtest.h"

using namespace std;

TEST(PrintVisitor, PrintVisitorTest)
{       
	   
        Op* op = new Op(6);
	Op* op2 = new Op(7);
	Add* A = new Add(op,op2);
	Root* root = new Root(A);
	
	std::ostringstream oss;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());
       	
	PreorderIterator *iter = new PreorderIterator(root);
	PrintVisitor *v = new PrintVisitor();
	for (iter->first();!iter->is_done();iter->next())
	{
		iter->current()->accept(v);
	}
	v->execute();
	std::cout.rdbuf(p_cout_streambuf);
        EXPECT_EQ("+ 6 7 \n",oss.str());

}

TEST(PrintVisitor2, PrintVisitorTest)
{

        Op* op = new Op(2);
        Op* op2 = new Op(7);
        Add* A = new Add(op,op2);
	Mult* B = new Mult(A, op2);
	Sqr* C = new Sqr(B);
        Root* root = new Root(C);

        std::ostringstream oss;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());

        PreorderIterator *iter = new PreorderIterator(root);
        PrintVisitor *v = new PrintVisitor();
        for (iter->first();!iter->is_done();iter->next())
        {
                iter->current()->accept(v);
        }
        v->execute();
        std::cout.rdbuf(p_cout_streambuf);
        EXPECT_EQ("^ * + 2 7 7 \n",oss.str());

}

    
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
