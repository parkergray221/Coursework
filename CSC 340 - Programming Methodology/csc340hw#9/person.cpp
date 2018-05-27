/*
    Parker Gray
    CSC 340 Programming Methodology
    12/7/16
*/

#include "person.h"
Person::~Person()
{
    if ( emails != NULL ){
      delete [] emails;
      emails = NULL;
    }
}

Person::Person()
{
    id = -1;
    name ="NA";
    //birthday = DayOfYear( 1,1, 2000);
    emails = NULL;
    numEmails = 0;
}

Person::Person(int new_id, string new_name)
{
    id = new_id;
    name = new_name;
    //birthday = date;
    emails=NULL;
    numEmails=0;
}

/**/
Person::Person(const Person & someone)
{
  id = someone.id;
  name = someone.name;
  numEmails = someone.numEmails;
  //allocate space to *emails if numEmails>0
  if (numEmails == 0)
      emails = NULL;
  else{
      emails = new string [numEmails];
      for (int i=0;i<numEmails; i++)
          emails[ i ] = someone.emails[ i ];
  }
}
/**/
/**/
void Person::operator =(const Person & rhs)
{
  id = rhs.id;
  name = rhs.name;
  //allocate space to *emails if needed
  if (numEmails > 0)
      delete [] emails;  //release the old memory
  numEmails = rhs.numEmails;
  emails = new string [numEmails];
  for (int i=0;i<numEmails; i++)
          emails[ i ] = rhs.emails[ i ];
}
/**/

void Person::output() const
{
    cout << "--------------------------\n";
    cout << "id=" << (*this).id << " name=" << this->name;
    for (int i=0; i<numEmails; i++)
        cout << "email-#" << i << ": " << emails[i] ;
    cout << "\n--------------------------\n\n";


}

int Person::get_id() const
{
    return id;
}

string Person::get_name() const
{

    return name;
}

void Person::set_id(int new_id)
{
    id = new_id;
}

void Person::set_name(string new_name)
{
    name = new_name;
}

string Person::getEmail( int i) const
{
        if (i>=0 && i<numEmails)
          return emails[i];
        else
            return "NA";
}

void Person::add_email( string the_email)
{
      //case 1: emails list is empty
      if ( numEmails == 0){
        emails = new string[1];
        //verification
        emails[0] = the_email;
      }
      else { //case 2: expand the list
          string *tmp_emails=new string [numEmails];
          for (int i=0; i<numEmails; i++)  //save the emails
                tmp_emails[i] = emails[ i ];
          delete [] emails;
          emails = new string [numEmails+1]; //expand the list by one
          //verify the above allocation
          for ( int i=0; i<numEmails; i++)
              emails[ i ] = tmp_emails[ i ]; //copy the existing emails
          emails[ numEmails ] = the_email; // add the new email
          delete [] tmp_emails;
      }
      numEmails += 1;
}

int Person::get_num_emails() const
{
    return numEmails;
}



void print( const Person& someone)
{
    cout << "****"<<someone.get_id() << " " << someone.get_name() <<endl;
}

//perform a sequential search on the employeeList
bool searchEmployee( Person *employeeList, int num_employees, int key)
{
    for ( int i=0; i<num_employees; i++){
        if ( employeeList[ i ].get_id() == key )//found
            return true;
    }//for (i)
    return false; //none of the employees has ID=key
}

bool sameID(const Person& person1, const Person& person2)
{
    return (person1.get_id() == person2.get_id());
}

bool equalID(const Person& person1, const Person& person2)
{
    return (person1.id == person2.id);
}
