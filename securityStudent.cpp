#include "securityStudent.h"


SecurityStudent::SecurityStudent() :Student()
{
	//this empty constructor in the SecurityStudent class will call 
	//the empty constructor from the parent Student class.

	//now you can declare the degree type.
	Degree degreeTypes = Degree::SECURITY;
};

SecurityStudent::SecurityStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int numDays[], Degree degreeTypes) :Student(studentID, firstName, lastName, emailAddress, age, numDays)
{
	//this does the same thing as the empty constructor (above).
	degreeTypes = Degree::SECURITY;
};

//since it is no longer virtual we can get the degree type.
Degree SecurityStudent::getDegreeProgram()
{
	return Degree::SECURITY;
};

void SecurityStudent::Print()
{
	//calls the print method that is in the Student class.
	this->Student::Print();
};

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
};