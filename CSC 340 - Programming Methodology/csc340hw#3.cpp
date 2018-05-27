/*
	CSC 340 Programming Methodology Section 01
	Homework #1
	Parker Gray
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void setNumber(){
	
	
};

int main(){
	string filename = "file1.txt"; 
	
	fstream finder; //finder searches through file1.txt when given certain parameters, like seekp and seekg.
	
		finder.open(filename.c_str(), ios::in|ios::out); //as shown in prof yang's C++ basics pdf, this opens the file1.txt and allows us to read and write to the file.
		
	finder.seekg(0, finder.end);
		int numOfInts = finder.tellg(); 
		cout << "The size of file1.txt is: " << numOfInts << endl; //This outputs 49995.
	
	finder.seekg(0, finder.beg); //Return the finder to the beginning of the file after moving to the end in the previous step.
		
		
	
}
