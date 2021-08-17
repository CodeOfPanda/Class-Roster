#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <sstream>

/*Add method*/
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeTypes)
{
	int daysInCourse[] = {daysInCourse1, daysInCourse2, daysInCourse3}; //assigning the three values (daysInCourse1 - 3) to the array daysInCourse.
	Student* student = nullptr;

	//when it hits the Degree parameter it will use this switch statement to determine which type of instance to create, or it defaults to nullptr if it is an unknown entry.
	switch (degreeTypes) {
	case Degree::NETWORK:
		student = new NetworkStudent(studentID,firstName, lastName, emailAddress, age, daysInCourse, degreeTypes);
		break;
	case Degree::SECURITY:
		student = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeTypes);
		break;
	case Degree::SOFTWARE:
		student = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeTypes);
		break;
	default:
		student = nullptr;
		break;
	}

	//loops through the information and pushes each instance into the classRosterArray.
	for (int i = 0; i < MAX; ++i) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = student;
			break;
		}
	}
};

/*Remove method*/
void Roster::remove(std::string studentID) {
	std::cout << "Removing studentID: " << studentID << std::endl;
	bool found = false;

	for (int i = 0; i < MAX; i++) {
		//Checks if iteration of classRosterArray is NULL or is an object
		if (classRosterArray[i] != NULL) {
			//if not NULL, then check the paramter to the studentID of iteration of classRosterArray
			if (studentID == classRosterArray[i]->get_studentID())
			{
				found = true;
				classRosterArray[i] = nullptr;
				std::cout << "Student removed" << std::endl;
				break;
			}
		}
	}
	//if not found in loop above, studentID doesn't exist, print error
	if (found == false)
	{
		std::cout << "ERROR: No student with studentID: " << studentID << " was found." << std::endl;
	}
};

/*Print all*/
void Roster::printAll() {
	for (int i = 0; i < MAX; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			classRosterArray[i]->Print();
		}

	}
};

/*Print days in course*/
void Roster::printDaysInCourse(std::string studentID)
{
	for (int i = 0; i < MAX; i++)
	{
		//checks if the iteration is not a nullptr and the studentID parameter matches the classRosterArray iteration, then calls the get_studentID method.
		if ((classRosterArray[i] != nullptr) & (studentID == classRosterArray[i]->get_studentID()))
		{
			//assigns the memory location of get_numDays for each classRosterArray iteration object to the pointer variable days. 
			int* days = classRosterArray[i]->get_numDays();
			
			//Calculate average number of days for data iteration by accessing the values of the pointer variable days.
			int sum = (days[0] + days[1] + days[2]) / 3;

			std::cout << std::endl << classRosterArray[i]->get_firstName() << " "
				<< classRosterArray[i]->get_lastName() << " ("
				<< classRosterArray[i]->get_studentID() << ")"
				<< " will need an average of " << sum << " days.";
		}
	}

};

/*Print invalid emails*/
void Roster::printInvalidEmails()
{
	for (int i = 0; i < MAX; i++)
	{
		//first have to access the email data and then assigning it to variable email.
		std::string email = classRosterArray[i]->get_emailAddress();

		//these are going to be my place holders.
		bool atSignFlag = false; //initializing to false.
		bool periodFlag = false;
		bool spaceFlag = false;

		//loops through each character of the input email.
		for (char& c : email)
		{
			if (c == ' ')
			{
				spaceFlag = true; // reassigning to true if they did have a space in the email.
			}
			else if (c == '.')
			{
				periodFlag = true; //reassigning to true is a period was found.
			}
			else if (c == '@')
			{
				atSignFlag = true; //reassigning to true is an @ symbol was found.
			}
		}

		if (atSignFlag == false || periodFlag == false || spaceFlag == true) //take this branch if they did not include an @ symbol or a period or had an empty space.
		{
			std::cout << "This is an invalid Email entry: " << email << std::endl;
		}
	}
};

/*Print by degree program*/
void Roster::printByDegreeProgram(Degree degreeTypes)
{
	for (int i = 0; i < MAX; i++)
	{
		Student* degree = classRosterArray[i];
		
		//checks if the parameter is equal to the degree type returned by the getDegreeProgram method.
		if (degree->getDegreeProgram() == degreeTypes)
		{
			degree->Print(); //prints that students information to the user.
		}
		
	}
};

/*Destructor*/
Roster::~Roster() 
{

};

int main()
{
	std::cout << "Scripting and Programming Applications - c867" << std::endl;
	std::cout << "Written in C++, " << "Student ID#: 001058808" << " - Maggie Leigland\n" << std::endl;

	//creating an instance of Roster and Degree.
	Roster classRoster;
	Degree degree;

	std::string data;
	std::string data_in[COLUMNS];

	//parsing through the studentData array from roster.h.
	for (int i = 0; i < MAX; ++i)
	{
		std::istringstream input(studentData[i]);
		for (int j = 0; j < COLUMNS; ++j) {
			std::getline(input, data, ',');
			data_in[j] = data;
		}

		if (data_in[8] == "NETWORK") 
		{
			degree = Degree::NETWORK;
		} 
		else if (data_in[8] == "SECURITY") 
		{
			degree = Degree::SECURITY;
		} 
		else if (data_in[8] == "SOFTWARE") 
		{
			degree = Degree::SOFTWARE;
		}

		//std::stoi() converts a string into an int.
		classRoster.add(data_in[0], data_in[1], data_in[2], data_in[3], std::stoi(data_in[4]), std::stoi(data_in[5]), std::stoi(data_in[6]), std::stoi(data_in[7]), degree);
	}


	classRoster.printAll();

	std::cout << std::endl;

	classRoster.printInvalidEmails();

	std::cout << std::endl;

	
	//looping through the classRosterArray to get the studentID.
	//calling the printDaysInCourse with the current studentID.
	for (int i = 0; i < MAX; i++)
	{
		std::string studentID = classRoster.classRosterArray[i]->get_studentID();
		classRoster.printDaysInCourse(studentID);
	}

	std::cout << std::endl;
	std::cout << std::endl;

	//instructions stated to printByDegreeProgram for just software.
	classRoster.printByDegreeProgram(Degree::SOFTWARE);
	std::cout << std::endl;

	classRoster.remove("A3");
	classRoster.remove("A3");
	
	classRoster.~Roster();

	return 0;
}