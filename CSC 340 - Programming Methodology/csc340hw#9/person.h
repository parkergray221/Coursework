/*
    Parker Gray
    CSC 340 Programming Methodology
    12/7/16
*/

/*
    I used Code::Blocks to implement this assignment. Please note that the Person class below and its implementation
    is taken from Professor Yang's work posted on iLearn. I've removed references to dayOfYear.h, as it is not required for the
    assignment.
*/

#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Person{
      public:
            //equalID() returns true:have the same ID; false: otherwise
            friend bool equalID(const Person & person1, const Person &Person2);//
            ~Person(); //destructor: to release any memory that has been allocated to the object
            Person(); //default constructor: id=-1, name="NA", birthday="1/1/2000"
            Person( int new_id, string new_name); //constructor that initializes
                            //id to new_id, name to new_name, and birthday to date
            Person(const Person & someone); //copy constructor: construct a new object as a copy of "someone"
            void operator= (const Person &rhs); //assign the object on the right-hand-side to the left-hand-side
            virtual void output() const; //print out a person's info.
            int get_id() const; //return the id of a Person object
            string get_name() const; //return the name of a Person object
            string getEmail( int i) const; //return the i-th email if exists; o.w: return "NA"
            void set_id(int new_id); //change a person's id to new_id
            void set_name(string new_name); // change a person's name to new_name
            void add_email( string the_email); //add the_email to the list
            int  get_num_emails() const;
      private:
              int id;
              string name;
              string *emails; //list of email addresses
              int numEmails;
};

void print( const Person& someone);  //print out a person's id and name
bool sameID(const Person& person1, const Person& person2);//true:have the same ID; false: otherwise
//search whether there exists a student on the employeeList with id=key
bool searchStudent( Person *employeeList, int num_employees, int key);

#endif // PERSON_H_INCLUDED
