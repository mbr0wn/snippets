#include <iostream>

// Compile with:
// g++ -std=c++11

int main(void)
{
    // Full format: [ captures ]( parameters ) ->returntype { statements; }
    auto sum = [](int x, int y){ return x + y; };
    // Or: auto sum = [](int x, int y)->int { return x + y; };

    // With captures (create closure):
    int x = 5;
    auto add_to_x = [x](int y){ return x + y; };

    std::cout << sum(1, 2) << std::endl;
    std::cout << add_to_x(3) << std::endl;
    return 0;
}
