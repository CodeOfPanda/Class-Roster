#include "networkStudent.h"

NetworkStudent::NetworkStudent() :Student()
{
	//this empty constructor in the NetworkStudent class will call 
	//the empty constructor from the parent Student class.

	Degree degreeTypes = Degree::NETWORK;
};

NetworkStudent::NetworkStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int numDays[], Degree degreeTypes) :Student(studentID, firstName, lastName, emailAddress, age, numDays)
{
	//this works the same as the empty constructor (above).

	degreeTypes = Degree::NETWORK;
};

//since it is no longer virtual we can get the degree type.
Degree NetworkStudent::getDegreeProgram()
{
	return Degree::NETWORK;
};

void NetworkStudent::Print()
{
	//calls the print method that is in the Student class.
	this->Student::Print();
};

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
};