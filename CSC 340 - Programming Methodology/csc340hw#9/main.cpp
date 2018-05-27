/*
    Parker Gray
    CSC 340 Programming Methodology
    12/7/16
*/

#include "employee.h"

int main()
{
    Person Bob(1, "Bob");
    Employee Bob_Employed(1, "Bob", 2010, 60000, 60000), Bob_Later; //person bob joins the company in 2010 w/ base salary and current salary = 60000

    Person & test = Bob_Employed;

    Bob_Employed.output();
    test.output(); //despite test being a person, it returns employee's output function regardless, because Bob_Employed contains
    //fields related to Employee's class- thus telling the virtual output function in the person class to use the employee version.
    Bob_Employed.Person::output(); //however, this line returns the Person output function successfully for Bob_Employed.

    Bob_Employed.setAnnualSalaryIncreaseRateNum(2); //since arriving in 2010, bob's salary has been increased twice.
    Bob_Employed.setAnnualSalaryIncreaseRate(1, .1); //give Bob a 10% raise on his first year at the company.
    Bob_Employed.setAnnualSalaryIncreaseRate(2, .2); //next year he gets a 20% raise.
    Bob_Employed.setCurrentSalary(79200); //this results in a 60000 * .1 + [(60000 * .1) * .2] result for Bob's current salary.

    Bob_Later = Bob_Employed;
    //operator<< works identically to output() for employee class.
    cout << Bob_Later;

    cout << "The below lines verify the usability of the accessors." << endl;
    cout << Bob_Employed.getBaseSalary() << endl;
    cout << Bob_Employed.getCurrentSalary() << endl;
    cout << Bob_Employed.getAnnualSalaryIncreaseRate(1) << endl; //position '1' in the array is array[0]. i assume that a regular user is not aware of the 0 index being the first position of the array.
    cout << Bob_Employed.getAnnualSalaryIncreaseRateNum() << endl;
    cout << Bob_Employed.getEmploymentYear() << endl;
    Bob.~Person();
    Bob_Employed.~Employee();
}
