#ifndef ROSTER
#define ROSTER

#include <string>
#include <iostream>
#include "degree.h"
#include "student.h"

const std::string studentData[] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Maggie,Leigland,mleigla@wgu.edu,23,45,30,20,SOFTWARE"
};

static const unsigned int MAX = sizeof(studentData) / sizeof(studentData[0]);
static const unsigned int COLUMNS = 9;

class Roster
{
public:
	//creating a array of MAX amount of null pointers of the Student class.
	//This allows adding Student objects to the array.
	Student* classRosterArray[MAX] = { nullptr, nullptr, nullptr, nullptr, nullptr }; 

	//sets the instance variables from Student class and updates roster.
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType);

	//removes students from the roster by their IDs and also prints an error if the ID is not found.
	void remove(std::string studentID);

	//prints a complete TAB separated list of studnet data using accer functions.
	void printAll();

	//prints average number of days to complete all three courses.
	//student is identified by their ID.
	void printDaysInCourse(std::string studentID);

	//verifies student email addresses and displays all invaild email addresses to the user.
	//needs to have '@' and '.' to be a verified email.
	void printInvalidEmails();

	//prints out student information for a degree program.
	//this comes from my enum class type Degree.(degree.h).
	void printByDegreeProgram(Degree degreeTypes);

	~Roster();
};

#endif

