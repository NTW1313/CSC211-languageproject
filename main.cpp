//main.cpp

#include "language.h"
#include <string>
#include <vector>
#include <iostream>
#include <math.h>


int main(int argc, char *argv[]){
	std::vector<language>testfiles;

	if (argc < 2) { //if 2 arguements or less, error
		std::cerr << "Please provide input with quotation marks surrounding it to test for trigrams" << std::endl;
		exit(EXIT_FAILURE);
	} else {
		for(int i = 1; i < argc; i++){
			language lang = language((std::string)argv[i]);
			lang = lang.countTrigrams();
			testfiles.push_back(lang);    // add new language objects to the vector
			
		}
		
		std::vector<double> similarities;
		int testindex = testfiles.size() - 1;
		double len = pow(27.0, 3.0);
		std::vector<int> a = testfiles[testindex].getFrequencies();
		//test similarity of the frequencies
		for(int j = 0; j < testfiles.size() - 1; j++){
			std::vector<int> b = testfiles[j].getFrequencies();
			double num;
			double denom1;
			double denom2;
			for(unsigned i = 0; i < len; i ++){
				num += (a[i] * b[i]);
				denom1 += (a[i] * a[i]);
				denom2 += (b[i] * b[i]);
			}
			// the formular for cosine theta 
			double fin = num / sqrt(denom1)*sqrt(denom2);
			// Adds to the vector
			similarities.append(fin);
			
		}
		
	}
    
	
}

//cosine similarity function
//double cos (double x);


