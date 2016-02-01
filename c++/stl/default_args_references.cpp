#include <iostream>
#include <set>
#include <string>

// References can't have default values unless they're const:
//void print_set(std::set< std::string > &s=std::set< std::string >())
void print_set(const std::set< std::string > &s=std::set< std::string >())
{
    std::cout <<  "set size: " << s.size() << std::endl;
}

// Same is also true for PODs (kind of pointless to have a const ref int though)
//void print_int(int &i=5)
void print_int(const int &i=5)
{
    std::cout << "int: " << i << std::endl;
}

int main(int argc, const char *argv[])
{
    print_set();
    return 0;
}
