#include <boost/thread.hpp>
#include <iostream>
#include <chrono>
#include <thread>



void ten_sleeps()
{
    for (int i = 0; i < 10; i++) {
        std::cout << "Sleeping " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main(void)
{
    // Both of these use the same pthreads under the hood, so this'll
    // both do the same:
    auto t1 = std::thread(&ten_sleeps);
    t1.join();

    auto t2 = boost::thread(&ten_sleeps);
    t2.join();

    return 0;
}
