/*
  Name: personnel.cpp
  Copyright:
  Author:
  Date: 22/02/09 15:02
  Description: manage a personnel database that currently consists of one employee Mary
*/

#include "dayOfYear.h"
#include "person.h"
#include "student.h"

int main()
{
    DayOfYear date(20, 7, 1985);

    Person mary_p( 101, "Mary", date);
    Student mary_s( 101, "Mary", date, 1), mary_c;
   // Person & mary_p = mary_s;

    Person & person1 = mary_s;

    mary_s.output(); //student version
    person1.output();

    /*
    mary_p.output();
    mary_s.Person::output();//person version

    print( mary_s );

    mary_s.add_email("mary@gmail.com");
    mary_s.set_num_grades(2);
    mary_s.set_grade(1, 98.00);
    mary_s.set_grade(2, 100.00);

    mary_c = mary_s;

    cout << mary_s;
    cout << mary_c;
    */
   //mary_clone.set_id(202);
   // print(mary_clone);
    //mary_clone.output();

   // mary = mary_clone;
   // mary.output();

   //sameID(mary, mary_clone);
   // equalID(mary, mary_clone);
    /**the code below create a dynamic array of Person
    ***
    //1 & 2:
    Person *students213 = NULL; //
    int num = 200; //size of the dynamic array *students213

    //3. allocate memory to students213
    students213 = new Person [ num ];

    //4. verify
    if (students213 == NULL ){
       cerr << "Memory allocation failure.\n";
       exit( -1 );
    }
    //5: use
    for (int i=0; i<num; i++){
        students213[ i ].set_id( i + 100);
        students213[ i ].output();
    }

    //search based on id
    cout << "Is there a student with ID=207? ";
    if (searchStudent( students213, num, 207) )
       cout << " Yes."<<endl;
    else
        cout << " No. "<<endl;

    cout << "Is there a student with ID=507? ";
    if (searchStudent( students213, num, 507) )
       cout << " Yes."<<endl;
    else
        cout << " No. "<<endl;

    //6&7: release the memory
    delete [] students213;
    students213 = NULL;
    *****
    **end of the dynamic array students213
    **************************************/
    return 0;
}
