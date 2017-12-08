#include <string>
#include <vector>
#include <fstream>

#ifndef _language_h
#define _language_h


//language.h
class language{

public:

	//default constructor
	language();

	
	//parameterized constructor
	//if the file isn't there, error out
	language(std::string filename);
	
	language(std::string filename, std::vector<int> freq);
	
	//method to count trigrams frequencies 
	language countTrigrams();
	
	std::vector<int> getFrequencies();
	
	
	std::string getlangName();
	
	

private:
	
	std::string filename;
	std::vector<int> frequencies;

};

#endif