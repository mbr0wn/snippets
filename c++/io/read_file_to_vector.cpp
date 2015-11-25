#include <boost/cstdint.hpp>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

int main()
{
    // Open file:
    ifstream file("foo.dat", ios::binary);
    vector<boost::uint8_t> buff;

    // Copy:
    copy(
        istream_iterator<boost::uint8_t>(file),
        istream_iterator<boost::uint8_t>(),
        back_inserter(buff)
    );

    // Stats:
    cout << "Buffer size: " << buff.size() << std::endl;
    cout << "Bytes:" << endl;
    for (size_t i = 0; i < buff.size(); i++) {
        cout << size_t(buff[i]) << endl;
    }
    cout << endl;
    return 0;
}
