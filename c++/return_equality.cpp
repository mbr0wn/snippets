#include <iostream>

class foo
{
 public:
     int set(int x) { return y = x; };

     int y;
};


int main()
{
    foo F;
    std::cout << "y == " << F.set(5) << std::endl;
    return 0;
}

