#include <iostream>


// Templated function
template <typename T>
void print_something(T foo)
{
	std::cout << foo << std::endl;
}

// Specialized function
void print_something(int foo)
{
	std::cout << "(int) " << foo << std::endl;
}

// Templated function
template <typename T>
T return_something(void)
{
	// Careful, this will only work on PODs
	// This is just for this example!
	T t = 0;
	return t;
}

// Specialized function
int return_something(void)
{
	return 23;
}


int main()
{
	double d = 2.8;
	// Automatically resolves the template:
	print_something(d);
	// And is the same as:
	print_something<double>(d);
	int i = 5;
	// This will call the specialized function:
	print_something(i);
	// But this will not:
	print_something<int>(i);

	// This calls the specialized version:
	std::cout << return_something() << std::endl;
	// This, obviously, does not:
	std::cout << return_something<double>() << std::endl;
	return 0;
}
