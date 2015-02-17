#include <iostream>
#include <vector>
#include <typeinfo>

int main()
{
    int k = 5;
    int *p;
    double dbl = 2.3;
    std::vector<int> i_v(10, 0);

    std::cout << "int: " << typeid(int).name() << std::endl;
    std::cout << "k  : " << typeid(k).name() << std::endl;
    std::cout << "p  : " << typeid(p).name() << std::endl;
    std::cout << "dbl: " << typeid(dbl).name() << std::endl;
    std::cout << "i_v: " << typeid(i_v).name() << std::endl;

    return 0;
}
