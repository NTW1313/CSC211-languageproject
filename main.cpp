//main.cpp
#include <language.h>
#include <language.cpp>
#include <string>
#include <vector>


int main(int argc, char *argv[]){
	std::vector<language>testfiles;
	if (argc < 2) { //if 2 arguements or less, error
		std::cerr << "Please provide input with quotation marks surrounding it to test for trigrams" << std::endl;
		exit(EXIT_FAILURE);
	} else {
		for(unsigned i = 1; i < argv.length(); i++){
			lang = new language(argv[1]);  // makes a new language object 
			testfiles.append(lang);    // add new language objects to the vector
			
		}
	}
    
}