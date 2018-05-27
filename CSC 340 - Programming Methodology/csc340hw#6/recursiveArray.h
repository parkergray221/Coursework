/*
	Parker Gray
	CSC 340 Programming Methodology Section #01
	10/26/16
	I am using CodeBlocks to create and compile homework 6.
*/

#ifndef RECURSIVEARRAY_H_INCLUDED
#define RECURSIVEARRAY_H_INCLUDED

#include <iostream>

using namespace std;

class recursiveArray{
    private:
        int x; //used in output operator.
        int n; //n is our size variable for myarray[].
        int myarray[100];
    public:
        friend ostream& operator<<(ostream& outS, recursiveArray& myarray); //start with friend function output operator.

        //constructors

        recursiveArray(); //default constructor

        //accessors

        void printArrayBackwards(int firstindex, int lastindex) const; //prints elements in an array one by one recursively, in a reverse order

        pair<int, int> largestNum(int firstindex, int lastindex) const; //search for largest num in recursiveArray and print it.

        int kthSmallestNum(int firstindex, int lastindex, int k); //search for kth largest num in recursiveArray and print it. kthSmallestInterger is not const because it calls partitionArray to modify the array's contents.

        //mutators

        int partitionArray(int firstindex, int lastindex); //a member function to partition the array from least to greatest

        recursiveArray setArray(); //sets recursive array to user's desired values

        void quickSort(int firstindex, int lastindex); //sorts the recursiveArray using QuickSort algorithm
};

#endif // RECURSIVEARRAY_H_INCLUDED
