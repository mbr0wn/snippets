#include <iostream>


int main()
{
    int y;
    int &x = y;
    y = 5;

    std::cout << "x == " << x << std::endl;
    x = 23;
    std::cout << "y == " << y << std::endl;

    return 0;
}
