#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"
using namespace std;

int main()
{
    cout << "C867 Scripting and Programming - Applications\tProgramming Language: C++\tStudentID: 007131218\tName: Chad Draper\n";
    Roster* classRoster = new Roster();
    cout << endl; 
    classRoster->printAll();
    cout << endl; 
    classRoster->printInvalidEmails();
    //loop through classRosterArray and for each element:
    cout << "\nAverage days in course\n";
    for (int i = 0; i < 5; ++i) 
    {
        Student x = classRoster->getCurrentStudent(i);
        classRoster->printAverageDaysInCourse(x.getStudentID());
    }
    cout << endl; 
    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl; 
    classRoster->remove("A3");
    cout << endl; 
    classRoster->printAll();
    cout << endl; 
    classRoster->remove("A3");
    cout << endl; 
    classRoster->~Roster();
   

   
   
}

