#ifndef NETWORK_STUDENT
#define NETWORK_STUDENT

#include "student.h"

//derived from the Student class.
class NetworkStudent : public Student
{
public:

	NetworkStudent();

	//custom constructor.
	NetworkStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int numDays[], Degree degreeTypes);

	//redeclared but without virtual keyword.
	//will override the Student class.
	Degree getDegreeProgram();
	void Print();

	//destructor will call the destructor from the student class.
	~NetworkStudent();
};


#endif // !NETWORK_STUDENT
