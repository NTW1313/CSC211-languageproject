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
	
	
	//gets the vector of frequencies
	std::vector<int> getFrequencies();
	
	
	//gets the name of the language
	std::string getlangName();
	
	

private:
	
	std::string langName;
	std::vector<int> frequencies;

};

#endif