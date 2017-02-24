#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;

int main(void)
{
    ptime NOW(microsec_clock::local_time());

    std::cout << NOW << std::endl;

    time_duration DELTA = microsec_clock::local_time() - NOW;

    std::cout << DELTA << std::endl;

    return 0;
}
