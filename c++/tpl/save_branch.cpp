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

// Also demo some inheritance:
class bar_always_true : public foo<true>
{};

template <bool b>
class bar_keep_tpl_arg : public foo<b>
{
    // If parent class has a constructor, pass in the template argument
    // as well:
    // bar_keep_tpl_arg() : foo<b>() {};
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

// We've created 2 separate print_bool() functions now, so we have to
// treat them like they're completely different things:
void print_bool_arg(bool b)
{
    if (b) {
        print_bool<true>();
    } else {
        print_bool<false>();
    }
}

int main()
{
    foo<true> Foo;
    Foo.print_bool();
    print_bool<false>();
    // This is pointless:
    print_bool_arg(true);
    return 0;
}

