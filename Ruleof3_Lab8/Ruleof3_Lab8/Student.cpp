#include "Student.h"
#include <iostream>


void Student::DisplayRecord()
{
	// DisplayRecord method so that it prints the name using GetName() and the salary to the screen
	std::cout << "Student Name: " << GetName() << "\nCurrent GPA: " << gpa << std::endl;
}
