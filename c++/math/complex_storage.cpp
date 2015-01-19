#include <iostream>
#include <complex>

// How are complex numbers stored?
int main(int argc, const char *argv[])
{
    std::complex<short> c(1, 30000);
    std::cout << " c: " << c << std::endl;
    std::cout << " c.real(): " << c.real() << std::endl;

    short *c_ptr = reinterpret_cast<short *>(&c);
    std::cout << " c_ptr[0]: " << c_ptr[0] << " c_ptr[1]: " << c_ptr[1] << std::endl;

    return 0;
}
