#include "language.h"
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

/*
	main.cpp
*/

/*
	compareFreq method to compare two languages similarities
	returns the cosine similarity as a double 
*/
double compareFreq(language lang1, language lang2){
	
	double len = pow(27.0, 3.0);
	
	std::vector<int> a = lang1.getFrequencies();
	std::vector<int> b = lang2.getFrequencies();
	
	double num = 0.00; 
	double denom1 = 0.00; 
	double denom2 = 0.00;
	
	for(unsigned i = 0; i < len; i++){
		num += (a[i] * b[i]);
		denom1 += (a[i] * a[i]);
		denom2 += (b[i] * b[i]);
	}
		
	// the formula for cosine
	double fin = num / (sqrt(denom1)*sqrt(denom2));
	
	return fin;
}

/*
	MAIN FUNCTION
*/
int main(int argc, char *argv[]){
	
	//if 2 files or less are provided, error
	if (argc <= 3) {
		std::cerr << "Please provide filenames for language comparison" << std::endl;
		exit(EXIT_FAILURE);
	} 
	else {
		
		//vector to hold the language objects
		std::vector<language>testfiles;
		
		//for loop to make new language objects and store them in a vector
		for(int i = 1; i < argc; i++){
			language lang = language(argv[i]);
			lang = lang.countTrigrams();
			testfiles.push_back(lang);
		}
		
		//vector to hold the cosine similarities of the languages
		std::vector<double> similarities;
		
		//testindex = the index of the test file
		int testindex = testfiles.size() - 1;
		
		//loop to find the cosine similaries of the test file and all other files
		for(int r = 0; r < testindex; r++){
			double fin = compareFreq(testfiles[testindex], testfiles[r]);
			similarities.push_back(fin);
		}
		
		//find the max (the most similar file)
		double max = similarities[0];
		int index;
		
		//loop to find max
		for(unsigned k = 1; k < similarities.size(); k++){
			if(similarities[k] > max){
				max = similarities[k];
				index = k;
			}
		}
		
		//save name of the language with the highest similarity
		std::string sim = testfiles[index].getlangName();
		
		//print the name of the closest language
		std::cout << sim << std::endl;
		
		//end
		return 0;
	}
    
	
}
//end main.cpp


