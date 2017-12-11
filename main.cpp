//main.cpp

#include "language.h"
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

//cosine similarity function
//double cos (double x);


//method to compare a given language
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

int main(int argc, char *argv[]){
	

	if (argc <= 3) { //if 2 arguements or less, error
		std::cerr << "Please provide filenames for language comparison" << std::endl;
		exit(EXIT_FAILURE);
	} else {
		
		std::vector<language>testfiles;
		//for loop to make new language objects and store them in a vector
		for(int i = 1; i < argc; i++){
			language lang = language(argv[i]);
			lang = lang.countTrigrams();
			testfiles.push_back(lang);
		}
		
		
		//update: that doesnt compile so nevermind
		std::vector<double> similarities;
		int testindex = testfiles.size() - 1;
		for(int r = 0; r < testindex; r++){
			double fin = compareFreq(testfiles[testindex], testfiles[r]);
			similarities.push_back(fin);
		}
		
		//finds the max (the most similar file)
		double max = similarities[0];
		int index;
		for(unsigned k = 1; k < similarities.size(); k++){
			if(similarities[k] > max){
				max = similarities[k];
				index = k;
			}
		}
		
		std::string sim = testfiles[index].getlangName();
		std::cout << sim << std::endl;
		return 0;
	}
    
	
}



