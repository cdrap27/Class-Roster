#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

class Roster
{
public:
	Roster();
	~Roster();
	void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType dp);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string StudentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeType degreeProgram);
	Student getCurrentStudent(int currentStudent);


private:
	string studentID;
	
	Student* classRosterArray;
	int student;
	int totalStudents;



};

#endif