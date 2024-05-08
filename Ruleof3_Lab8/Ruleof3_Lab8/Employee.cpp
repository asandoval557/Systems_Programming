#include "Employee.h"
#include <iostream>

void Employee::DisplayRecord()
{
	// DisplayRecord method so that it prints the name using GetName() and the salary to the screen
	std::cout << "Employee Name: " << GetName() << "\nCurrent Salary: $" << salary << std::endl;
}
