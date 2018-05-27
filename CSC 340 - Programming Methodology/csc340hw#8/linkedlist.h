/*
    Parker Gray
    CSC 340 Programming Methodology Section 01
    11/21/16
    I used Code::Blocks to create and compile this assignment.
*/

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>

using namespace std;

class linkedlist{

private:
    struct Node{ //a struct that contains an interger item and a pointer that points to the following node in the linked list
        int item;
        Node *next; //points to the following node
    };
    int n; //size variable. i use n because code::blocks has the name 'size' as a keyword. using 'size' causes me some errors.
    Node *head; //starting node

public:
    friend ostream& operator<<(ostream& outS, linkedlist& instance); //overloaded output operator that is a friend.

    linkedlist(); //default constructor

    //big 3

    linkedlist(const linkedlist& instance); //copy constructor

    linkedlist operator=(const linkedlist& rhs); //overloaded assignment operator

    ~linkedlist(); //destructor

    //accessors

    bool existingValueCheck(int value); //verifies if a value is inside of the list already

    int sizeCheck(); //returns the size of the linked list

    //mutators

    void insertValueAtFront(int value); //inserts a value at the front of the linked list

    void deleteValue(int position); //deletes a number from the linked list at the specified position in argument.

    void reverseList(); //reverses the linked list such that the last value becomes the first value and vice versa.

};

#endif // LINKEDLIST_H_INCLUDED
