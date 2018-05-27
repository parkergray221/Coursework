/*
    Parker Gray
    CSC 340 Programming Methodology Section 01
    11/21/16
*/

#include "linkedlist.h"

int main(){
    linkedlist l1;
    l1.insertValueAtFront(1);
    l1.insertValueAtFront(0);
    cout << "Default constructor check/Value insertion at front check:" << endl;
    cout << l1 << endl; //this returns head -> [0][>] -> [1][>] -> NULL.
    linkedlist l2;
    l2.insertValueAtFront(2);
    l2.insertValueAtFront(1);
    l2.insertValueAtFront(0);
    linkedlist l3(l2);
    cout << "Copy constructor check:" << endl;
    cout << l3 << endl;
    linkedlist l4 = l1;
    cout << "Assignment operator check:" << endl;
    cout << l4 << endl;
    cout << "Existing value check:" << endl;
    cout << l1.existingValueCheck(1) << endl; //should return 1 for true
    cout << l1.existingValueCheck(5) << endl; //should return 0 for false
    cout << "Size return check:" << endl;
    cout << l1.sizeCheck() << endl;
    l2.deleteValue(2); //deletes the Node that contains 0 in l2, ie the second node (first node after head)
    cout << "Delete a value check:" << endl;
    cout << l2 << endl;
    l3.reverseList();
    cout << "Reverse list check:" << endl;
    cout << l3 << endl; //returns head -> [2][>] -> [1][>] -> [0][>] -> NULL
}
