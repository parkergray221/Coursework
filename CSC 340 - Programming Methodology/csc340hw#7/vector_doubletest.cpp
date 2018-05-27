/*
	Parker Gray
	CSC 340 Programming Methodology Section #01
	11/10/16
*/

#include "vector_double.h"

int main()
{
    vector_double v1;
    v1.pushBack(1.1); //place 1.1 at the front of v1, its 0th index. still have 9 spaces that could be filled
    v1.resizePointer(1); //resize pointer to have a size of 1, ie v1 is [1.1] with no following indices displayed
    cout << "Default constructor, pushBack, resizePointer check:" << endl;
    cout << v1 << endl; //should return 1.1 only
    vector_double v2(v1); //test copy constructor
    cout << "Copy constructor check:" << endl;
    cout << v2 << endl; //check to see if v2 correctly copies v1, should also return 1.1
    vector_double v3;
    v3.pushBack(1.1); // [1.1]
    v3.pushBack(2.2); // [1.1][2.2]
    v3.pushBack(3.3); // [1.1][2.2][3.3]
    cout << "Pointer size check:" << endl;
    cout << v3.sizePointer() << endl;
    cout << "Pointer capacity check:" << endl;
    cout << v3.getCapacity() << endl;
    vector_double v4 = v3; //test assignment operator
    cout << "Assignment operator check:" << endl;
    cout << v4 << endl; // should return 1.1 2.2 3.3
    cout << "resizePointer check:" << endl;
    v4.resizePointer(2);
    cout << v4 << endl; //should return 1.1 2.2
    v3.insertValue(0.0, 2);
    cout << "insertValue check for case where value inserted is between the first and last point of the pointer:" << endl;
    cout << v3 << endl; //should return 1.1 2.2 0.0 3.3
    v3.insertValue(0.1, 0);
    cout << "insertValue check for case where value inserted is at first point of pointer:" << endl;
    cout << v3 << endl; //should return 0.1 1.1 2.2 0.0 3.3
    v3.insertValue(0.2, 5);
    cout << "insertValue check for case where value inserted is at last point of pointer:" << endl;
    cout << v3 << endl; //should return 0.1 1.1 2.2 0.0 3.3 0.2
    v3.popBack();
    cout << "popBack check:" << endl;
    cout << v3 << endl; //should return 0.1 1.1 2.2 0.0 3.3
    vector_double v5;
    v5.pushBack(0.0); //[0.0][][][][][][][][][], indexesused = 1. totalcapacity = 10.
    v5.shrinkToFit(); //set capacity to 1, same as indexesused.
    cout << "shrinkToFit check:" << endl;
    cout << v5 << endl; //should return 0.0 only.
}
