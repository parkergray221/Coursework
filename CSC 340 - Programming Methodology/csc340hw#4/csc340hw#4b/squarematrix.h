/*
	Parker Gray
	CSC 340 Programming Methodology Section #01
	10/6/16
*/

//After some issues with DevC++ compiling this project, I switched over to Code::Blocks. I compiled and ran this project on Code::Blocks specifically. I do not know how it might fare on DevC++,
//but I hope for the best.

#ifndef _SQUAREMATRIX_H
#define _SQUAREMATRIX_H

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class SquareMatrix{
	private:
		vector < vector<double> > matrix;
		int numofcolsrows;

	public:

		//friend function including the << operator
		friend ostream& operator<<(ostream& outS, const SquareMatrix& m2);

		//constructors

		SquareMatrix(); //default constuctor.
		SquareMatrix(vector< vector<double> > v2d ); //2d matrix that is formed from the elements of another matrix

		//accessors (getters)

		double getValue(int i, int j) const; //returns a vector that contains the double value at a certain row & column value.

		//mutators (setters)

		void setValue(int i, int j, double value); //sets the double value at a certain row & column value of the calling vector to a new double of the user's liking.
		void resizeMatrix(int newSize); //returns a new vector of doubles resized to the user's preferred interger.

		//overloaded operators

	    SquareMatrix operator*(const SquareMatrix& m2) const; //multiplies matrices.
		SquareMatrix operator*(double scalar) const; //multiplies a single matrix by a scalar.
    	SquareMatrix operator-(const SquareMatrix& m2) const;
};

#endif
