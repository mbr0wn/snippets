#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Read a file to buffer, wait until eof, then reset
int main()
{
	std::ifstream infile;
	std::string fname("ifstream_past_eof.cpp"); // Read this file, because it's there
	infile.open(fname.c_str(), std::ifstream::binary);

	size_t bytes_read = 0;
	size_t bytes_per_read = 100;
	std::vector<char> buff(bytes_per_read); // Buffer of length 10
	while (not infile.eof()) {
		infile.read((char *) &buff[0], bytes_per_read);
		bytes_read += infile.gcount();
		std::cout << "Bytes read: " << bytes_read << std::endl;
	}
	std::cout << "Reached EOF." << std::endl;

	infile.clear();
	infile.seekg(0);

	while (not infile.eof()) {
		infile.read((char *) &buff[0], bytes_per_read);
		bytes_read += infile.gcount();
		std::cout << "Bytes read: " << bytes_read << std::endl;
	}
	std::cout << "Reached EOF." << std::endl;

	return 0;
}
