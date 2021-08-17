#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent() :Student()
{
	//this empty constructor in the SoftwareStudent class will call 
	//the empty constructor from the parent Student class.

	Degree degreeTypes = Degree::SOFTWARE;
};

SoftwareStudent::SoftwareStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int numDays[], Degree degreeTypes) :Student(studentID, firstName, lastName, emailAddress, age, numDays)
{
	//this works the same as the empty constructor (above).

	degreeTypes = Degree::SOFTWARE;
};

//since it is no longer virtual we can get the degree type.
Degree SoftwareStudent::getDegreeProgram()
{
	return Degree::SOFTWARE;
};

void SoftwareStudent::Print()
{
	//calls the print method that is in the Student class.
	this->Student::Print();
};

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
};