#include <iostream>
#include <sstream>
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
#include "DoublePrint.h"
#include "HexPrint.h"
#include "BinaryPrint.h"
#include "BinaryFactory.h"
#include "HexFactory.h"
#include "DoubleFactory.h"

#include "gtest/gtest.h"

int GLOBAL_ARGC;
char** GLOBAL_ARGV;

TEST(AddTest, DoublesAdding) 
{
	Op* op4 = new Op(4.0);
        Op* op3 = new Op(3.0);

        Add* B = new Add(op3, op4); 
         
   	EXPECT_EQ(7.0, B->evaluate());
}

TEST(AddTwiceTest, DoublesAdding)
{
        Op* op4 = new Op(4.0);
        Op* op3 = new Op(3.0);

        Add* B = new Add(op3, op4);
	Add* C = new Add(B, op3);
        EXPECT_EQ(10.0, C->evaluate());
}

TEST(SubTest, DoublesSubtracting)
{
        Op* op4 = new Op(4.0);
        Op* op3 = new Op(3.0);

        Sub* C = new Sub(op4,op3);

        EXPECT_EQ(1.0, C->evaluate());
}
TEST(SubTwiceTest, DoublesSubtracting)
{
        Op* op8 = new Op(8.0);
        Op* op3 = new Op(3.0);

        Sub* C = new Sub(op8,op3);
	Sub* D = new Sub(C, op3);
        EXPECT_EQ(2.0, D->evaluate());
}

TEST(SqrTest, SqrDouble)
{
        Op* op4 = new Op(4.0);

        Sqr* D = new Sqr(op4);

        EXPECT_EQ(16.0, D->evaluate());
}

TEST(MultTest, MultDouble)
{
        Op* op4 = new Op(4.0);
	Op* op2 = new Op(2.0);

	Mult* M = new Mult(op4,op2);
        EXPECT_EQ(8.0, M->evaluate());
}

TEST(MultTwiceTest, MultDouble)
{
        Op* op4 = new Op(4.0);
        Op* op2 = new Op(2.0);

        Mult* M = new Mult(op4,op2);
	Mult* N = new Mult(M, op2);
        EXPECT_EQ(16.0, N->evaluate());
}
TEST(ListTestSize, ListContainer)
{
        Op* op4 = new Op(4.0);
        Op* op2 = new Op(2.0);
	
        Mult* M = new Mult(op4,op2);
        Op* O = new Op(3.0);
	ListContainer* l_container= new ListContainer();
	l_container->add_element(op4);
    	l_container->add_element(M);
    	l_container->add_element(op2);
	l_container->add_element(O);	
	EXPECT_EQ(4, l_container->size());
}

TEST(VectorTestSize, VectorContainer)
{
        Op* op4 = new Op(4.0);
        Op* op2 = new Op(2.0);

        Mult* M = new Mult(op4,op2);
        Op* O = new Op(3.0);
        VectorContainer* v_container= new VectorContainer();
        v_container->add_element(op4);
        v_container->add_element(M);
        v_container->add_element(op2);
	EXPECT_EQ(3, v_container->size());
}

TEST(AbsTester, AbsClass)
{
	Op* abs_tester = new Op(-5.8);
    	Abs* test_Abs = new Abs(abs_tester);
	EXPECT_EQ(5.8, test_Abs->abs());
}

TEST(FloorTester, FloorClass)
{
        Op* Floor_tester = new Op(2.67);
        Floor* test_floor = new Floor(Floor_tester);
        EXPECT_EQ(2, test_floor->floor());
}

TEST(CeilTester, CeilClass)
{
        Op* ceil_tester = new Op(4.34);
        Ceiling* test_ceil = new Ceiling(ceil_tester);
        EXPECT_EQ(5, test_ceil->ceil());
}

TEST(AbsFloorTester, AbsFloor) 
{
  Op* abs_floor_tester = new Op(-4.55);
  Floor* test_abs_floor = new Floor(abs_floor_tester);
  Abs* test_abs_on_floor = new Abs(test_abs_floor);
  EXPECT_EQ(5, test_abs_on_floor->abs());
}

TEST(AbsCeilTester, AbsCeil) 
{
  Op* abs_ceil_tester = new Op(-4.55);
  Ceiling* test_abs_ceil = new Ceiling(abs_ceil_tester);
  Abs* test_abs_on_ceil = new Abs(test_abs_ceil);
  EXPECT_EQ(4, test_abs_on_ceil->abs());
}

TEST(ListSortTester, ListSortTest) 
{
    Op* C = new Op(7);
    Op* D = new Op(4);

    Op* B = new Op(3);
    Op* A = new Op(2);

    ListContainer* l_container= new ListContainer();
    l_container->add_element(D);
    l_container->add_element(C);
    l_container->add_element(B);
    l_container->add_element(A);

    l_container->set_sort_function(new SelectionSort());
    l_container->sort();
    EXPECT_EQ(2, l_container->at(0)->evaluate());
    EXPECT_EQ(3, l_container->at(1)->evaluate());
    EXPECT_EQ(4, l_container->at(2)->evaluate());
    EXPECT_EQ(7, l_container->at(3)->evaluate());
}

TEST(VectorSortTester, ListSortTest)
{
    Op* C = new Op(7);
    Op* D = new Op(4);

    Op* B = new Op(3);
    Op* A = new Op(2);

    VectorContainer* container = new VectorContainer();
    container->add_element(A);
    container->add_element(B);
    container->add_element(C);
    container->add_element(D);

    container->set_sort_function(new BubbleSort());
    container->sort();
    EXPECT_EQ(2, container->at(0)->evaluate());
    EXPECT_EQ(3, container->at(1)->evaluate());
    EXPECT_EQ(4, container->at(2)->evaluate());
    EXPECT_EQ(7, container->at(3)->evaluate());
}

TEST(HexPrintTest, Hex)
{
	HexPrint *hex = new HexPrint(4.0);
	
	std::ostringstream oss;
	std::streambuf* p_cout_streambuf = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf());
	hex->print();
	std::cout.rdbuf(p_cout_streambuf);
		
	EXPECT_EQ("4.000000e+00",oss.str());
}

TEST(DoublePrintTest, DoublePrint)
{
	DoublePrint* doub = new DoublePrint(5.6);
	
        std::ostringstream oss;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());
        doub->print();
        std::cout.rdbuf(p_cout_streambuf);

	EXPECT_EQ("5.6", oss.str());
}

TEST(BinaryPrintTest, DoublePrint)
{
	BinaryPrint *bin = new BinaryPrint(2.0);
	
	std::ostringstream oss;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());
	bin->print();
	std::cout.rdbuf(p_cout_streambuf);

	EXPECT_EQ("0000000000000010", oss.str());
}

TEST(DoubleFactTest, test)
{
	DoubleFactory *df = new DoubleFactory();
	BasePrint *newDF = df->generatePrint(1.0);
	newDF->print();
	std::cout << endl;
}

TEST(HexFactTest, test)
{
	HexFactory *hf = new HexFactory();
	BasePrint *newHF = hf->generatePrint(3.1);
	
	std::ostringstream oss;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());
        newHF->print();
        std::cout.rdbuf(p_cout_streambuf);
	EXPECT_EQ("3.100000e+00", oss.str());
}

TEST(BinFactTest, test)
{
	BinaryFactory *bf = new BinaryFactory();
	BasePrint *newBF = bf->generatePrint(1.9);

	std::ostringstream oss;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());
	newBF->print();
	std::cout.rdbuf(p_cout_streambuf);

	EXPECT_EQ("0000000000000001", oss.str());
}

TEST(VectorDoubleFactoryTester, VectorFactoryTest)
{
    Op* C = new Op(7);
    Op* D = new Op(4);

    Op* B = new Op(3);
    Op* A = new Op(2);

    VectorContainer* container = new VectorContainer();
    container->add_element(A);
    container->add_element(B);
    container->add_element(C);
    container->add_element(D);

    container->set_print_factory(new DoubleFactory);
    
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    container->print();
    std::cout.rdbuf(p_cout_streambuf);
    EXPECT_EQ("2 3 7 4 ", oss.str());
}

TEST(VectorHexFactoryTester, VectorFactoryTest)
{
    Op* C = new Op(7);
    Op* D = new Op(4);

    Op* B = new Op(3);
    Op* A = new Op(2);

    VectorContainer* container = new VectorContainer();
    container->add_element(A);
    container->add_element(B);
    container->add_element(C);
    container->add_element(D);

    container->set_print_factory(new HexFactory);
    
	    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    container->print();
    std::cout.rdbuf(p_cout_streambuf);
    EXPECT_EQ("2.000000e+00 3.000000e+00 7.000000e+00 4.000000e+00 ", oss.str());
}

TEST(ListBinaryFactoryTester, ListFactoryTest) 
{
    Op* C = new Op(7);
    Op* D = new Op(4);

    Op* B = new Op(3);
    Op* A = new Op(2);

    ListContainer* l_container= new ListContainer();
    l_container->add_element(D);
    l_container->add_element(C);
    l_container->add_element(B);
    l_container->add_element(A);

    l_container->set_print_factory(new BinaryFactory);
   
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    l_container->print();
    std::cout.rdbuf(p_cout_streambuf);

	EXPECT_EQ("0000000000000100 0000000000000111 0000000000000011 0000000000000010 ", oss.str());
}

TEST(FactoryFlagsTester, FactoryFlagTest)
{
    BaseFactory* printfac;
    int expectset;

    if (GLOBAL_ARGC < 2) {
      std::cout << "Please input one flag (d, h, or b). Flag set to default (Double)" << endl;
      printfac = new DoubleFactory();
      expectset = 1;
    }  

    if (std::string(GLOBAL_ARGV[1]) == "d") {
      cout << "Print Factory set to Double." << endl;
      printfac = new DoubleFactory();
	expectset = 1;
    }

    else if (std::string(GLOBAL_ARGV[1]) == "h") {
      cout << "Print Factory set to Hex." << endl;
      printfac = new HexFactory();
	expectset = 2;
    }

    else if (std::string(GLOBAL_ARGV[1]) == "b") {
      cout << "Print Factory set to Binary." << endl;
      printfac = new BinaryFactory();
	expectset = 3;
    }
	
    else {
      std::cout << "Your input was " << GLOBAL_ARGV[1] << ". Please input the flags (d, h, or b). Flag set to default (Double)" << endl;
      printfac = new DoubleFactory();
      expectset = 1;
    }
	
    Op* op7 = new Op(7);
    Op* op4 = new Op(4);
    
    Op* op3 = new Op(3);
    Op* op2 = new Op(2);
    
    Mult* A = new Mult(op7, op4);
    Add* B = new Add(op3, op4);
    Sub* C = new Sub(B, op2);
    Sqr* D = new Sqr(C);
    
    VectorContainer* container = new VectorContainer();
    container->add_element(A);
    container->add_element(B);
    container->add_element(C);
    container->add_element(D);

    container->set_print_factory(printfac);
    
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    if (expectset == 1){
	container->print();
    	std::cout.rdbuf(p_cout_streambuf);
	EXPECT_EQ("28 7 5 25 ", oss.str());
}
    else if (expectset == 2)
{
	        container->print();
        std::cout.rdbuf(p_cout_streambuf);
        EXPECT_EQ("2.800000e+01 7.000000e+00 5.000000e+00 2.500000e+01 ", oss.str());
}
    else if (expectset == 3)
{
                container->print();
        std::cout.rdbuf(p_cout_streambuf);
        EXPECT_EQ("0000000000011100 0000000000000111 0000000000000101 0000000000011001 ", oss.str());
}
}

TEST(ListFactoryFlagsTester, ListFactoryFlagTest)
{
    BaseFactory* printfac;
    int expectset;
    if (GLOBAL_ARGC < 2) {
      std::cout << "Please input one flag (d, h, or b). Flag set to default (Double)" << endl;
      printfac = new DoubleFactory();
      expectset = 1;
    }  

    if (std::string(GLOBAL_ARGV[1]) == "d") {
      cout << "Print Factory set to Double." << endl;
      printfac = new DoubleFactory();
	expectset = 1;
    }

    else if (std::string(GLOBAL_ARGV[1]) == "h") {
      cout << "Print Factory set to Hex." << endl;
      printfac = new HexFactory();
	expectset = 2;
    }

    else if (std::string(GLOBAL_ARGV[1]) == "b") {
      cout << "Print Factory set to Binary." << endl;
      printfac = new BinaryFactory();
	expectset = 3;
    }
	
    else {
      std::cout << "Your input was " << GLOBAL_ARGV[1] << ". Please input the flags (d, h, or b). Flag set to default (Double)" << endl;
      printfac = new DoubleFactory();
      expectset = 1;
    }
	
    Op* op7 = new Op(7);
    Op* op4 = new Op(4);
    
    Op* op3 = new Op(3);
    Op* op2 = new Op(2);
    
    Mult* A = new Mult(op7, op4);
    Add* B = new Add(op3, op4);
    Sub* C = new Sub(B, op2);
    Sqr* D = new Sqr(C);
    
    ListContainer* l_container= new ListContainer();
    l_container->add_element(D);
    l_container->add_element(C);
    l_container->add_element(B);
    l_container->add_element(A);
    
    l_container->set_print_factory(printfac);
    l_container->print();
  
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    if (expectset == 1)
	{
        	l_container->print();
        	std::cout.rdbuf(p_cout_streambuf);
        	EXPECT_EQ("25 5 7 28 ", oss.str());
	}
    else if (expectset == 2)
	{
        	l_container->print();
        	std::cout.rdbuf(p_cout_streambuf);
        	EXPECT_EQ("2.500000e+01 5.000000e+00 7.000000e+00 2.800000e+01 ", oss.str());
	}
    else if (expectset == 3)
	{
        	l_container->print();
        	std::cout.rdbuf(p_cout_streambuf);
        	EXPECT_EQ("0000000000011001 0000000000000101 0000000000000111 0000000000011100 ", oss.str());
	}
}

int main(int argc, char **argv) {
  GLOBAL_ARGC = argc;
  GLOBAL_ARGV = argv;
	
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}













