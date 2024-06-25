#include "RedFileInterface.h"
#include <iostream>
#include <fstream>

using namespace std;

// All return true if OK, otherwise false.
bool RedFileInterface::openForRead() {
	if (fileOpen) {
		// printf("Red not open for read\n");
		return false;
	}
	// printf("Red open for read\n");
	MyInFile.open(RedInFN, ios::in);
	return true;
}

unsigned char RedFileInterface::getNextChar() {
	if (!MyInFile.good()) {
		// printf("No next char\n");
		return 0;
	}
	// printf("Red get char\n");
	return MyInFile.get();
}

bool RedFileInterface::openForWrite() {
	if (fileOpen) {
		// printf("Red not open for write\n");
		return false;
	}
	// printf("Red open for write\n");
	MyInFile.open(RedOutFN, ios::out);
	return true;
}

bool RedFileInterface::putNextChar(unsigned char c) {
	if (MyInFile) {
		// printf("Red put next char\n");
		MyInFile.put(c);
		return true;
	}
	// printf("Red can't put next char\n");
	return false;
}

bool RedFileInterface::eof() {
	if (MyInFile.eof()) {
		// printf("Red EOF\n");
		return true;
	}
	// printf("Red not EOF\n");
	return false;
}

bool RedFileInterface::close() {
	if (!MyInFile) {
		// printf("Red not close file\n");
		return false;
	}
	// printf("Red close file\n");
	MyInFile.flush();
	MyInFile.close();
	return true;
}