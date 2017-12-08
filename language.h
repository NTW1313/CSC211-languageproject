//language.h

#ifndef _language_h
#define _language_h

#include <string>
#include <vector>
#include <ifstream>


class language{

public:

	//default constructor
	language();

	//parameterized constructor
	//if the file isn't there, error out
	language(std::string filename);
	
	getFrequencies(); 
	getFilename();
	
	//method to count trigrams frequencies given the file
	std::vector<int> countTrigrams(std::string filename);

private:
	
	std::string filename;
	std::vector<int> frequencies;

}

#endif