#include "../include/hw2.h"
#include "gtest/gtest.h"

#include <iostream>

int main(int argc, char* argv[])
{

    if (false) // make false to run unit tests
    {
        // debug section
        Login l;
        l.readFile("src/users.txt");
    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << RUN_ALL_TESTS() << std::endl;
    }
}