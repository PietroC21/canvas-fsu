/* Name: Pietro Candiani.
 * Date: March 21, 2022.
*/
#include <iostream>
#include <cstring>
#include "student.h"
using namespace std;

Student::Student() {
        //Constructor that initializes all the data types

    classification= '\0';
    SID=0;



    name= new char [100];
    major= new char [100];


    name=strcpy(name," ");      //to make sure it's not initialize to junk data
    major=strcpy(major," ");

}

Student::~Student()
{
    delete [] name;     //destructor
    delete [] major;
}

Student &Student::operator=(const Student &a) {

delete [] name;
delete [] major;    //first I have to deallocate wahteevr its stored in the DMA so we dont have a leak

int sizeN=0,sizeM=0;
sizeN= strlen(a.name);      //after that we want to calculate how much space we will have to
sizeM= strlen(a.major);     // allocate with the new DMA we are trying to copy



    name= new char [sizeN];     //we also have to do this as we are doing a deep copy
    major= new char [sizeM];

    for(int i=0;i<sizeN;i++)
    {
        name[i]=a.name[i];      //here we are just copying the all the values, strcpy could have done the same
    }

    for(int i=0;i<sizeM;i++)
    {
        major[i]=a.major[i];
    }

classification=a.classification;
    SID=a.SID;

    return *this;       //as this is a deep copy we have to return *this
}

 istream& operator>>(istream& h, Student& s)
{
    cout << "\nType the Name, Major, Classification, and Student ID"        //this operator is used to get the info
            "\nEach followed by RETURN or ENTER:\n> ";                      // from user for the student class
    h.getline(s.name,100,'\n');
    cout<<"> ";
    h.getline(s.major,100,'\n');
    cout<<"> ";
    h>>s.classification;
    cout<<"> ";
    h>>s.SID;
    h.ignore();
    return h;

}


 ostream& operator << (ostream& h, const Student& s)
 {
                //This operator prints out the current student class to the screen
     h <<"\tName: " << s.name;

     h << "\t\tMajor: " << s.major; // Display phone number.

     h << "\t\tStudent ID: " << s.SID; // Display address.

     h << "\t\tClassification: " << s.classification; // Display address.

     h << '\n';
     return h;
 }


const char *Student::GetName() {
    return name;        //This are getters
}

const char *Student::GetMajor() {
    return major;
}


const char Student::GetClassification() {
    return classification;
}
const int Student::GetSID() {
    return SID;
}
void Student::SetName(char* d)
{       //The setters I used to then be able to modify the data of a student
        // As it's DMA we have to create a new DMA so we can allocate whatever the user is trying to set
        // the name here to
    name=new char [strlen(d)+1];
    strcpy(name,d);
}

void Student::SetMajor(char* d)
{
    major=new char [strlen(d)+1];
    strcpy(major,d);

}
void Student::SetClassification(char d) {
    classification=d;
}

void Student::SetSID(int d) {
    SID=d;
}

