# CSC211-languageproject

1.What small problems do you need to solve?
	Some small problems include recognizing the ASCII character for each character of the trigram, including non-letter characters.
	Another problem would be recognizing if the file input is correct and handling incorrect cases. 
2. How will you solve them?
	
3. What classes, if any, will you create or subclass?
	We'll create a language class that will be an object that includes methods to process the files and do comparisons.
	The language class will have a vector text that will hold the contents from the text files.
	1.What instance variables...? 
	We'll need instance variables:
	<vector> text
	<string> trigram
	Methods:
	std::vector compute(vector text){
	method that takes the language object and returns the frequencies of the trigrams, as a vector
		we'll need a function that goes through the text repeatly counting the trigrams and storing the frequency
	}
	float compare(language L1, language L2){
	method that takes 2 language objects and determines the similarity using cosine
		we'll need a function that computes cosine
	}
	std::vector getText(){
		getter function for the text vector of language
	}
	
4. What files will you need to create? 
	We'll need a language.h file, a language.cpp file, a main.cpp to run tests, and a compile script for making compiling simple.
	
5. For Milestone 1, how will your main() be structured?
	Our main will take the string input, check that the input is correct, use it as a parameter to open an infile stream, and then
	create a new language object with the infile stream as a parameter to the constructor. The language object will handle reading the file,
	and save the file's contents to a vector. The main will then call the compute method of the language class, 
	which will output the frequencies.
	
6. For Milestone 2, how will your main() be structured?
	Our main will take 2 or more arguments, and check that there is 2 or more and that they are correct. Then it will take the first n-1 files, 
	and turn them into language objects. The nth file will also become a language object. It will then call the compute method of each object.
	The main() will then call the compare() method for each n-1 object, comparing it to the nth one. Lastly, it will return whichever object
	had the highest frequency.
	
7. What libaries will you need?
	We'll need the c standard library, string library, the iostream and fstream libraries, and the vector library.
	