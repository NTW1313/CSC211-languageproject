#include <string>
#include <vector>
#include <fstream>

#ifndef _language_h
#define _language_h

/*

	language.h
	Language class template

*/


class language{

public:

	//default constructor
	language();

	//parameterized constructors
	language(std::string filename);
	
	language(std::string filename, std::vector<int> freq);
	
	/*
	method to count trigram frequencies 
	returns the frequencies in a vector
	*/
	language countTrigrams();
	
	/*
	getter method for the vector of
	frequencies
	*/
	std::vector<int> getFrequencies();
	
	/*
	getter function for the name of the file
	*/
	std::string getlangName();
	
	

private:
	
	//data members
	std::string langName;
	std::vector<int> frequencies;

};

//end language.h
#endif