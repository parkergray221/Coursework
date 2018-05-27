/*
	CSC 340 Programming Methodology Section 01
	Homework #1
	Parker Gray
    This program checks for the most frequent character that occurs in a paragraph.
*/
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

char getMostFreqLetter(string s){
	
	int frequencyOfMostFrequentCharacter = 0; //frequencyofMostFrequentChar is going to hold the current highest value. 
	int frequencyOfCharacter = 0; //frequencyOfChar is going to hold the frequency of the character that the below loops are currently on.
	char mostFreqCharacter = 'a'; //Stores the character whose value aligns to frequencyofMostFrequentChar.
	
	for(char q = 'a'; q <= 'z'; q++){ //This loop starts at the letter a and goes down to z, while the following loop counts the frequency of the character this loop is currently on.
	
		frequencyOfCharacter = 0; //Setting the frequency to zero after each loop is important to prevent the loop from counting the frequency of the previous character.
		
		for(int i = 0; i < s.length(); i++){ //This nested loop seeks to verify if the current character being viewed in string s is the same as char q in the previous loop, and perform actions if it is.
			
			if(s[i] == q) 
			frequencyOfCharacter++; //If a match with the current character is found, we raise the frequency of character for that specific character.
			
		}
		
		if(frequencyOfCharacter > frequencyOfMostFrequentCharacter){ //Verifies if the number of times char q occurs is higher than the previously recorded highest amount. If it is, change variables accordingly.
				mostFreqCharacter = q;
				frequencyOfMostFrequentCharacter = frequencyOfCharacter;
			}
	}
	return mostFreqCharacter;
}

void strToToken(string s, char delim, vector<string> v){ //I need to have the delim and string vector in the inputs for the method here because it is the most intuitive way in my mind to complete the problem here.

	int i = 0;  //Int i will be holding the position of our currently viewed character in the string.
    int pos = s.find(delim); //Use the string.find command to find the delimiter of our string. String.find creates substrings of elements that it finds, so it will be useful for creating tokens individually.
    
	while (pos != string::npos) { //We push back all elements of the string that are NOT located at delimiter locations.
      v.push_back(s.substr(i, pos-i)); //Create a substring of all the characters found that are not the delimiter character. (i, pos-i) makes sure we can record every character.
      i = ++pos; 
      pos = s.find(delim, pos); 

      if (pos == string::npos) //If we end up encountering a white space, we push back the substring found by s.find thus far. 
         v.push_back(s.substr(i, s.length()));
    }
		
		for( int i = 0; i < v.size(); i++){ //We print out all of the elements found using the above while loop using this for loop.
    		cout << "Found the following tokens: " << v[i] << endl;
	}
}
main(int n){
	string s = "this is a test paragraph";
	cout << "Most frequent character is: " << getMostFreqLetter(s) << endl;
	vector<string> tokens; //This is the vector which we store the tokens found for strToToken.
	strToToken(s, ' ', tokens);
}
