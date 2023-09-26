#define _CRT_SECURE_NO_WARNINGS
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


	this->toFree = nullptr;

	
}










void FileReader::Debug()
{
	std::cout << this->Buffer->str() << std::endl;

}



char* FileReader::GetSource()
{
	char* result = new char[this->Buffer->str().length() + 1];
	
	strcpy(result, this->Buffer->str().c_str());
	
	this->toFree = (void*)result;


	return result;
}
