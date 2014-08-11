#include <iostream>

// If you want to replace parts of strings use ##:
#define FOO(a) \
	a##_1 + a##_2

int main()
{
	int x_1 = 1, x_2 = 2;

	// Replaces with x_1 + x_2 and prints 3
	std::cout << FOO(x) << std::endl;
	return 0;
}
