#include <boost/type_traits.hpp>
#include <iostream>
#include <vector>

int main()
{
    int i = 5;
    double d = 2.3;

    std::cout << "int   : " << boost::is_integral<int>::value << std::endl;
    std::cout << "double: " << boost::is_integral<double>::value << std::endl;
    std::cout << "int   : " << boost::is_floating_point<int>::value << std::endl;
    std::cout << "double: " << boost::is_floating_point<double>::value << std::endl;
    std::cout << "vector<int> is int: " << boost::is_integral< std::vector<int> >::value << std::endl;
    std::cout << "vector<int> is array: " << boost::is_array< std::vector<int> >::value << std::endl;
    return 0;
}

