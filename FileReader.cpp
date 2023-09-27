#define _CRT_SECURE_NO_WARNINGS
#include "FileReader.h"


FileReader::FileReader(const char* path){


	this->Fptr = new std::ifstream(path);
	this->Buffer = new std::stringstream;

	if (this->Fptr->is_open()) {
		*this->Buffer << this->Fptr->rdbuf();
		this->Fptr->close();
		this->Available = true;
	}
	else {
		std::cerr << "Failed to Open FILE" << std::endl;
		
	}


	this->toFree = nullptr;

	
}




RETURNVOID FileReader::ReleaseMemory(PARAMETERVOID) {
	delete this->toFree;
}







RETURNVOID FileReader::Debug(PARAMETERVOID)
{
	std::cout << this->Buffer->str() << std::endl;

}



bool FileReader::GetAvailable()
{
	return this->Available;
}

char* FileReader::GetSource(PARAMETERVOID)
{
	char* result = new char[this->Buffer->str().length() + 1];
	
	strcpy(result, this->Buffer->str().c_str());
	
	this->toFree = (void*)result;


	return result;
}
