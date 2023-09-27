#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>

#include "Definition.h"

class FileReader{
private:
	std::ifstream* Fptr = nullptr;
	std::stringstream* Buffer = nullptr;
	void* toFree;

public:
	FileReader(const char*);
	FileReader() {};
	RETURNVOID ReleaseMemory(PARAMETERVOID);

	RETURNVOID Debug(PARAMETERVOID);
	char* GetSource(PARAMETERVOID);
};

