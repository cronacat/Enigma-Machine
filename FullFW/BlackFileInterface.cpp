#include "BlackFileInterface.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

//
// Implement the following operations for both the red and black files.
// All return true if OK, otherwise false.
//
bool BlackFileInterface::openForRead() {
	if (!MyInFile) {
		// printf("Black not open for read\n");
		return false;
	}
	// printf("Black open for read\n");
	MyInFile.open(BlackInFN, ios::in);
	return true;
}

unsigned char BlackFileInterface::getNextChar() {
	if (!MyInFile.good()) {
		// printf("No next char\n");
		return 0;
	}
	// printf("Black get char\n");
	return MyInFile.get();
}

bool BlackFileInterface::openForWrite() {
	if (!MyInFile) {
		// printf("Black not open for write\n");
		return false;
	}
	// printf("Black open for write\n");
	MyInFile.open(BlackOutFN, ios::out);
	return true;
}

bool BlackFileInterface::putNextChar(unsigned char c) {
	if (MyInFile) {
		// printf("Black put next char\n");
		MyInFile.put(c);
		return true;
	}
	// printf("Black can't put next char\n");
	return false;
}

bool BlackFileInterface::eof() {
	if (MyInFile.eof()) {
		// printf("Black EOF\n");
		return true;
	}
	// printf("Black not EOF\n");
	return false;
}

bool BlackFileInterface::close() {
	if (!MyInFile) {
		// printf("Black not close file\n");
		return false;
	}
	// printf("Black close file\n");
	MyInFile.flush();
	MyInFile.close();
	return true;
}