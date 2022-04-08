/* Name: Pietro Candiani.
 * Date: March 21, 2022.
 * Assignment: Homework 4
 * Section: 2
*/

#include <iostream>
#include <cstring>
#include "student.h"
using namespace std;


Course::Course() {


    maxStu=2;       //ammount of students
    currentStu=0;

    strcpy(Code,"");
    strcpy(Location," ");
    CourseName=new char [50];

    s= new Student [maxStu];

}
Course::~Course() {

    delete [] CourseName;
    delete [] s;
}



void Course::GrowStu() {     //Grow how many students we can store in case we reached the max, this lets us grow it
    Student * newStu;       //we create a new pointer
        maxStu=maxStu+10;

        newStu=new Student[maxStu];     //Dynamically allocate it

        for(int i=0;i<currentStu;i++)
        {
            newStu[i]=s[i];     //using the = operator nwe copy all the valiues

        }

        delete[] s;     //deallocate s so we won't have a leak
        s=newStu;       //and then point the old pointer to where the new pointer is pointing to
    }


Course &Course::operator=(const Course &a) {

        delete [] CourseName;       //here we do the same  as in the student class
        delete [] s;

        int size=0,sizeS;

        sizeS=maxStu;

        size= strlen(a.CourseName);


        s=new Student [sizeS];
        CourseName= new char [size];


for(int i=0;i<size;i++)
    CourseName[i]=a.CourseName[i];

for(int i=0;i<a.currentStu;i++)
        s[i]=a.s[i];        //Also, a class is composed of students so we need to make sure we are copying them too

    strcpy(Code,a.Code);
    strcpy(Location,a.Location);
maxStu=a.maxStu;         //copy the max and current so if we want to add a students doesn't lap in the place
                        // of a student that already exists
currentStu=a.currentStu;


        return *this;
    }


 istream& operator>>(istream& h, Course& s)
 {
h.ignore();     //for cin so the '\n' is not input in the get line
         cout << "\nType the Name of course ,Course Code (7 chars), and  Course Location (10 chars)."
                 "\nEach followed by RETURN or ENTER:\n> ";
         h.getline(s.CourseName,100,'\n');
         cout<<"> ";
         h.getline(s.Code,100,'\n');
         cout<<"> ";
         h.getline(s.Location,100,'\n');


         char ans;

         cout<<"Would you like to add students? Type (y or n): ";     //Ask user if they want to add students
         cin>>ans;

         if(ans=='y')
             s.AddStu();
         if(ans!='n' & ans!='y')
         {
             while(ans!='n' & ans!='y')
             {

                 cout<<"Invalid Answer! Type it again "<<endl;
                 cout<<"Would you like to add students? Type (y or n): ";
                 cin>>ans;
                 cin.ignore();

             }

             if(ans=='y')
                 s.AddStu();


         }
         return h;
 }

 ostream& operator<<(ostream& h, const Course& d)
 {
     h<<"\nCourse: ";
     h  << d.CourseName;

     h << "\nCode:" << d.Code; // Display phone number.

     h<<"\nLocation: "<<d.Location<<endl;

     h << "\n\t***NAME***\t\t***MAJOR***\t\t***STUDENT ID***\t\t***CLASSIFICATION***\n\n";

for(int i=0;i<d.currentStu;i++)
    h<<d.s[i]<<endl;

     return h;

 }








void Course::AddStu() {


int ans=0;

    cout<<"How many students do you wish to add?";
    cin>>ans;       //here you have the option to add more than just one student

    ans+=currentStu;    // and so if we want to add more than one student we n eed to make sure that it
                       // isn't greater than our max size
if(ans>=maxStu || currentStu==maxStu)
    GrowStu();


cin.ignore();
    cout << "\nType the information of the students in this course";
    for( ;currentStu<ans;currentStu++)
    { cout << "\nType the information of the student number "<< currentStu+1<<" below: "<<endl;
       cin>> s[currentStu];
    }

}

void Course::RemoveStudent(int pos)
{
    for(int j=pos+1;j<currentStu;j++)
        s[j-1]=s[j];

    currentStu--;

}


int Course::SearchStudent(char ans, char d[],int a) {
int pos=-1;
        //what this does it searches in each individual class for the student with the date the user gave
        // and depending on what you want to search in will lead you there, and then return the position
        // of the student in a class
    if(ans=='s')
    {


        for(int i=0;i<currentStu  ;i++)
        { if(strcmp(d,s[i].GetName())==0)
            {

                cout<<s[i]<<endl;
                pos=i;
                return pos;
            }

        }


    }

    else if(ans=='i')
    {



        for(int i=0;i<currentStu ;i++)
        { if(a==s[i].GetSID())
            {
                cout<<s[i]<<endl;

                pos=i;
                return pos;

            }

        }



    }



    return pos;
}

void Course::ModifyS(char ans, int pos) {

    char d[50];
int k;
char a;

    if(ans=='s')
    {
        cout<<"What would you like to modify your name to?";
        cin.getline(d,50,'\n');
        s[pos].SetName(d);  //After finding the position of the student I use a setter to set the name to the name
                            //the user wish to use
    }
        if(ans=='m')
        {
            cout<<"What would you like to modify your major to?";
            cin.getline(d,50,'\n');
            s[pos].SetMajor(d);
        }
            if(ans=='i')
            {
                cout<<"What would you like to modify your Student ID to?";
        cin>>k;
        cin.ignore();
     s[pos].SetSID(k);
            }


            if(ans=='c'){

                cout<<"What would you like to modify your Classification to?";
                cin>>a;
                cin.ignore();

                s[pos].SetClassification(a);
            }

}


char* Course::GetCourseName() {

    return CourseName;
}

char* Course::GetCode() {

    return Code;
}