#ifndef SECURITY_STUDENT
#define SECURITY_STUDENT

#include "student.h"

//derived from the Student class.
class SecurityStudent : public Student
{
public:
	//empty constructor
	SecurityStudent();

	//custom constructor
	SecurityStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int numDays[], Degree degreeTypes);

	//redeclared but without the keyword virtual.
	Degree getDegreeProgram();
	void Print();

	~SecurityStudent();
};

#endif // !SECURITY_STUDENT
