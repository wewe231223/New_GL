#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

class FileReader{
private:
	std::ifstream* Fptr;
	std::stringstream* Buffer;

public:
	FileReader(const char*);

	void Debug();
	const char* GetSource();
};

