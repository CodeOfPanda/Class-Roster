#ifndef SOFTWARE_STUDENT
#define SOFTWARE_STUDENT
#include "student.h"

//derived from the Student class
class SoftwareStudent : public Student
{
public:
	//empty constructor that calls the parent constructor from Student class.
	SoftwareStudent();

	//custom constructor that calls the parent version from Student class.
	SoftwareStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int numDays[], Degree degreeTypes);

	//redeclared without the virtual keyword. 
	//will override the Student class.
	Degree getDegreeProgram();
	void Print();

	~SoftwareStudent();
};

#endif // !SOFTWARE_STUDENT