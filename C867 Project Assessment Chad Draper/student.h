#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include<string>
#include "degree.h"
using namespace std;
class Student
{
public:
	
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeType d);
	void setStudentId(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setStudentAge(int age);
	void setEmail(string email);
	void setDays(int days[]);
	void setDegreeProgram(DegreeType d);
	void print();

	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	int getStudentAge() const;
	string getEmail() const;
	int* getDays();
	string getDegreeProgram() ;


	

private:
	string studentID, firstName, lastName, email, degreeProgram;
	string degree[3];
	
	int age;
	int days[3];
	DegreeType d;


		
};

#endif

