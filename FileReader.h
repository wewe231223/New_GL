#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>

class FileReader{
private:
	std::ifstream* Fptr;
	std::stringstream* Buffer;
	void* toFree;

public:
	FileReader(const char*);


	void Debug();
	char* GetSource();
};

