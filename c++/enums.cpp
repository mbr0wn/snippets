#include <iostream>

enum test_enum
{
    ENTRY_FOO = 0,
    ENTRY_BAR = 1,
    ENTRY_BAZ = ENTRY_BAR
};


int main()
{
    std::cout << ENTRY_FOO << std::endl;
    std::cout << ENTRY_BAR << std::endl;
    std::cout << ENTRY_BAZ << std::endl;
    return 0;
}
