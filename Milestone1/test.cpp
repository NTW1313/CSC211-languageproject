//Final Project Milestone 1

#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <iostream>

//test.cpp
//Code by Nora Wallace and Aman Negassi
    
//chars to look for are lowercase a-z (97-122), space (' ') (032), and newline ('\n').

 //countTrigrams counts the trigram frequencies and returns a vector of them
std::vector<int> countTrigrams(std::string text){//takes a string for milestone 1

    double length = pow(27.0, 3.0); //the length of the frequencies vector
	std::vector<int> frequencies(length); //the frequencies vector will hold all of the frequencies of the trigrams
    
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
    
    return frequencies; //return the frequencies as a vector
    
}
//function to print out frequencies
void printFreq(std::vector<int> frequencies){
	
    for(unsigned i = 0; i < frequencies.size(); i++){
        std::cout << frequencies[i];
        std::cout << " ";
    }
    
}

//main function
int main(int argc, char *argv[]){
	
	if (argc != 2) { //if more than one argument, exception
		std::cerr << "Please provide input with quotation marks surrounding it to test for trigrams" << std::endl;
		exit(EXIT_FAILURE);
	} else {
		std::string testInput = argv[1]; //take user input
		std::vector<int> frequencies = countTrigrams(testInput); //get vector of all trigram frequencies for input
		printFreq(frequencies); //print the frequencies
	}
    
}



