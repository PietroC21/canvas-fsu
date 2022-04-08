/* Name: Pietro Candiani.
 * Date: March 21, 2022.
*/

#include <iostream>
#include "student.h"
#include "commands.h"

using namespace std;

char GetCommand();
int IsLegal(char cmd);
void ShowMenu();


int main() {
Commands c;     //Create one object


    char cmd;

    ShowMenu();
    cout<<"\n\tStart by creating a class enter a"<<endl;
    do
    {

        cmd = GetCommand(); // Get a command from the user,
        if (cmd == 'm')// if 'm', display the menu
            ShowMenu();
        else if (cmd != 'x')// else if it's not the exit command,
            c.DoSelection(cmd); // pass it on to the machine.
    } while (cmd != 'x'); // Quit when the user enters 'X'.



    return 0;
}
char GetCommand()
// Get a char and send the char back to main.
{
    char cmd;    // the command character entered by the user
    do
    {
        cout << "\n> ";
        cin >> cmd;

        if (!IsLegal(cmd))// We got an illegal command
            cout << "\n*** Unrecognized command.  Type M to see the menu.";
    } while (!IsLegal(cmd));
    return cmd;
}

int IsLegal(char cmd)
// Return 1 if cmd is one that we can handle, else return 0.
{
    return  ((cmd == 'a') || (cmd == 's') || (cmd == 'R') ||
             (cmd == 'l') || (cmd == 'f') || (cmd == 'F') ||
             (cmd == 'r') || (cmd == 'x') || (cmd == 'm') || (cmd == 'M') );
}

void ShowMenu()
{
    cout << "Please select one of the following options\n";
    cout << "by pressing the indicated key:\n";
    cout << "\t\ta:  Add a Course\n";
    cout << "\t\ts:  Add a Student\n";
    cout << "\t\tl:  List courses and students\n";
    cout << "\t\tf:  Find student by name os student ID\n";
    cout << "\t\tF:  Find course by name, course code, or location\n";
    cout << "\t\tr:  Remove a course from the list by course code\n";
    cout << "\t\tR:  Remove a student from the list\n";
    cout << "\t\tM:  Modify a student from the list\n";
    cout << "\t\tm:  Display Menu of Program\n";
    cout << "\t\tx:  Quit Program\n";
}
