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
#include "command.h"

#include "gtest/gtest.h"

TEST(AddCommand, AddCommandTest)
{
	Menu* menu = new Menu();
	menu->add_command(new OpCommand(1));	
	menu->add_command(new AddCommand(menu->get_command(),2));
	
        EXPECT_EQ(3, menu->execute());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

