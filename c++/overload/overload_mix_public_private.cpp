#include <iostream>

class Foo
{
public:
    void print_int(int i) {
        print_int(i, "\n");
    };

private:
    void print_int(int i, const std::string &line_end)
    {
        std::cout << "int: " << i << line_end;
    }
};

int main()
{
    Foo f;
    f.print_int(5);
    return 0;
}
