#include <iostream>
#include <sstream>

#include "iterator.h"

#include "gtest/gtest.h"

using namespace std;

TEST(PreOrder, PreOrderIterTest)
{       
	   
        Op* op = new Op(6);
	Op* op2 = new Op(7);
	Add* A = new Add(op,op2);
	Root* root = new Root(A);
	
	std::ostringstream oss;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());
       	
	PreorderIterator *iter = new PreorderIterator(root);
	for (iter->first();!iter->is_done();iter->next())
	{
		iter->current()->print();
		cout << endl;
	}	
	std::cout.rdbuf(p_cout_streambuf);
        EXPECT_EQ("+\n6\n7\n",oss.str());

}

TEST(PreOrderSub, PreiterTest)
{
	Op* op = new Op(3);
	Op* op2 = new Op(2);

	Sub* A = new Sub(op, op2);
	Mult* B = new Mult(A, op2);
	Sqr* C = new Sqr(B);
	Root* root = new Root(C);

	        std::ostringstream oss;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());

	PreorderIterator* iter = new PreorderIterator(root);
        for (iter->first();!iter->is_done();iter->next())
        { 
                iter->current()->print(); 
                cout << endl;
        }    
        std::cout.rdbuf(p_cout_streambuf);
        EXPECT_EQ("^2\n*\n-\n3\n2\n2\n",oss.str());
}

TEST(UnaryIter, OperTest)
{

	Op* op = new Op(3);
	Op* op2 = new Op(1);
	
	Add* A = new Add(op, op2);
	Sub* B = new Sub(A, op);
	Sqr* C = new Sqr(B);
	Root* root = new Root(C);
	 std::ostringstream oss;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());

	UnaryIterator* iter = new UnaryIterator(root);
	        for (iter->first();!iter->is_done();iter->next())
        { 
                iter->current()->print(); 
                cout << endl;
        }    
        std::cout.rdbuf(p_cout_streambuf);
	EXPECT_EQ("^2\n", oss.str());
}

TEST(OperIter, OperTest)
{

        Op* op = new Op(3);
        Op* op2 = new Op(1);
        
        Add* A = new Add(op, op2);
        Sub* B = new Sub(A, op);
        Root* root = new Root(B);
         std::ostringstream oss;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());

        OperatorIterator* iter = new OperatorIterator(root);
                for (iter->first();!iter->is_done();iter->next())
        {
                iter->current()->print(); 
                cout << endl;
        }     
        std::cout.rdbuf(p_cout_streambuf);
        EXPECT_EQ("-\n", oss.str());
}

TEST(NullIter, Nulltest)
{
        Op* op = new Op(3);
        Op* op2 = new Op(1);
        
        Add* A = new Add(op, op2);
        Sub* B = new Sub(A, op);
        Root* root = new Root(B);
         std::ostringstream oss;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());

        NullIterator* iter = new NullIterator(root);
                for (iter->first();!iter->is_done();iter->next())
        {
                iter->current()->print(); 
                cout << endl;
        }     
        std::cout.rdbuf(p_cout_streambuf);
        EXPECT_EQ("", oss.str());
}    
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
