#include <iostream>

int maxlen(int a[], int n){
    int storedIndex = a[0];
    int currentTally = 0; //stores the consecutive sequence of numbers in the array we're currently recording.
    int highestTally = 0; //stores the current greatest record of all previous consecutive searches.
    for(int i = 0; i < n; i++){
        if(storedIndex == a[i]){ //check if storedIndex matches the current index.
        currentTally++; //if so, increment tally by one.
        }else{
            if(currentTally > highestTally){ //if the tally of the previous consecutive sequence is greater than highestTally
                highestTally = currentTally; //set highestTally to that sequence.
            }
            currentTally = 0; //then set currentTally to 0 to start the consecutive sequence counting over again.
            storedIndex = a[i]; // and store the next current index to compare with the next index.
        }
    }
    return highestTally;
}


int main()
{
    int n = 10; //array size
    int a[] = {1, 1, 1, 1, 4, 4, 4, 3, 2, 3}; //array of integers with size 10
    std::cout << maxlen(a, n); //should return "4".
}

