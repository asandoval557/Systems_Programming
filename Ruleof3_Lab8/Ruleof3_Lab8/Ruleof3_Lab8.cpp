#include <iostream>
#include "Base.h"
#include "Employee.h"
#include "Student.h"
#include <vector>
#include <iostream>
#include <string>
#include "Helper.h"

//Declaring AddRecord,DisplayRecord, and DuplicateRecord above int main()
//Definig the 3 methods will take place outside on int main() in order to maintain code clarity(I want to say maintain good housekeeping of my code, but doesn't sound right)
void AddRecord(std::vector<Base*>& BasePtr);
void DisplayRecords(std::vector<Base*>& BasePtr);
void DuplicateRecord(std::vector<Base*>& BasePtr);

int main()
{
	std::vector<Base*> basePtr;
	int mainMenu;

	do
	{
		//User facing menu options, displayed via console and mainMenu variable accepts user input
		std::cout << " Welcome to the Main Menu, choose from the options below:\n\n 1. Add a Record\n 2. Display all Records\n 3. Duplicate a Record\n 4. Exit Main Menu\n";
		mainMenu = Helper::GetValidatedInt("Enter your choice: ", 1, 4);

		//menu loop that will allow the user to add a record, display all records, duplicate a record, or exit the menu loop.
		switch (mainMenu)
		{
		case 1:
			AddRecord(basePtr);
			break;
		case 2:
			DisplayRecords(basePtr);
			break;
		case 3:
			DuplicateRecord(basePtr);
			break;
		case 4:
			std::cout << "Thank you for visiting. Press any key to exit" << std::endl;
			break;
		default:
			break;
		}

	} while (mainMenu != 4);

	//Delete all records in the vector
	for (auto& record : basePtr)
	{
		delete record;
	}
}

void AddRecord(std::vector<Base*>& BasePtr)
{
	int recordMenu;
	//User facing menu, user can add a record to the employee or student, recordMenu variable accepts user input
	std::cout << "What type of record would you like to add? Choose from the options below:\n 1. Employee\n 2. Student\n";
	recordMenu = Helper::GetValidatedInt("Enter your choice: ", 1, 2);

	std::string name;
	int salary;
	float gpa;

	switch (recordMenu)
	{
	case 1:
	{
		std::cout << "Enter Employee's Name: ";
		std::cin.ignore();
		std::getline(std::cin, name);
		salary = Helper::GetValidatedInt("Enter Employee Salary: ", 0, std::numeric_limits<int>::max());

		Employee* employee = new Employee(name.c_str(), salary);
		//Push new record to the employee vector
		BasePtr.push_back(employee);
		break;
	}
	case 2:
	{
		std::cout << "Enter Student's Name: ";
		std::cin.ignore();
		std::getline(std::cin, name);
		gpa = Helper::GetValidatedFloat("Enter Student's current GPA: ", 0.00f, 4.00f);

		Student* student = new Student(name.c_str(), gpa);
		//Push new record to the student vector
		BasePtr.push_back(student);
		break;
	}
	default:
		std::cout << "You've made an invalid choice, try again." << std::endl;
	}

}
//loop through the vector of records and call each pointer’s DisplayRecord() method
void DisplayRecords(std::vector<Base*>& BasePtr)
{
	for (auto& record : BasePtr)
	{
		record->DisplayRecord();
		std::cout << std::endl;
	}
}

void DuplicateRecord(std::vector<Base*>& BasePtr)
{
	int duplicateMenu;
	// User facing menu, user can duplicate a record to the employee or student, duplicateMenu variable accepts user input
	std::cout << "Enter the index of the record that you would like to duplicate: ";
	std::cin >> duplicateMenu;

	// Error checking to ensure user input is within the bounds of the vector
	if (duplicateMenu >= 0 && duplicateMenu < BasePtr.size())
	{
		Base* original = BasePtr[duplicateMenu];
		Base* copy;
		//use the dynamic_cast technique from lecture to determine whether that record is a Student or Employee
		if (dynamic_cast<Employee*>(original))
		{
			copy = new Employee(*dynamic_cast<Employee*>(original));
		}
		else if (dynamic_cast<Student*>(original))
		{
			copy = new Student(*dynamic_cast<Student*>(original));
		}
		//Pushback duplicated record to vector
		BasePtr.push_back(copy);
	}

}








