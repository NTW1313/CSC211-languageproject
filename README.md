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
	
	
4.