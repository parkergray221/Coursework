#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int binSearch(int a[], int n, int x){ //x is the key value we are searching for
    int low = 0; //standard low high and mid variables for binary search
    int high = n-1;
    int mid;
    while (low <= high){ //iterative solution for key finding
        mid = (low + high) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        (a[mid] > x) ? high = mid - 1 : low = mid + 1; //if a[mid] is greater then x then make (mid - 1) the new high. otherwise
    } // make mid + 1 the new low.
}

int binSearchRecursive(int a[], int n, int x){
    int low = 0;
    int high = n-1;
    int mid;
    if (low > high) //useful check for recursive bin search
    {
        return 0;
    }
    else
    {
        mid = (low + high) / 2;
        if (x == a[mid])
        {
            return mid;
        }
        else if (x < a[mid])
        {
            return binSearchRecursive(a, mid, x);
        }
        else
        {
            return bsr(a, mid + 2, x);
        }
    }
}

int main(){
    int n = 1000000, K = 1;
    int a[n];
    for (int i = 0; i < n; i++){a[i] = i;} //fill array
    //binary search recursive
    for (int i = 0; i < n; i++){if (binSearch(a,n,i) != i){cout << "\nERROR";}}
    //binary search iterative
    for (int i = 0; i < n; i++){if (binSearchRecursive(a,n,i) != i){cout << "\nERROR";}}
}
