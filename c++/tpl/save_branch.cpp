#include <iostream>

template <bool b>
class foo
{
public:
    void print_bool()
    {
        if (b) {
            std::cout << "true" << std::endl;
        } else {
            std::cout << "false" << std::endl;
        }
    }
};


template <bool b>
void print_bool()
{
    if (b) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
}

int main()
{
    foo<true> Foo;
    Foo.print_bool();
    print_bool<false>();
    return 0;
}
