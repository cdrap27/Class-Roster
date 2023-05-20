#include "student.h"
#include "degree.h"
#include "roster.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <array>


Roster::Roster()
{
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Chad,Draper,cdrap27@wgu.edu,29,27,32,45,SOFTWARE" };
	classRosterArray = new Student[5];
	//parse data 
	for (int i = 0; i < 5; i++)
	{
		//get id
		size_t j = studentData[i].find(",");
		string studentID = studentData[i].substr(0, j);
		size_t k = j + 1;
		//cout << studentID << endl;
		//get first name
		j = studentData[i].find(",", k);
		string firstName = studentData[i].substr(k, j - k);
		//cout << firstName << endl;
		//get last name
		k = j + 1;
		j = studentData[i].find(",", k);
		string lastName = studentData[i].substr(k, j - k);
		//cout << lastName << endl;
		//get email
		k = j + 1;
		j = studentData[i].find(",", k);
		string email = studentData[i].substr(k, j - k);
		//cout << email << endl;
		//get age
		k = j + 1;
		j = studentData[i].find(",", k);
		int age = stoi(studentData[i].substr(k, j - k));
		//cout << age << endl;
		//get day1
		int days[3];
		k = j + 1;
		j = studentData[i].find(",", k);
		int daysInCourse1 = stoi(studentData[i].substr(k, j - k));
		//cout << days[0] << endl;
		//get day2
		k = j + 1;
		j = studentData[i].find(",", k);
		int daysInCourse2 = stoi(studentData[i].substr(k, j - k));
		//cout << days[1] << endl;
		//get day3
		k = j + 1;
		j = studentData[i].find(",", k);
		int daysInCourse3 = stoi(studentData[i].substr(k, j - k));
		//cout << days[2] << endl;
		//get degree program
		k = j + 1;
		j = studentData[i].find("\"", k);
		string degreeP = studentData[i].substr(k, j - k);
		DegreeType dp;
		//cout << degreeP << endl;
		if (degreeP.at(0) == 'S')
		{
			if (degreeP.at(1) == 'E')
				dp = SECURITY;
			else
				dp = SOFTWARE;
		}
		else if (degreeP.at(0) == 'N')
			dp = NETWORK;
		add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, dp);
	}
	this->student = 0;
}

Roster::~Roster() {
	cout << "Roster destructor called" << endl;
	delete[] classRosterArray;
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType dp)
{
	int days[3];
	days[0] = daysInCourse1;
	days[1] = daysInCourse2;
	days[2] = daysInCourse3;
	Student* s = new Student(studentID, firstName, lastName, email, age, days, dp);
	classRosterArray[student++] = *s;
	//cout << totalStudents;
	totalStudents = totalStudents++;
	//cout << endl << "Student added." << endl;
	return;
}

Student Roster::getCurrentStudent(int currentStudent) 
{
	return classRosterArray[currentStudent];
}

void Roster::remove(string studentID)
{
		for(int i = 0; i < totalStudents; i++)
		if (classRosterArray[i].getStudentID() == studentID)
		{
			cout << "Deleting: " << studentID << endl;
			classRosterArray[i].setStudentId("empty");
			return;
		}
	cout << "Error: Student not found.\n";
		

	
}

void Roster::printAll()
{
	for(int i =0; i < totalStudents; i++)
		if(classRosterArray[i].getStudentID() != "empty")
	classRosterArray[i].print();
}

void Roster::printAverageDaysInCourse(string StudentID)
{

	int avg = 0;
	for (int i = 0; i < totalStudents; i++)
	{
		if (classRosterArray[i].getStudentID() == StudentID)
		{
			avg = (classRosterArray[i].getDays()[0] + classRosterArray[i].getDays()[1] + classRosterArray[i].getDays()[2])/3;
			cout << "Student: " << classRosterArray[i].getFirstName() << " ID: " << classRosterArray[i].getStudentID() << " has an average of " << avg << " days in three courses.\n";
			return;
		}
		
	}
	cout << "Error: Student not found.\n";
}

void Roster::printInvalidEmails()
{
	cout << "Invalid E-Mail Address:\n";
		bool invalid = false;
	for (int i = 0; i < totalStudents; i++)
	{
		if (classRosterArray[i].getEmail().find(" ") != std::string::npos 
			|| classRosterArray[i].getEmail().find("@") == std::string::npos 
			|| classRosterArray[i].getEmail().find(".") == std::string::npos)
		{
			cout << classRosterArray[i].getEmail() << endl;
			invalid = true;
		}

	}
	if (invalid == false)
		cout << "None" << endl; 
}

void Roster::printByDegreeProgram(DegreeType degreeProgram)
{
	string degree;
	bool found = false;
	if (degreeProgram == 0)
		degree = "SECURITY";
	else if (degreeProgram == 1)
		degree = "NETWORK";
	else if (degreeProgram == 2)
		degree = "SOFTWARE";
	cout << degree << " students:\n";

	for (int i = 0; i < totalStudents; i++)
	{
		if (classRosterArray[i].getDegreeProgram() == degree
			&& classRosterArray[i].getStudentID() != "empty")
		{
			classRosterArray[i].print();
			found = true;
		}

	}
	if(found == false)
	cout << "Error: Student not found.\n";
}
