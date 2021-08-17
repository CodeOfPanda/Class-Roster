#include "student.h"

/*constructors*/
Student::Student()
{
	//empty constructor will set to default values.
	//does not include degreeTypes.
	//if you don't set the strings to empty strings it could be set to 0.
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < NUM_COURSES; i++)
	{
		this->numDays[i] = 0;
	}
};

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int numDays[])
{
	//does not include degreeTypes.
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < NUM_COURSES; i++)
	{
		this->numDays[i] = numDays[i];
	}
};

/*getters*/
std::string Student::get_studentID()
{
	return studentID;
};

std::string Student::get_firstName()
{
	return firstName;
};

std::string Student::get_lastName()
{
	return lastName;
};

std::string Student::get_emailAddress()
{
	return emailAddress;
};

int Student::get_age()
{
	return age;
};

int* Student::get_numDays()    //array of pointers.
{
	return numDays;
};


/*setters*/
void Student::set_studentID(std::string studentID)
{
	this->studentID = studentID;    //must use the "this" keyword so the compiler knows the correct variable to assign to.
};

void Student::set_firstName(std::string firstName)
{
	this->firstName = firstName;
};

void Student::set_lastName(std::string lastName)
{
	this->lastName = lastName;
};

void Student::set_emailAddress(std::string emailAddress)
{
	this->emailAddress = emailAddress;
};

void Student::set_age(int age)
{
	this->age = age;
};

void Student::set_numDays(int numDays[])
{
	//must iterate through the array to be able to set the different values to the number of days needed.
	for (int i = 0; i < NUM_COURSES; i++)
	{
		this->numDays[i] = numDays[i];
	}

};


/*Print*/
void Student::Print()
{
	std::cout << get_studentID()
		<< "\tFirst Name: " << get_firstName()
		<< "\tLast Name: " << get_lastName()
		<< "\tAge: " << get_age();

	int* numberDays = get_numDays();
	std::cout << "\tdaysInCourse: {"
		<< numberDays[0] << ", "
		<< numberDays[1] << ", "
		<< numberDays[2] << "}";

	std::string degree = "";
	switch (getDegreeProgram())
	{
	case Degree::NETWORK:
		degree = "NETWORK";
		std::cout << "\tDegree Program: " << degree << std::endl;
		break;
	case Degree::SECURITY:
		degree = "SECURITY";
		std::cout << "\tDegree Program: " << degree << std::endl;
		break;
	case Degree::SOFTWARE:
		degree = "SOFTWARE";
		std::cout << "\tDegree Program: " << degree << std::endl;
		break;
	default:
		std::cout << "\tI'm sorry that is not a vaild entry." << std::endl;
		break;
	}
};


/*deconstructor*/
Student::~Student()
{
	//does not do anything right now;
	std::cout << "deconstructor was hit" << std::endl;
};