#include <iostream>
using namespace std;

class Student{

    friend istream& operator>>(istream& h, Student& s);
    friend ostream& operator << (ostream& h, const Student& s);

public:
Student();  //constructor
~Student(); //destructor



//Getters
const char * GetName();
const char * GetMajor();
const char  GetClassification();
const int GetSID();

//Setters
void SetName(char* d);
void SetClassification(char d);
void SetMajor(char *d);
void SetSID(int d);

//operator overload for deeps copy
Student& operator=(const Student& a);


private:
    char * name;
char classification;
char * major;
int SID;
};


class Course{

    friend istream& operator>>(istream& h, Course& s);
    friend ostream& operator<<(ostream& h, const Course& d);


public:

    Course();
    ~Course();
    void AddStu();

    void GrowStu();
    void RemoveStudent(int pos);
    int SearchStudent( char ans, char d[], int a);
    void ModifyS( char ans, int pos);

    int FindName( Student *aName);

    char * GetCourseName();
    char * GetCode();



    Course& operator=(const Course& a);

private:
    int  maxStu,currentStu;
    char *CourseName;
    char Code[7];
    char Location[10];
    Student *s; //roster

};
