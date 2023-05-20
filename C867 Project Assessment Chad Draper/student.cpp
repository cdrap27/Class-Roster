#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>



//setters
void Student::setStudentId(string studentID)
{
	this->studentID = studentID;
}


void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setStudentAge(int age)
{
	this->age = age;
}

void Student::setEmail(string email)
{
	this->email = email;

}

void Student::setDays(int days[])
{
	int daySize = sizeof(days);
	for (int i = 0; i < daySize; i++)
	{
		this ->days[i] = days[i];
	}
}

void Student::setDegreeProgram(DegreeType d)
{
	this->d = d;

}

//getters
string Student::getStudentID() const
{
	return studentID;
}

string Student::getFirstName() const
{
	return firstName;
}

string Student::getLastName() const
{
	return lastName;
}

int Student::getStudentAge()const
{
	return age;
}

string Student::getEmail() const
{
	return email;
}

int *Student::getDays() 
{
	return this->days;
}

string Student::getDegreeProgram() 
{
	//string degree[3];
	degree[0] = "SECURITY";
	degree[1] = "NETWORK";
	degree[2] = "SOFTWARE";
	//cout << d;
	degreeProgram = degree[d];
	return degreeProgram;
}

//default constructor
Student::Student()
{
	studentID = "";
	firstName = "";
	lastName = "";
	age = 0;
	email = "";
	//int daySize = sizeof(days);
	for (int i = 0; i < 3; i++)
	{
		this->days[i] = 0;
	}
	degreeProgram = "";
}

//constructor using all parameters

Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeType d)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	//int daySize = sizeof(days);
	for (int i = 0; i < 3; i++)
	{
		this->days[i] = days[i];
	}
	this->d = d;
}

//print student info
void Student::print()
{
	degree[0] = "SECURITY";
	degree[1] = "NETWORK";
	degree[2] = "SOFTWARE";
	degreeProgram = degree[d];
	cout << getStudentID() << "\tFirst Name: " << getFirstName() << "\tLast Name: " << getLastName() << "\tEmail: "<<
		email << "\tAge: " << age << "\tdaysInCourse {" << days[0] << ", " << days[1] << ", " << days[2] << "} Degree Program: " << degreeProgram << endl;
}