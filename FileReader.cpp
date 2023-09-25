#include "FileReader.h"

FileReader::FileReader(const char* path){


	this->Fptr = new std::ifstream(path);
	this->Buffer = new std::stringstream;

	if (this->Fptr->is_open()) {
		*this->Buffer << this->Fptr->rdbuf();
		this->Fptr->close();

	}
	else {
		std::cerr << "Failed to Open FILE" << std::endl;
	}
}

void FileReader::Test()
{
	std::cout << this->Buffer->str() << std::endl;

}
