/*

Simple test for new cv::FileStorage copy constructor
and assignment operator

Uses test.yml

*/

#include <iostream>
#include <opencv2/core/persistence.hpp>

using namespace std;

int main(int argc, char* argv[]) {
	
	cv::FileStorage fs;
	fs = cv::FileStorage("test.yml", cv::FileStorage::READ);
	
	/* cv::FileStorage fs("test.yml", cv::FileStorage::READ); */
	
	std::string s;
	fs["string"] >> s;

	// If everything works well, s contains "Hello World!"
	assert(s == "Hello World!");

	return 0;
}