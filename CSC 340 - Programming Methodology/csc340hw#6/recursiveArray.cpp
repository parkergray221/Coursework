/*
	Parker Gray
	CSC 340 Programming Methodology Section #01
	10/26/16like
*/

#include "recursiveArray.h"

//initialization segment

recursiveArray::recursiveArray()
{
    (*this).n = 100;
    (*this).x = 0;
    for(int i = 0; i < n; i++){
        (*this).myarray[i] = 0;
    }
}

/*
    For a majority of these following functions, the user has to enter the range of indexes they would like to utilize in the
    array as arguments firstindex and lastindex. If the user wants to use these functions with respect to all indexes in the
    array, they must know the size of the array ahead of time and have 0 be the value for firstindex and the size of the array
    as the lastindex value. This is perhaps not the most intuitive way of doing things (the user will often want to run the
    function to get the whole array's values without having to enter index arguments, but as far as I am aware it's impossible
    for me to make a default case based on whether the user enters an argument or not), however it is the best way to
    solve certain problems involved with implementing some of these functions that I experienced.
*/

void recursiveArray::printArrayBackwards(int firstindex, int lastindex) const
{
    if(firstindex <= lastindex){ //If the number that describes the lastindex (eg the 9 in myarray[9]) is greater than the number that describes the first index (eg the 0 in myarray[0]), then....
        cout << (*this).myarray[lastindex]; //print the value of myarray at lastindex.

        printArrayBackwards(firstindex, lastindex - 1); //then call the function again, this time with the lastindex being 8, following from the initial example in line 29.
    }   //Eventually, all values will be printed, starting from the lastindex given in the argument of the function.
}

pair<int, int> recursiveArray::largestNum(int firstindex, int lastindex) const
{
    pair<int, int> returnValue (0, 0); //returnValue is a std::pair type that will be used to return both the index of the array that holds the largest number and the largest number itself.
    if (firstindex == lastindex){ //If the indexes we which to search are equal, as in firstindex is zero and lastindex is also zero, then...
        returnValue.first = firstindex; //Simply return the firstindex and the value at firstindex.
        returnValue.second = ((*this).myarray[firstindex]); //Whenever we find the largest number, we set returnValue's contents to be the largest number and the largest number's index.
        return returnValue;
    }
    pair<int, int> largestNumber = largestNum(firstindex, lastindex-1); //Call largestNum again with new parameters.
    if((*this).myarray[lastindex - 1] > largestNumber.first){ //If lastindex - 1 is greater than largestNumber, then...
            returnValue.first = lastindex - 1;
            returnValue.second = ((*this).myarray[lastindex - 1]);
            return returnValue; //Return the largest number and its index.
        }else{ //If lastindex - 1 isn't bigger, then largestNumber must be bigger.
            returnValue.first = largestNumber.first;
            returnValue.second = largestNumber.second;
            return returnValue;
        }
}

int recursiveArray::partitionArray(int firstindex, int lastindex) //This partitionArray function is from slide 16 in Professor Yang's powerpoint on recursion.
{
    int x = (*this).myarray[lastindex];
    int i = firstindex - 1;
    for(int j = firstindex; j < lastindex - 1; j++){
        if ((*this).myarray[j] <= x){
        i = i + 1;
        int temp = (*this).myarray[i];
        (*this).myarray[i] = (*this).myarray[j];
        (*this).myarray[j] = temp;
        }
    }
    int temp1 = (*this).myarray[i+1];
    (*this).myarray[i+1] = (*this).myarray[lastindex];
    (*this).myarray[lastindex] = temp1;
    return i + 1;
}

int recursiveArray::kthSmallestNum(int firstindex, int lastindex, int k)
{
     //If the k value given is both greater than or equal to the firstindex of the array and less than or equal to the lastindex of the array, we know we can solve for the kth smallest number.
        int pivotIndex = firstindex;
        int pivot = (*this).myarray[firstindex];
        partitionArray(firstindex, lastindex);

        if(k < pivotIndex - firstindex + 1){ //If k is less than our pivot value - the first index of the array + 1 (the + 1 accounts for the fact that the size of an array, eg 50, counts from 0 to 49)...
            return kthSmallestNum(firstindex, pivotIndex - 1,  k); //we return kthsmallest num with a new value for lastindex, pivot - 1.
        } else if (k == pivotIndex - firstindex + 1){ //If k is exactly equal to the pivot value - firstindex + 1, then the pivot must be the kth value. This is our base case, so we eventually reach it.
            return pivot;
        } else {
            return kthSmallestNum(pivotIndex + 1, lastindex, k - (pivotIndex - firstindex + 1)); //Otherwise, the kth value must be in the 'upper half' of the array, so we set firstindex to a new value of pivot + 1 to search the top half.
        }
}

recursiveArray recursiveArray::setArray()
{
    cout << "How many values will be inside of your array?\n";
    cin >> (*this).n;
    cout << "Please provide a list of integers separated by spaces equal to the size number you just typed in. \n";
    for(int i = 0; i < (*this).n; i++){
        cin >> (*this).myarray[i];
        cout << "The " << i << "th value has been set.\n";
    }
}

void recursiveArray::quickSort(int firstindex, int lastindex)
{
    int lowerbound = firstindex; //Create separate intergers to hold the initial values of firstindex and lastindex.
    int upperbound = lastindex;
    int temp; //Create a temp varaible for swapping later.
    int pivot = (*this).myarray[(lowerbound+upperbound)/2]; //Create a pivot at the midpoint of the array.
    while(lowerbound <= upperbound){ //While lowerbound is less than or equal to upperbound...
        while((*this).myarray[lowerbound] < pivot){ //Check various inequalities involving the pivot (middle) value.
            lowerbound++; //If lowerbound's current checked value is less than the pivot, it's in the correct spot. Iterate lowerbound.
        }
        while((*this).myarray[upperbound] > pivot){ //If the value at upperbound is larger than the pivot, that value is in the correct place.
            upperbound--; //Negatively iterate upperbound.
        }
        if(lowerbound <= upperbound){ //If lowerbound is less than or equal to upperbound,
            temp = (*this).myarray[lowerbound]; //Switch the values that are located at lower and upper bound.
            (*this).myarray[lowerbound] = (*this).myarray[upperbound];
            (*this).myarray[upperbound] = temp;
            lowerbound++; //And iterate them both.
            upperbound--;
        }
    }
    if(firstindex < upperbound){ //Recursive portion. If firstindex is less than upperbound
        quickSort(firstindex, upperbound); //Run quicksort with new parameters.
    }
    if(lastindex > lowerbound){ //If lastindex is greater than lowerbound,
        quickSort(lowerbound, lastindex); //Run quicksort with new parameters.
    }
}

ostream& operator<<(ostream& outS, recursiveArray& array1)
{
    if(array1.x >= 0 && array1.x < 5){ //Normally, array1.x would be compared to 100, the size of the array. However, in my test.cpp, I'm only concerned with the 5 values I place into the default array with setArray(). Hence, I have array1.x iterate to 5 here.
        outS << array1.myarray[array1.x]; //Print out the x'th index.
        array1.x = array1.x + 1; //Iterate x.
        outS << array1; //Print out the remainder of the array, so long as array1 is not 5. This recursively prints out all remaining values in the 0-5 range.
    }
    array1.x = 0; //Reset x after all printing.
    return outS;
}
