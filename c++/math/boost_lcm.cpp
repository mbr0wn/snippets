#include <iostream>
#include <boost/math/common_factor.hpp>

int main()
{
	boost::uint32_t x = 250000;
	boost::uint32_t y = 5000000;
	
	std::cout << "lcm(" << x << ", " << y << ") == " << boost::math::lcm<boost::uint32_t>(x, y) << std::endl;

	return 0;
}
