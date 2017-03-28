#include <iostream>
#include <memory>

// Store a var inside a lambda for re-use, without using move captures:
// With move captures, or even named captures, a unique_ptr is a better
// option.
// Note there is a certain expectation that lambdas are stateless.

decltype(auto) get_lambda()
{
    auto x = std::make_shared<int>(5);
    std::cout << "Current refs: " << x.use_count() << std::endl;
    auto l = [x](){
        if (*x == 5) {
            std::cout << "five" << std::endl;
            *x = 3;
        }
        else {
            std::cout << *x << std::endl;
            (*x)++;
        }
        std::cout << "Current refs: " << x.use_count() << std::endl;
    };
    l();
    return l;
}

int main(void)
{
    auto l = get_lambda();
    l();
    l();
    return 0;
}
