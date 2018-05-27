#include <cstdlib>
#include <iostream>

using namespace std;

int binSearch(int a[], int n, int x){ //x is the key value we are searching for
    int low = 0, high = n-1, mid;
    while (low <= high){ //iterative solution for key finding
        mid = (low + high) / 2;
        if (a[mid] == x) { return mid; }
        (a[mid] > x) ? high = mid - 1 : low = mid + 1; //if a[mid] is greater then x then make (mid - 1) the new high. otherwise
    } // make mid + 1 the new low.
}

int binSearchRecursive(int a[], int first, int n, int x){
   if (first <= n) {
       int mid = (first + n) / 2;  // compute mid point.
       if (x == a[mid])
           return mid;   // found it.
       else if (x < a[mid])
           // Call ourself for the lower part of the array
           return binSearchRecursive(a, first, mid-1, x);
       else
           // Call ourself for the upper part of the array
           return binSearchRecursive(a, mid+1, n, x);
   }
   return -(first + 1);    // failed to find key
}

int main() {
    int n = 100000, K = 500;
    int a[n];
    for (int i = 0; i < n; i++) { a[i] = i; } //fill array
    for(int j = 0; j < K; j++){
            for (int i = 0; i < n; i++) { if (binSearch(a, n, i) != i) { cout << "\nERROR"; }} //bin search iterative
    }
        for (int i = 0; i < n; i++) { if (binSearch(a, n, i) != i) { cout << "\nERROR"; }} //bin search iterative
        //for (int i = 0; i < n; i++) { if (binSearchRecursive(a, 0, n, i) != i) { cout << "\nERROR"; }} // bin search recursive

}

