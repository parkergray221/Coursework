#include <iostream>
#include <vector>
using namespace std;

vector <int> reduce(int a[], int n)
{
    int firstLargest = 0;
    int secondLargest = 0;
    int thirdLargest = 0;
    vector<int> reduced_a;
    for(int i = 0; i < n; i++){ //point of this section is to determine what the first second and third largest numbers in vector are
        if(a[i] > firstLargest){
            thirdLargest = secondLargest;
            secondLargest = firstLargest;
            firstLargest = a[i];
        }
        if(a[i] > secondLargest && a[i] < firstLargest){
            thirdLargest = secondLargest;
            secondLargest = a[i];
        }
        if(a[i] > thirdLargest && a[i] < secondLargest){
            thirdLargest = a[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] != firstLargest && a[i] != secondLargest && a[i] != thirdLargest){ //if current index is not equal to one of largest nums
            reduced_a.push_back(a[i]); //include it in the new vector.
        }
    }
    return reduced_a;
}

int main()
{
    int a[] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //contains 10 elements
    int n = sizeof(a)/sizeof(int);
    vector<int> reduced_a = reduce(a, n);
    std::cout << "Reduced array = (";
    for(int i = 0; i < reduced_a.size() - 1; i++){
        std::cout << reduced_a[i] << ", ";
    }
    std::cout << reduced_a[reduced_a.size() - 1] << ") and size of reduced array is " << reduced_a.size();
}
