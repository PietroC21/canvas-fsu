/* Name: Pietro Candiani.
 * Date: March 21, 2022.
 * Assignment: Homework 4
 * Section: 2
*/


#include "student.h"
#include "commands.h"
#include <cstring>
#include <iostream>
using namespace std;

Commands::Commands() {
        //I created a new class so I can put all the functions that I want and need for the program
    current=0;
    max=2;

    c=new Course[max];

}

Commands::~Commands() {

    delete [] c;

}
void Commands::GrowCourse()
{

    if(current==max) //if current Course is equal to MaxCourses, then we have to grow it, same concept as before
    {
        Course *newC;
        max=max+2;
        newC= new Course [max];

        for(int i=0;i<current;i++)
        {newC[i]=c[i];
       }



delete [] c;
        c=newC;


    }
}

void Commands::DoSelection(char cmd) {

    switch(cmd) // Show all possible comndads and what function they should call
    {
        case 'a' : AddCourse();  break;
        case 's' : AddS();  break;
        case 'l' : { for(int i=0;i<current;i++)
            {cout<< c[i];}
            break;}
        case 'M': ModifyS(); break;
        case 'f' :  ; SearchS();  break;
        case 'F' :  SearchC();  break;
        case 'r' :RemoveC();  break;
        case 'R' :  RemoveS(); break;



    }
}

void Commands::AddCourse() {

    if(current==max)        //Before adding a class I make sure current does not equal max
        GrowCourse();

cin>>c[current];        //After I give the chance of the user adding a new course

current++;
}

void Commands::AddS() {
cin.ignore();
    char d[50];
    int pos=-1;
    cout<<"In what class do you wish to add this student(s)? ";     //To add a student I first ask in what class they
    cin.getline(d,50,'\n');                              // want to add the student



    for(int i=0;i<current && pos==-1;i++)
    {
        if(strcmp(d,c[i].GetCourseName())==0)
        {
            pos=i;      //Get the position of the class the user wants

        }
    }




    if(pos==-1)
    {cout<<"Cannot find class! "<<endl;}

    if(pos!=-1)
        c[pos].AddStu();        //And then add the student in the array of class at that position

}

void Commands::RemoveS()
{

    char ans;
    int pos=-1,posC=-1,a=0;
    char d[40];
    cout<<"Type s to search by name, or i to search by Student ID ";
    cin>>ans;
    cin.ignore();

    if(ans=='s'){
        cout<<"Whats the name of the student: ";
        cin.getline(d,40,'\n');
        for(int i=0;i<current && pos==-1;i++)
        {
            pos=c[i].SearchStudent('s',d,0);        //To remove student I get the position of the student
            posC=i;                                         //And the position of the course the student is
        }
    }

    if(ans=='i')
    {
        cout<<"Whats the Student ID of the student: ";
        cin>>a;
        cin.ignore();
        for(int i=0;i<current && pos==-1;i++)
        {
            pos=c[i].SearchStudent('i',d,a);
            posC=i;

        }
    }

    if(pos==-1)
    {
        cout<<"Could not find student";
    }


 else if(pos!=-1)
    {
     c[posC].RemoveStudent(pos);        //After if we find the student We call the function remove and remove him
    cout<<"Student Removed!"<<endl;
    }

}

void Commands::SearchS() {

    char ans;
    int pos=-1;
    int posC=-1;
    char d[40];
    int a;
    cout<<"Type s to search by name, or i to search by Student ID ";
    cin>>ans;
    cin.ignore();

    if(ans=='s'){         //Depending on the option the user chose it will iterate through all courses to see if
                         //it finds a student with that name
        cout<<"Whats the name of the student: ";
        cin.getline(d,40,'\n');
        for(int i=0;i<current && pos==-1;i++)
        {
            pos=c[i].SearchStudent('s',d,0);

        }
    }

if(ans=='i')
{
    cout<<"Whats the Student ID of the student: ";
   cin>>a;
   cin.ignore();
    for(int i=0;i<current && pos==-1;i++)
    {
        pos=c[i].SearchStudent('i',d,a);

    }
}
    if(pos==-1)     //if pos = -1 it means it never found the student
    {
        cout<<"Could not find student";
    }


}

    int Commands::SearchC()
    {

        char d[50];     //same conecpt as search for student but here we iterate just the courses and not the student in the coujrse
        char ans;
        int pos=-1;


        cout<<"Type s to search by  course name,  i to search by Course code, or l by location ";
        cin>>ans;
cin.ignore();


        if(ans=='s') {
            cout<<"Whats the name of the course? ";
            cin.getline(d,50,'\n');

            for (int i = 0; i < current && pos==-1; i++) {
                if (strcmp(d, c[i].GetCourseName()) == 0) {
            cout<<c[i]<<endl;
            pos=i;

                }
            }
             }

        if(ans=='i')
        {
            cout<<"Whats the code of the course? ";
            cin.getline(d,7,'\n');

            for (int i = 0; i < current && pos==-1; i++) {
                if (strcmp(d, c[i].GetCode()) == 0) {
                    cout<<c[i]<<endl;
                    pos=i;

                }
            }
         }

        if(ans=='l')
        {

            cout<<"Whats the location of the course? ";
            cin.getline(d,10,'\n');


            for (int i = 0; i < current && pos==-1; i++) {
                if (strcmp(d, c[i].GetCourseName()) == 0) {
                    cout<<c[i]<<endl;
                    pos=i;

                }
            }
      }

        if (pos==-1)
        { cout<<"Course not found";
            return pos;}
        if(pos!=-1)
        {
            return pos;
        }
    }

    void Commands::RemoveC() {


        int pos;
        pos=SearchC();      //To remove a course first find the position of the course

        if(pos==-1)     //Then make sure it returned a valid position
        {cout << "Course not Found.\n";}



        if(pos!=-1){        //If it did remove the course and bring the rest down by one
            for(int j=pos+1;j<current;j++)
            {
                c[j-1]=c[j];
            }

            current--;      //And decrese the current by one
            cout << "Course removed!\n";}
    }

void Commands::ModifyS() {

    char ans;
    int pos=-1;
    int posC=-1;
    char d[40];
    cout<<"Type s to modify  name, m to modify major, or i to modify Student ID ";
    cin>>ans;       //First ask the user what they wish to modify in a studnet
    while(ans!='s'&& ans!='m'&& ans!='i'&& ans!='c')
    {
        cout<<"Sorry type it again!\ns to modify  name, m to modify major, or  i to modify Student ID ";
        cin>>ans;
    }
    cin.ignore();

cout<<"What's the name of the student? ";
cin.getline(d,40,'\n');
for(int i=0;i<current;i++)
{
    pos=c[i].SearchStudent('s',d,0);        //Find nposition of student and which course they are
    posC=i;
}

if(posC!=-1)
c[posC].ModifyS(ans,pos);   //Then call the modify function and then depending on their answer modify that

else
    cout<<"Student not found!"<<endl;

}