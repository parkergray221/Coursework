/*
    Parker Gray
    CSC 340 Programming Methodology
    12/7/16
*/

//I used Code::Blocks to implement this assignment.

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "person.h"

class Employee:public Person{
private:
    int employment_year;
    int current_salary;
    int base_salary;
    double *annual_salary_increase_rate; //the dynamic array that will hold the annual salary increase rate is declared as a
    //double pointer (because it can hold decimal values).
    int annual_salary_increase_rate_num; //the number of times that an employee's salary has been increased by a
    //distinct percentage.

public:

    Employee(); //default constructor

    Employee(int new_id, string new_name, int employ_year, int base_sal, int current_sal); //initializes inherited members from person class

    ~Employee(); //destructor

    Employee(const Employee & worker); //copy constructor

    void operator=(const Employee &rhs); //overloaded assignment operator

    //accessors

    int getEmploymentYear();

    int getCurrentSalary();

    int getBaseSalary();

    double getAnnualSalaryIncreaseRate(int position);

    int getAnnualSalaryIncreaseRateNum();

    //mutators

    void setEmploymentYear(int newyear);

    void setCurrentSalary(int newcurrsalary);

    void setBaseSalary(int newbasesalary);

    void setAnnualSalaryIncreaseRateNum(int newquantity);

    void setAnnualSalaryIncreaseRate(int position, double newincreaserate);

    //remaining functions

    friend ostream & operator<<(ostream & outS, const Employee& employee); //friend function output operator

    virtual void output() const;

};

#endif // EMPLOYEE_H_INCLUDED
