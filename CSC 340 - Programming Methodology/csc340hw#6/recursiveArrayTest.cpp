/*
	Parker Gray
	CSC 340 Programming Methodology Section #01
	10/26/16
*/

#include "recursiveArray.h"

int main()
{
    recursiveArray myarray = recursiveArray();
    pair<int, int> returnValue(0, 0);
    cout << "setArray check: " << endl;
    myarray.setArray(); //I always set my size to 5 (ie, 4 indexes from 0 to 4). More manageable that way. I always use the set of numbers 1, 2, 3, 6, 5, in that order. This allows me to check all of my functions accurately.
    cout << "printArrayBackwards check: " << endl;
    myarray.printArrayBackwards(0, 4); //while myarray contains 100 elements of all zeros because it was initialized with the default constructor,, we only really want to be concerned with the 5 entries the user (in this case me) submits above.
    cout << "\nlargestNum check: " << endl;
    returnValue = myarray.largestNum(0, 4);
    cout << "The largest number is " << returnValue.second << " at index " << returnValue.first << endl;
    cout << "kSmallestNum check: " << endl;
    cout << myarray.kthSmallestNum(0, 4, 3) << endl; //Returns the third smallest number.
    cout << "quickSort check and overloaded operator check: " << endl;
    myarray.quickSort(0, 4);
    cout << myarray << endl;
}
