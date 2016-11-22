#include <iostream>
#include <functional>

void run_3(std::function<int(int)> f)
{
    std::cout << f(3) << std::endl;
}

int main(void)
{
    int x = 5;
    auto l = [&x](int y){return x + y;};
    run_3(l); // x is still in scope here!
    return 0;
}
