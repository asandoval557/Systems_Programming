// Lab2_Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*TODO:
	Program 2
	Create a function with parameters for both an int and an int pointer.This function should print out the int and int pointer parameters(do not use any operators on the pointer as we just want to see the memory address).This function should not loop as it is printing only a single element.*/
void showMemoryAddress(int value, int* pointer)
{
	std::cout << "Value: " << value << "\tMemory Address: " << pointer << std::endl;
}

//Program 3_Part 1
//Declare an enum named EnumColorDefinition that contains at least two values
enum EnumColorDefinition
{
	Black, Red, White, Maroon, Magentic, Cobalt, Eggshell, Green
};

//Then, create a struct named Car that has the following members: Make - char array of size 32,
//Model – char array of size 32, Year – int, Mileage – int, Color - EnumColorDefinition
struct Car
{
	char Make[32];
	char Model[32];
	int Year;
	int Mileage;
	EnumColorDefinition Color;

};

//Program 3_Part 2
//Changes the Color member of the provided car pointer parameter to the provided color
void repaintCar(Car* ptrCar, EnumColorDefinition newcolor)
{
	ptrCar->Color = newcolor;
}

//Program 3_Part 3
//Move our display logic into a separate function.
void printCar(Car c)
{
	std::cout << c.Year << " ";

	switch (c.Color)
	{
	case 0:
	{
		std::cout << "Black";
		break;
	}
	case 1:
	{
		std::cout << "Red";
		break;
	}
	case 2:
	{
		std::cout << "White";
		break;
	}
	case 3:
	{
		std::cout << "Maroon";
		break;
	}
	case 4:
	{
		std::cout << "Magnetic";
		break;
	}
	case 5:
	{
		std::cout << "Cobalt";
		break;
	}
	case 6:
	{
		std::cout << "Eggshell";
		break;
	}
	case 7:
	{
		std::cout << "Green";
		break;
	}
	default:
		break;
	}
	std::cout << " " << c.Make << " " << c.Model << " with " << c.Mileage << " miles" << std::endl;
}

//Call printCar function within printCarPointer function
void printCarPointer(Car* ptrCar)
{
	printCar(*ptrCar);
}

//Program 3_Part 4 addmileage function
//Increase the Mileage member of the provided car pointer parameter by the provided amount
void addMileage(Car* ptrCar, int milestoadd)
{
	ptrCar->Mileage += milestoadd;
}



int main()
{
	/*TODO:
	-------------------------------------------------------------Program 1--------------------------------------------------------------------------------
	Create an array of 15 ints and place a random number into
	each slot in the array.Then loop through that array and print out
	the value and memory address of each item.*/

	int numbers[15] = { 2,8,4,6,7,0,15,3,22,76,21,90,64,53,43 };

	std::cout << "****************** PROGRAM 1 *******************" << std::endl;

	for (int i = 0; i < 15; i++)
	{
		std::cout << "Value: " << numbers[i] << "\tMemory Address: " << &numbers[i] << std::endl;
	}
	std::cout << "================================================\n\n" << std::endl;

	
	
	
	/*TODO:
	-------------------------------------------------------------Program 2--------------------------------------------------------------------------------
			Then, similar to Program 1, create another array of 15 ints and place a random number into each slot in the array.Loop through the array and pass each item in the array and its memory address to the function you created.*/

	int value[15];

	std::cout << "****************** PROGRAM 2 *******************" << std::endl;

	for (int i = 0; i < 15; ++i)
	{
		value[i] = rand() % 100;
		showMemoryAddress(value[i], &value[i]);
	}
	std::cout << "================================================\n\n" << std::endl;


	/*TODO:
	-------------------------------------------------------------Program 3--------------------------------------------------------------------------------
			Declare an array of 3 Car and ask the user for all of the information (all 5 members) of each car in the array by using a loop. Remember to use cin.getline for the make and model input instead of cin >>. You’ll also need to clear and ignore the cin buffer after each numeric input to avoid breaking the next getline input.*/

	std::cout << "****************** PROGRAM 3 *******************" << std::endl;

	const int cars = 3;

	Car Cars[cars];

	for (int i = 0; i < cars; i++)
	{
		std::cout << "Please enter car Make " << i + 1 << ": ";
		std::cin.getline(Cars[i].Make, 32);

		std::cout << "Please enter car Model " << i + 1 << ": ";
		std::cin.getline(Cars[i].Model, 32);

		std::cout << "Please enter Year of manufacture " << i + 1 << ": ";
		std::cin >> Cars[i].Year;
		std::cin.ignore(INT_MAX, '\n');

		std::cout << "Please enter car mileage " << i + 1 << ": ";
		std::cin >> Cars[i].Mileage;
		std::cin.ignore(INT_MAX, '\n');

		std::cout << "What color is your car? " << i + 1 << "( 0 = Black, 1 = Red, 2 = White, 3 = Maroon, 4 = Magentic, 5 = Cobalt, 6 = Eggshell, 7 = Green )";
		int colorInput;
		std::cin >> colorInput;
		std::cin.ignore(INT_MAX, '\n');
		Cars[i].Color = (EnumColorDefinition)colorInput;

	}

	//loop through the array of cars, call printCar and printCarPointer to display car details 
	//**switch that was originally created for print out the car details and later moved within
	//the printcar method.
	std::cout << "\n=====================================================" << std::endl;
	std::cout << "Printing cars..." << std::endl;
	for (int i = 0; i < cars; i++)
	{
		std::cout << "Car " << i + 1 << "- ";
		printCar(Cars[i]);
	}
	std::cout << "=====================================================" << std::endl;
	
	std::cout << "\n=====================================================" << std::endl;
	std::cout << "Printing car pointers..." << std::endl;
	for (int i = 0; i < cars; i++)
	{
		std::cout << "Car " << i + 1 << "- ";
		printCarPointer(&Cars[i]);
	}
	std::cout << "=====================================================" << std::endl;


	//Repaint and add mileage methods menu
	int updateMenu;
	
	do {
		std::cout << "\n\n*************** Update Car Details Menu **************" << std::endl;
		std::cout << "1.Update Mileage(Increase the number of miles of your car) \n2.Repaint your Car \n3.Exit Update Car Details Menu\n" << std::endl;
		std::cout << "Choose from the options above to update car details : " << std::endl;
		std::cin >> updateMenu;

		if (updateMenu == 1)
		{
			int mileageIndex;
			std::cout << "Which car do you want to update the mileage: \n(1 = Car-1, 2 = Car-2, 3 = Car-3)\n";
			std::cin >> mileageIndex;
			mileageIndex--;

			if (mileageIndex >= 0 && mileageIndex < cars)
			{
				int milestoadd;
				std::cout << "Enter the number of additional miles for car " << mileageIndex + 1 << ": ";
				std::cin >> milestoadd;
				std::cin.ignore(INT_MAX, '\n');
				addMileage(&Cars[mileageIndex], milestoadd);

			}
			else
			{
				std::cout << "Error try again..." << std::endl;
			}

		}
		else if (updateMenu == 2)
		{
			int repaintIndex;
			std::cout << "Which car do you want to repaint: \n(1 = Car-1, 2 = Car-2, 3 = Car-3)\n";
			std::cin >> repaintIndex;
			repaintIndex--;

			if (repaintIndex >= 0 && repaintIndex < cars)
			{
				int newColor;
				std::cout << "Choose a new color from the available options.( 0 = Black, 1 = Red, 2 = White, 3 = Maroon, 4 = Magentic, 5 = Cobalt, 6 = Eggshell, 7 = Green )";
				std::cin >> newColor;
				std::cin.ignore(INT_MAX, '\n');
				repaintCar(&Cars[repaintIndex], (EnumColorDefinition)newColor);
			}
			else
			{
				std::cout << "Error try again..." << std::endl;
			}

		}
		
		//Using the existing print methods and loop from above to reprint updated car details  
		std::cout << "\n=====================================================" << std::endl;
		std::cout << "Printing updated cars..." << std::endl;
		for (int i = 0; i < cars; i++)
		{
			std::cout << "Car " << i + 1 << "- ";
			printCar(Cars[i]);
		}
		std::cout << "=====================================================" << std::endl;

		std::cout << "\n=====================================================" << std::endl;
		std::cout << "Printing updated car pointers..." << std::endl;
		for (int i = 0; i < cars; i++)
		{
			std::cout << "Car " << i + 1 << "- ";
			printCarPointer(&Cars[i]);
		}
		std::cout << "=====================================================" << std::endl;

	} while (updateMenu != 3);
}