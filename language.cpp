//language.cpp
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>

#include "language.h"

std::vector<int> frequencies;
std::string langName;

language::language(){
	langName = "";
	
}

language::language(std::string filename) {
	langName = filename;
}

language::language(std::string filename, std::vector<int> freq){
	langName = filename;
	frequencies = freq;
}

language language::countTrigrams(){
	std::string filename = langName;
	std::vector<int> frequencies(pow(27.0, 3.0)); //the frequencies vector will hold all of the frequencies of the trigrams
    
	//read file
	std::fstream infile;
	
	infile.open(filename);
	
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
			
			frequencies[index] = frequencies[index] + 1; //add 1 one the frequencies vector at the trigram's position
			
		}
		
		//close file here
		infile.close();
		
		return language(filename, frequencies); //return a new language object 
	}
	else{
		std::cerr << "File cannot open, please check input" << std::endl;
		exit(EXIT_FAILURE);
	}

}



std::vector<int>getFrequencies(){
	return frequencies;
}


std::string getlangName(){
	return langName;
}







