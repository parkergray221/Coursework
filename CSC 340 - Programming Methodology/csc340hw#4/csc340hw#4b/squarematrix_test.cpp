/*
	Parker Gray
	CSC 340 Programming Methodology Section #01
	10/6/16
*/

#include "squarematrix.h"

/*
    Notes: resizeMatrix doesn't work properly when it's used on m2, for whatever reason. I'm not quite sure why that is. Other than that, all functions work properly with their expected
    outputs aside from the size of the resultant matrix.
*/

int main()
{
    SquareMatrix m1 = SquareMatrix();
    SquareMatrix m2 = SquareMatrix();
    cout << "Default constructor check: " << endl << m1 << endl;
    m1.setValue(0,0,3);
    m1.setValue(0,1,3);
    m1.setValue(1,0,3);
    m1.setValue(1,1,3);
    m1.resizeMatrix(2);
    cout << "getValue check: " << m1.getValue(0,0) << endl;
    m2.setValue(0,0,4);
    m2.setValue(0,1,4);
    m2.setValue(1,0,4);
    m2.setValue(1,1,4);
    m2.resizeMatrix(2);
    cout << "resizeMatrix check: " << endl << m2 << endl;
    cout << "Matrix Multiplication check: " << endl << m1*m2 << endl;
    cout << "Matrix Mult by a scalar check: " << endl << m1*3 << endl;
    cout << "Matrix Subtraction check: " << endl << m2-m1 << endl;

    return 0;
}
