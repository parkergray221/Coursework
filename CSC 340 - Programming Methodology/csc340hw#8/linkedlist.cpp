/*
    Parker Gray
    CSC 340 Programming Methodology Section 01
    11/21/16
*/

#include "linkedlist.h"

using namespace std;

linkedlist::linkedlist() //default constructor
{
    n = 0; //contains no values
    head = NULL;
}

linkedlist::linkedlist(const linkedlist& instance) //copy constructor
{
    if(instance.head == NULL){ //if the linkedlist we're copying is blank...
        head == NULL; //set the destination linkedlist object to also be blank.
        n = 0;
    }else{
        try{
        head = new Node;
        }catch (bad_alloc & ba){
        cerr<<"linkedlist::linkedlist(const linkedlist& instance)" << ba.what() << endl;
        }
        head->item = instance.head->item;

        Node *newptr = head;
        for(Node *initptr = instance.head->next; initptr != NULL; initptr = initptr->next){
            try{
            newptr->next = new Node; //create a new node.
            }catch (bad_alloc & ba){
                cerr<<"linkedlist::linkedlist(const linkedlist& instance): " << ba.what() << endl;
            }
            newptr = newptr->next; //enter that new node.
            newptr->item = initptr->item; //set that node's item to be initptr's item.
        }
        newptr->next = NULL;
    }
}

linkedlist linkedlist::operator=(const linkedlist& rhs) //overloaded assignment operator
{
    if(n > 0){
        Node* current = head;
        while(current != NULL){ //we wish to remove the old memory used by the left hand side's linkedlist and
            head = current->next; //create a new linkedlist object for the left hand side that is identical to right hand side.
            delete current;
            current = head;
        } //once current reaches the end of lhs, lhs's memory space will simply be null.
    } //now we have to reconstruct lhs to be identical to rhs.
        n = rhs.n; //give the left hand side rhs's size.
        Node *newptr = head; //create a Node newptr that is lhs' head.
        for(Node *initptr = rhs.head->next; initptr != NULL; initptr = initptr->next){ //from here, repeat of copy constructor's code.
            try{
            newptr->next = new Node; //create a new node.
            }catch (bad_alloc & ba){
                cerr<<"linkedlist::operator=(const linkedlist& rhs)" << ba.what() << endl;
            }
            newptr = newptr->next; //enter that new node.
            newptr->item = initptr->item; //set that node's item to be initptr's item.
        }
        newptr->next = NULL;
        return *this;
}

linkedlist::~linkedlist() //destructor
{
    Node *current = head; //start at the head node.
    while(current != NULL){
        head = current->next;
        delete current; //delete the current node after iterating once.
        current = head;
    }
}

bool linkedlist::existingValueCheck(int value)
{
    Node *current = head;
    while(current != NULL){ //iterate through whole linked list
        if(current->item == value){ //does the Node that current is at hold the value we seek?
            return true; //if so, return true.
        }
        current = current->next; //if not, iterate forward and check the next node.
    }
    return false;
}


int linkedlist::sizeCheck()
{
    return n;
}

void linkedlist::insertValueAtFront(int value)
{
    try{
    Node *newPtr = new Node; //create a new Node struct called newPtr.
    }catch (bad_alloc & ba){
        cerr<<"linkedlist::insertValueAtFront(int value): " << ba.what() << endl;
    }
    newPtr->item = value; //newPtr's item variable contains the value we wish to insert at the front of the linked list.
    newPtr->next = head; //we then set newPtr's next variable to equal the current head. ie, head -> [1][next] <- [value][next] where [value][next] is our desired new node.
    head = newPtr; //then, we set the head to be newPtr. in the example on the above line, [1][next] would be pushed back one space.
    n++; //iterate size, as we added a new node to the existing list.
}

void linkedlist::deleteValue(int position)
{
    Node *current = head; //start at the head as usual.
    int currposition = 1; //create an interger that will keep track of our position as we iterate through the linkedlist.
    if(position = 1){ //if the position we wish to delete is the node at head.....
            head = head->next; //set the head to be the next node.
            delete current; //delete the head node.
    } //if the above condition isn't true, the position we wish to delete must be partway through the linkedlist.
    while(currposition != n){ //while currposition hasn't iterated all the way through the list....
        if(currposition == position-1){ //if currposition's current value is one less than position's value...
            Node *currentplusone = current->next;
            Node *currentplustwo = currentplusone->next; //we create a variable that points two nodes ahead of current.
            current->next = currentplustwo; //then we set the next value of current to be pointing to currentplus two.
            delete currentplusone; //delete the node at position!
        } //otherwise iterate both our node and our currposition variable.
        current = current->next;
        currposition++;
    }
}

void linkedlist::reverseList()
{
    Node *previous = NULL;
    Node *current = head;
    Node *nextnode;
        while(current != NULL){
            nextnode = current->next; //set nextnode to be current's next value.
            current->next = previous; //set current's next value to point to the previous node.
            previous = current; //then set previous to be the current node.
            current = nextnode; //then move current to be the next node.
        }
        head = previous; //finally, set previous to be the head node.
}

ostream& operator<<(ostream& outS, linkedlist& instance)
{
    outS << "head -> ";
    linkedlist::Node *current;
    current = instance.head;
    while(current->next != NULL){
            outS << "[";
            outS << current->item;
            outS << "][>] -> ";
            current = current->next;
        } //output looks like "head -> [value][>] -> .... -> [value][>] -> NULL
        outS << "[";
        outS << current->item;
        outS << "][>] -> ";
        outS << "NULL" << endl;
        return outS;
}


