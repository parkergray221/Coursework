//File name--student.h: declare Student as a derived class of Person
#ifndef _STUDENT_H
#define _STUDENT_H

#include "person.h"

class Student:public Person
{
      public:
         ~Student(); //destructor
         Student(); //default: 1->level, 0->num_grades, NULL->grades
         Student(int new_id, string new_name, DayOfYear date, int lvl ); //lvl->level, 0->num_grades, NULL->grades
         Student(const Student& std); //copy constructor: std -->*this
         void operator=(const Student& rhs); //rhs --> *this 
         int get_level() const; //return level
         int get_num_grades() const; //return num_grades
         double get_grade(int i) const; //return grades[i]
         void set_level(int lvl); //lvl-->level
         void set_num_grades( int num); //num->num_grades, allocate memory to *grades
         void set_grade(int i, double grd); //grd --> grades[i]
      
         friend ostream & operator <<( ostream & out, const Student& std);
         virtual void output() const; //print out a student's info.
      private:
         int level; //1-4: freshmen, sophomore, junior and senior
         int num_grades;
         double *grades; 
};

#endif //_STUDENT_H
