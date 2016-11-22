#include <boost/function.hpp>
#include <iostream>

// Compile with:
// g++ -std=c++11

void run_boost_func(boost::function<void(double)> x)
{
    x(0.1);
}

void run_boost_func2(std::function<void(double)> x)
{
    x(0.1);
}


int main(void)
{
    auto l = [](double x)->void { std::cout << x << std::endl; };
    // These are all the same:
    run_boost_func(static_cast< boost::function<void(double)> >(l));
    run_boost_func(l);
    run_boost_func2(l);
    // boost::function and std::function aren't really that different.
    return 0;
}
