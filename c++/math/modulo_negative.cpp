#include <iostream>

#define PRINT_EXPRESSION(x) \
    std::cout << #x << " == " << (x) << std::endl;

int main(int argc, const char *argv[])
{
    PRINT_EXPRESSION(2 % 3);
    PRINT_EXPRESSION(5 % 3);
    PRINT_EXPRESSION(-2 % 3);
    PRINT_EXPRESSION(-5 % 3);

    return 0;
}
