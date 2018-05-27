/*
	Parker Gray
	CSC 340 Programming Methodology Section #01
	11/10/16
	I am using CodeBlocks to create and compile homework 7.
*/

#ifndef VECTOR_DOUBLE_H_INCLUDED
#define VECTOR_DOUBLE_H_INCLUDED

#include <iostream>

using namespace std;


class vector_double{
    private:
        double *pointer_double;
        int indexesused; //number of doubles stored in pointer_double (number of indexes currently in use).
        int totalcapacity; //number of doubles that COULD be stored in pointer_double. two different quantities.

    public:
        friend ostream& operator<<(ostream& outS, vector_double& pointer);

        vector_double(); //default constructor that takes no args

        //big 3

        ~vector_double(); //destructor
        vector_double(const vector_double& instance); //copy constructor
        vector_double operator=(const vector_double& rhs); //assignment

        //accessors

        int getCapacity(); //returns total capacity the vector could hold.

        bool isEmpty(); //tests if the calling vector is empty, returns a int 1 for true or int 0 for false.

        int sizePointer(); //returns the size of the vector as an integer.

        //mutators

        void insertValue(double value, int position); //inserts given value at the given position of a vector

        void popBack(); //deletes last element of the vector.

        void pushBack(double value); //adds an element to the end of a vector.

        void resizePointer(int newsize); //sets vector to the size given in the argument.

        void shrinkToFit(); //removes excess elements of the vector, sets size to last nonzero or null value of the vector.
};

#endif // VECTOR_DOUBLE_H_INCLUDED
