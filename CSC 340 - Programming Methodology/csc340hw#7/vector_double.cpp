/*
	Parker Gray
	CSC 340 Programming Methodology Section #01
	11/10/16
*/

#include "vector_double.h"

vector_double::~vector_double() //destructor
{
    if(pointer_double != NULL){
        delete [] pointer_double;
        pointer_double = NULL; //reinitialize with default constructor's parameters
        indexesused = 0;
        totalcapacity = 10;
    }
}

vector_double::vector_double() //default constructor
{
    pointer_double = NULL;
    indexesused = 0; //initially, no indexes are being used. have to use pushBack or insert to add values before fiddling with pointer_double in other ways.
    totalcapacity = 10; //can hold 10 doubles
}

vector_double::vector_double(const vector_double& instance) //copy constructor
{
    indexesused = instance.indexesused;
    totalcapacity = instance.totalcapacity;
    pointer_double = new double [totalcapacity]; //try to set pointer_double to a new pointer with a size of the number of used indexes in pointer_double
        for(int i = 0; i < indexesused; i++){
            pointer_double[i] = instance.pointer_double[i]; //set all of pointer_double's indexes to have the same value as the vector_double object instance's pointer_double.
        }
}

vector_double vector_double::operator=(const vector_double& rhs) //assignment operator
{
    if(indexesused > 0){ //if indexes being used is greater than zero
        delete [] pointer_double; //release the old memory that is held by pointer_double
    }
    indexesused = rhs.indexesused; //get the pointer on the right hand side of the = operator's values
    totalcapacity = rhs.totalcapacity;
    if(indexesused <= 0){ //if the new value of indexes used is zero
        pointer_double = NULL; //the pointer_double must be NULL, as it contains no values
    }else{
        try{
            pointer_double = new double [totalcapacity]; //create a new pointer just like the copy constructor function.
        }
        catch (bad_alloc & ba)
        {
            cerr<<"vector_double::vector_double(const vector_double&): " << ba.what() << endl;
        }
        for(int i = 0; i < indexesused; i++){
            pointer_double[i] = rhs.pointer_double[i]; //set the new pointer_double's values to the values on the right hand side of the = operator
        }
    }
    return (*this); //return the result
}


int vector_double::getCapacity()
{
    return totalcapacity; //returns how many numbers could be held inside of pointer_double, ie its capacity.
}

bool vector_double::isEmpty()
{
    if(indexesused == 0){ //is the amount of indexes used empty to begin with?
        return true; //if so, we have no reason to continue. we already know the pointer is empty. it contains no values.
    }else{
        return false;
        }
}

int vector_double::sizePointer()
{
    return indexesused;
}

void vector_double::insertValue(double value, int position) //below a lot of code is commented out. this is because when i had this code active the insertValue did not work properly.
{
    if(indexesused == totalcapacity){ //check if pointer_double is contiguous
        indexesused++; //rather than having to set each future temppointer as temppointer = new double [indexesused + 1], I iterate indexesused immediately to avoid repetition.
            double * temppointer = new double [indexesused];
            for(int i = 0; i < position; i++){ //move all values at position or greater than position to the right by one.
                temppointer[i] = pointer_double[i]; //this moves all indexes at index i up one value.
            }
            temppointer[position] = value;
            for(int i = position+1; i < indexesused; i++){ //move all values at position or greater than position to the right by one.
                temppointer[i] = pointer_double[i-1]; //this moves all indexes at index i up one value.
            }
            delete [] pointer_double;
            pointer_double = temppointer;
    }else{ //if pointer_double is not contiguous, resize the pointer_double such that it is contiguous
        resizePointer(indexesused); //resizes the capacity of the calling pointer to be equal to indexesused, ie it allows indexesused to equal totalcapacity and pass the above if statement.
        insertValue(value, position); //then run insertValue again with the same parameters.
    }
}

void vector_double::popBack()
{
    indexesused--;
    double * temppointer = new double [indexesused]; //create a new pointer with capacity that is one less than the currently amount of values held in indexes
    for(int i = 0; i < indexesused; i++){
        temppointer[i] = pointer_double[i];
        }
    delete [] pointer_double;
    pointer_double = temppointer;
}

void vector_double::pushBack(double value)
{
    double * temppointer = new double [indexesused + 1]; //if a pointer holds 2 indexes currently, create a new pointer that holds 3 capacity in total
    for(int i = 0; i < indexesused; i++){
            temppointer[i] = pointer_double[i];
        }
    temppointer[indexesused] = value;
    delete [] pointer_double;
    pointer_double = temppointer;
    indexesused++;
}

void vector_double::resizePointer(int newsize)
{
    if(newsize < indexesused){ //if there exist values outside of newsize's integer in the current pointer_double
        double * temppointer = new double [newsize]; //create a temporary pointer with capacity of newsize
            for(int i = 0; i < newsize; i++){
                temppointer[i] = pointer_double[i]; //apply pointer_double's values to temppointer
            }
            delete [] pointer_double;
            pointer_double = temppointer; //after completing temppointer, set pointer_double to point to temppointer
            indexesused = newsize; //the amount of indexesused is now equal to the newsize of the pointer_double
            totalcapacity = newsize;
        }else{
        totalcapacity = newsize; //totalcapacity does not need 'trimming' because newsize is either greater or equal to it.
    }
}

void vector_double::shrinkToFit()
{
    resizePointer(indexesused); //use resizePointer to take care of the shrinking
}

ostream& operator<<(ostream& outS, vector_double& pointer){
    for(int i = 0; i < pointer.indexesused; i++){
        outS << pointer.pointer_double[i] << " ";
    }
    return outS;
}
