#ifndef STUDENT
#define STUDENT

#include "degree.h"

class Student
{
public:
	/*variables*/
	const static int NUM_COURSES = 3;
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int numDays[NUM_COURSES];
	Degree degreeTypes;

	/*constructors*/
	Student();
	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int numDays[]);

	/*getters*/
	std::string get_studentID();
	std::string get_firstName();
	std::string get_lastName();
	std::string get_emailAddress();
	int get_age();
	int* get_numDays();
	virtual Degree getDegreeProgram() = 0; //(should be populated in subclasses only.)

	/*setters*/
	void set_studentID(std::string studentID);
	void set_firstName(std::string firstName);
	void set_lastName(std::string lastName);
	void set_emailAddress(std::string emailAddress);
	void set_age(int age);
	void set_numDays(int numDays[]);

	/*print*/
	virtual void Print() = 0;

	~Student();
};

#endif // !STUDENT
