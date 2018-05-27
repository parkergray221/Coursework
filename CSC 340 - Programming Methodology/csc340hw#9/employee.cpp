/*
    Parker Gray
    CSC 340 Programming Methodology
    12/7/16
*/

#include "employee.h"

Employee::Employee():Person() //default constructor calls the person constructor as well. as an employee is a person.
{
    employment_year = 2010; //assume company was started in 2010. earliest employee's hiring date was 2010.
    current_salary = 60,000; //let the default constructed employee have only just started at the company.
    base_salary = 60,000; //means base salary = current salary.
    annual_salary_increase_rate_num = 0; //default employee hasn't stayed for a year yet, so he can't have any salary increases
    annual_salary_increase_rate = NULL;
}

Employee::Employee(int new_id, string new_name, int employ_year, int base_sal, int current_sal):Person(new_id, new_name),employment_year(employ_year),base_salary(base_sal),current_salary(current_sal),annual_salary_increase_rate_num(0),annual_salary_increase_rate(NULL)
{
    //initialize inherited member in person class for employee class as is done in the
    //student.cpp provided for this homework.
}


Employee::~Employee() //destructor
{
    if(annual_salary_increase_rate != NULL){
        delete [] annual_salary_increase_rate;
    }
}

Employee::Employee(const Employee & worker):Person(worker) //employee's copy constructor calls the person copy constructor .
{
    employment_year = worker.employment_year;
    current_salary = worker.current_salary;
    base_salary = worker.base_salary;
    if(annual_salary_increase_rate_num <= 0){
        annual_salary_increase_rate = NULL;
    }else{
    (*this).annual_salary_increase_rate = new double [worker.annual_salary_increase_rate_num];
    }
    if(annual_salary_increase_rate == NULL){
        cerr<< "Employee:Employee(const Employee &): Memory allocation error\n";
        exit(-1);
    }
    for(int i = 0; i < annual_salary_increase_rate_num; i++){
        annual_salary_increase_rate[i] = worker.annual_salary_increase_rate[i];
    }
}


void Employee::operator=(const Employee & rhs)
{
    (*this).Person::operator=(rhs); //run person's equals operator first.
    employment_year = rhs.employment_year; //set calling object's datafields to be the rhs fields.
    current_salary = rhs.current_salary;
    base_salary = rhs.base_salary;
    if(annual_salary_increase_rate_num != rhs.annual_salary_increase_rate_num){ //modify the pointer if it does not have same size as rhs.
        delete [] annual_salary_increase_rate;
        annual_salary_increase_rate_num = rhs.annual_salary_increase_rate_num;
        annual_salary_increase_rate = new double [annual_salary_increase_rate_num];
    }
    if(annual_salary_increase_rate == NULL){
        cerr<< "Employee:operator=(const Employee &): Memory allocation error\n";
        exit(-1);
    }
    for (int i=0; i<annual_salary_increase_rate_num; i++)
           annual_salary_increase_rate[i] = rhs.annual_salary_increase_rate[i];
}

int Employee::getEmploymentYear()
{
    return employment_year;
}

int Employee::getCurrentSalary()
{
    return current_salary;
}

int Employee::getBaseSalary()
{
    return base_salary;
}

double Employee::getAnnualSalaryIncreaseRate(int position)
{
    if(position < 1 || position > annual_salary_increase_rate_num){ //if position is 'out of bounds'
        cout << "You entered an index number that is non-existent within the pointer of annual_salary_increase_rate.";
        return -1.0;
    }else{
        return annual_salary_increase_rate[position-1]; //otherwise return the grade
    }
}

int Employee::getAnnualSalaryIncreaseRateNum()
{
    return annual_salary_increase_rate_num;
}

void Employee::setEmploymentYear(int newyear)
{
    employment_year = newyear;
}

void Employee::setCurrentSalary(int newcurrsalary)
{
    current_salary = newcurrsalary;
}

void Employee::setBaseSalary(int newbasesalary)
{
    base_salary = newbasesalary;
}

void Employee::setAnnualSalaryIncreaseRateNum(int newquantity)
{
    annual_salary_increase_rate_num = newquantity;
    if(newquantity > 0){
        annual_salary_increase_rate = new double [newquantity];
        if(annual_salary_increase_rate == NULL){
            cerr << "Employee:setAnnualSalaryIncreaseRateNum(int newquantity): Memory allocation error\n";
            exit(-1);
        }
        for(int i = 0; i < newquantity; i++){
            annual_salary_increase_rate[i] = 0;
        }
    }
}

void Employee::setAnnualSalaryIncreaseRate(int position, double newincreaserate)
{
    if(position >=1 || position < annual_salary_increase_rate_num){
        annual_salary_increase_rate[position-1] = newincreaserate;
    }
}

ostream& operator<<(ostream& outS, const Employee& rhs)
{
    outS << "-------------------------------" << endl;
    outS << "ID = " << rhs.get_id() << endl;
    outS << "Name = " << rhs.get_name() << endl;
    outS << "Year hired = " << rhs.employment_year << endl;
    outS << "Starting salary = " << rhs.base_salary << endl;
    outS << "Current salary = " << rhs.current_salary << endl;
    outS << "Number of salary rate changes = " << rhs.annual_salary_increase_rate_num << endl;
        for (int i = 1; i <= rhs.annual_salary_increase_rate_num; i++)
        outS << "annual_salary_increase_rate[year " << i <<"]=" << rhs.annual_salary_increase_rate[i-1] <<" ";
    outS <<endl;
    outS << "-------------------------------\n" << endl;

    return outS;
}

void Employee::output() const
{
    cout << "-------------------------------" << endl;
    cout << "Person ID = " << get_id() << endl;
    cout << "Name = " << get_name() << endl;
    cout << "Year hired = " << employment_year << endl;
    cout << "Starting salary = " << base_salary << endl;
    cout << "Current salary = " << current_salary << endl;
    cout << "Number of salary rate changes = " << annual_salary_increase_rate_num << endl;
        for (int i = 1; i<= (*this).annual_salary_increase_rate_num; i++)
        cout << "annual_salary_increase_rate[year " << i <<"]=" << annual_salary_increase_rate[i-1] <<" ";
    cout << endl;
    cout << "-------------------------------\n" << endl;
}
