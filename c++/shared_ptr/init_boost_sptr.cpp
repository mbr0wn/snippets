#include <iostream>
#include <boost/shared_ptr.hpp>

class foo
{
public:
	typedef boost::shared_ptr<foo> sptr;

	foo() : x(0) {};

	void print_something() { std::cout << "foo " << x << std::endl; };
	int x;
};

int main()
{
	foo::sptr F;

	if (not F) // Is definitely true
		std::cout << "F not initialized." << std::endl;
	if (F == NULL) // So is this
		std::cout << "F == NULL" << std::endl;
	// And this is zero
	std::cout << "F.use_count(): " << F.use_count() <<  std::endl;

	F = foo::sptr(new foo); // Init

	if (F) // Is true if init was successful
		std::cout << "F not initialized." << std::endl;
	if (F == NULL) // So is this
		std::cout << "F == NULL" << std::endl;
	// And this is one
	std::cout << "F.use_count(): " << F.use_count() <<  std::endl;

	// This will fail if init failed
	F->x = 5;

	foo::sptr F2 = F;
	// This is 2 now
	std::cout << "F.use_count(): " << F.use_count() <<  std::endl;

	// Clear this ref
	F.reset();
	// This is 1 now
	std::cout << "F.use_count(): " << F2.use_count() <<  std::endl;
	F2->print_something();

	return 0;
}
