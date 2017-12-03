//Final Project Milestone 1

#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <iostream>


    
//chars to look for are lowercase a-z, space (' '), and newline ('\n'). 
std::vector<int> countTrigrams(std::string text){//takes a string for milestone 1

    double length = pow(27.0, 3.0); //How did we determine these #'s for ranging on the pow?
    std::vector<int> frequencies(length);
    
    for (int i = 0; i < (int) text.length() - 2; i+=1) {
        std::string trigram = text.substr(i,3);
        std::cout << trigram << std::endl;
        int indexa = trigram[0];
        int indexb = trigram[1];
        int indexc = trigram[2];
        
        int index = indexa * 729 + indexb * 27 + indexc;  // Is the 27 from the one in the pow assignment? 729? 
        std::cout << index << std::endl;
        //error here, wong save to frequencies
        frequencies[index] = frequencies[index] + 1; // Is the double length going to have any involvement down the code?
        //std::cout << frequencies[index] << std::endl;
    }
    
    return frequencies; // What are we trying to return it as?
    
}

void printFreq(std::vector<int> frequencies){
    for(int i = 0; i < frequencies.size(); i++){
        std::cout << frequencies[i];
        std::cout << " ";
    }
    
}

int main(){
    std::string testInput = "this is a test";
    std::vector<int> frequencies = countTrigrams(testInput);
    printFreq(frequencies);
    
}




