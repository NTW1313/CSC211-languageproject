//Final Project Milestone 1

#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <iostream>



    
//chars to look for are lowercase a-z (97-122), space (' ') (032), and newline ('\n'). 
std::vector<int> countTrigrams(std::string text){//takes a string for milestone 1

    double length = pow(27.0, 3.0); //How did we determine these #'s for ranging on the pow?
	//answer: there are 27^(3) possible trigrams using lowercase letters and spaces
    std::vector<int> frequencies(length);
	//the frequencies vector will hold all of the frequencies of the trigrams
    
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
        int index = indexa * pow(27.0, 2.0) + indexb * 27 + indexc;  // Is the 27 from the one in the pow assignment? 729? 
		//answer: the "index" (where the frequency will be stored in the vector) is found by taking each of the trigram's chars
		//	ascii code and putting it into a equation like this: for trigram "abc", a * 27^(2) + b * 27 + c
		//	that way, the order of the frequencies in our frequencies vector will always be the same, based on the possible trigrams
		//	(or something like that)
        
        //error here, wrong save to frequencies
        frequencies[index] = frequencies[index] + 1; // Is the double length going to have any involvement down the code?
		//answer: not really, its just so that we have a vector of size 27^(3) filled with zeros to start with.
       
        
    }
    
    return frequencies; // What are we trying to return it as?
	//for this I have it return the vector, with another function printing out the vector so that the output
	//	matches the requirements for milestone 1 (not including the print statements we can get rid of later)
    
}

void printFreq(std::vector<int> frequencies){
    for(unsigned i = 0; i < frequencies.size(); i++){
        std::cout << frequencies[i];
        std::cout << " ";
    }
    
}

int main(int argc, char *argv[]){
	if (argc != 2) {
		std::cerr << "Please provide input with quotation marks surrounding it to test for trigrams" << std::endl;
		exit(EXIT_FAILURE);
	} else {
		std::string testInput = argv[1];
		std::vector<int> frequencies = countTrigrams(testInput);
		printFreq(frequencies);
	}
    
}



