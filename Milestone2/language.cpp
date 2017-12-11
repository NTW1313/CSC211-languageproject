#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>

#include "language.h"

/*
	language.cpp
	language class implementation
*/

//std::vector<int> frequencies;
//std::string langName;

//default constructor
language::language(){
	langName = "";
}
//parameterized constructor
language::language(std::string filename) {
	langName = filename;
}
//parameterized constructor
language::language(std::string filename, std::vector<int> freq){
	langName = filename;
	frequencies = freq;
}
/*
	countTrigrams() method 
	counts the trigram frequencies of the language and
	stores them in a vector
	returns a language object with the filename and frequencies stored
*/
language language::countTrigrams(){
	
	//the name of the file 
	std::string filename = langName;
	
	//the frequencies vector will hold all of the frequencies of the trigrams
	std::vector<int> frequencies(pow(27.0, 3.0)); 
	
	//read file
	std::fstream infile;
	
	//opens the file
	infile.open(filename);
	
	//if the file opens
	if(!infile.fail()){
		
		std::string text = "";
		
		for (std::string line; std::getline(infile, line); ) {
			text.append(line);
		}
		
		//for loop to look at all possible trigrams
		for (int i = 0; i < (int) text.length() - 2; i+=1) {
			std::string trigram = text.substr(i,3);
			
			//get the ascii code for each char
			int indexa = trigram[0];
			int indexb = trigram[1];
			int indexc = trigram[2];
			
			if(indexa==32){indexa = 0;}// if its a space, map it to 0
			else{indexa = indexa - 96;}// - 96 so 'a' is 1, 'b' is 2, and so on
			
			if(indexb==32){indexb = 0;}
			else{indexb = indexb - 96;}
			
			if(indexc==32){indexc = 0;}
			else{indexc = indexc - 96;}
			
			//find the index of the trigram in frequencies
			int index = indexa * pow(27.0, 2.0) + indexb * 27 + indexc;  
			
			//add 1 to the frequencies vector at the trigram's position
			frequencies[index] = frequencies[index] + 1; 
			
		}
		
		//close file here
		infile.close();
		
		return language(filename, frequencies); //return a new language object 
	}
	else{
		//if the file does not open
		std::cerr << "File cannot open, please check input" << std::endl;
		exit(EXIT_FAILURE);
	}

}

/*
	getter methods
*/

//get frequencies: returns the vector of frequencies
std::vector<int> language::getFrequencies(){
	return frequencies;
}

//get language name: returns the name of the language (the filename)
std::string language::getlangName(){
	return langName;
}



