#include <iostream>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

class Foo
{
public:
    // Overloaded functions:
    void print_this(int x) { std::cout << "(int) " << x << std::endl; };
    void print_this(std::string x) { std::cout << "(string) " << x << std::endl; };

};

int main()
{
    int i = 5;
    boost::shared_ptr<Foo> f = boost::make_shared<Foo>();
    // This wouldn't compile, because boost::bind can't resolve print_this:
    //boost::bind(&Foo::print_this, f, i)();

    // An explicit cast will fix:
    boost::bind( static_cast< void (Foo::*)(int)>(&Foo::print_this), f, i)();

    return 0;
}
