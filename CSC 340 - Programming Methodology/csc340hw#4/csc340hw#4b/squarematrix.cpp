/*
	Parker Gray
	CSC 340 Programming Methodology Section #01
	10/6/16
*/

#include "squarematrix.h"

//initialization segment

SquareMatrix::SquareMatrix():matrix(10, vector <double> (10))
{
    numofcolsrows = 10;
    vector < vector<double> > m1(numofcolsrows, vector <double> (numofcolsrows)); //creates a 2d matrix called m1 that has 10 columns and 10 rows
    for(int i = 0; i < numofcolsrows; i++){
        for(int j = 0; j < numofcolsrows; j++){
            m1.at(i).at(j) = 0.0;
        }
    }
}

SquareMatrix::SquareMatrix(vector <vector<double> > v2d )
{
    int counterrow = 0;
    int countercol = 0;
    for(int i = 0; i < v2d.size(); i++){ //each time we encounter a new row....
            counterrow++; //increment our row counter by one.
        for(int j = 0; j < v2d[i].size(); j++){ //each time we encounter a new column....
            countercol++; //increment our column counter by one.
        }
    }
    if(counterrow == countercol){ //if v2d's # of rows and columns are the same....
        vector <vector<double> > m1 (v2d); //set m1's values to be v2d's. (and thus m1's size to be v2d's as well)
    }
}

double SquareMatrix::getValue(int i, int j) const
{
    return (*this).matrix.at(i).at(j);
}

void SquareMatrix::setValue(int i, int j, double value)
{
    (*this).matrix.at(i).at(j)= value;
}


void SquareMatrix::resizeMatrix(int newSize)
{
    if((*this).numofcolsrows < newSize){ //because any SquareMatrix is going to have size (numofcolsrows)^2, a hypothetical newsize value that the users enters, ie 4, has to be squared in order to find its appropriate value for a resultant SquareMatrix object, ie 4x4.
        (*this).numofcolsrows = newSize; //Expands the calling squareMatrix to newSize
        for(int i = 0; i < (*this).numofcolsrows; i++){
            for(int j = 0; j < (*this).numofcolsrows; j++){
                if((*this).matrix.at(i).at(j) == NULL){ //If index at [i][j] has no value assigned to it (it's a new index added after changing the num of cols and rows to new size
                    setValue(i, j, 0.0); //then put a 0 there.
                }
            }
        }
    }

    if((*this).numofcolsrows > newSize){
        (*this).numofcolsrows = newSize; //Contracts the calling squareMatrix to newSize
        for(int i = 0; i < (*this).numofcolsrows; i++){
            for(int j = 0; j < (*this).numofcolsrows; j++){
                if((*this).matrix.at(i).at(j)!= NULL && (*this).matrix.at(i).at(j) > newSize){ //if the value of [i][j] does exist and [i][j] is outside the bounds of the newSize of our vector....
                    (*this).matrix.pop_back(); //delete the value at [i][j]
                }
            }
        }
    }
}

/*
    Matrix multiplication works like so- first row of the left hand side is multiplied by the first column of the right hand side.
    Then, first row of the left hand side matrix matrix times the second column of the right hand side, and so on.
    Given a phrase [a b] * [e f] = ?
                   [c d]   [g h]
    the first term of the resultant vector will be [(a*e) + (b*g)].
    To make matrix multiplication work, we have to keep track of the column and row that we're in when solving for each term. To this end,
    I've incorporated three for loops. The first two loops are for the purpose are making certain that we are in the correct row and column per term.
    The last loop (which uses k as its interger) is to make certain that we get the correct final value to insert into the resultant matrix. To explain further, I'll use
    this example again:
    [a b] * [e f] = ?
    [c d]   [g h]
    We know that the first top left term of the resultant vector will be [(a*e) + (b*g)]. k is here to move our multiplication to (b*g) after solving for (a*e) initially.
    That is k's purpose. Following the calculation, we set the first term of our resultant matrix m3 to the tempValue that we find by following matrix multiplication rules.
    And then we reset our tempValue to 0, and start the evaluation of the second term for the resultant matrix. I hope this is intuitive enough for you after reading the explanation.
*/

SquareMatrix SquareMatrix::operator*(const SquareMatrix& m2) const{

    SquareMatrix m3;
    m3.resizeMatrix(m2.matrix.size());
    double tempVal;
    if((*this).numofcolsrows == m2.numofcolsrows){
        for(int i = 0; i < (*this).numofcolsrows; i++){
            for(int j = 0; j < (*this).numofcolsrows; j++){
                for(int k = 0; k < (*this).numofcolsrows; k++){
                tempVal += (*this).matrix.at(i).at(k) * m2.matrix.at(k).at(j);
                }
                m3.matrix.at(i).at(j)= tempVal;
                tempVal = 0;
            }
        }
    }
    return m3;
}

SquareMatrix SquareMatrix::operator*(double scalar) const{

    SquareMatrix m3;
    m3.resizeMatrix((*this).matrix.size());
        for(int i = 0; i < (*this).numofcolsrows; i++){
            for(int j = 0; j < (*this).numofcolsrows; j++){
                m3.matrix.at(i).at(j) = (*this).matrix.at(i).at(j) * scalar;
            }
        }
    return m3;
}

SquareMatrix SquareMatrix::operator-(const SquareMatrix& m2) const{

    SquareMatrix m3;
    m3.resizeMatrix(m2.matrix.size());
        if((*this).numofcolsrows == m2.numofcolsrows){
        for(int i = 0; i < (*this).numofcolsrows; i++){
            for(int j = 0; j < (*this).numofcolsrows; j++){
                m3.matrix.at(i).at(j) = (*this).matrix.at(i).at(j) - m2.matrix.at(i).at(j);
            }
        }
    }
    return m3;
}

ostream& operator<<(ostream& outS, const SquareMatrix& m2){
	for(int i = 0; i < m2.numofcolsrows; i++){
            outS << "["; //bracket is placed at start of row
        for(int j = 0; j < m2.numofcolsrows; j++){
            outS << m2.matrix.at(i).at(j) << " "; // prints all elements in that row as the for loop iterates through the row
        }
        outS << "]" << endl; //end bracket placed after all row's elements have been printed.
	}
    return outS;
}
