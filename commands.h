
#include <fstream>
class Commands{
    friend ostream& operator<<( ostream &h,const Course& a);

public:

    Commands();
    ~Commands();


    void GrowCourse();
    void AddCourse( );
    void DoSelection(char cmd);
    void SearchS();
    int SearchC();
    void RemoveC();
    void RemoveS();
    void AddS();
    void ModifyS();


private:
    int current,max;
    Course *c;


};