#include <iostream>
#include <sstream>
#include "menu.h"
#include "composite.h"

#include "gtest/gtest.h"

TEST(AddCommand, AddCommandTest)
{       
        Menu* menu = new Menu();
        menu->add_command(new OpCommand(1));
        menu->add_command(new AddCommand(menu->get_command(),2));
        menu->add_command(new SubCommand(menu->get_command(), 2));
        menu->execute();
    
        std::ostringstream oss;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());
        
        menu->execute();
        std::cout.rdbuf(p_cout_streambuf);

        EXPECT_EQ("3",oss.str());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
