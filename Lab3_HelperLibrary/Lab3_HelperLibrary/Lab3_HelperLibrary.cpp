#include <iostream>
#include "Helper.h"



int main()
{
    int userInput;

    // Test with no range
    userInput = Helper::GetValidatedInt("Enter a number: ", 0, 0);
    std::cout << "You entered: " << userInput << std::endl;

    // Test with minimum range
    userInput = Helper::GetValidatedInt("Enter a number greater than 5: ", 5, 0);
    std::cout << "You entered: " << userInput << std::endl;

    // Test with minimum range
    userInput = Helper::GetValidatedInt("Enter a number lower than 50: ", 0, 50);
    std::cout << "You entered: " << userInput << std::endl;

    // Test with both minimum and maximum range
    userInput = Helper::GetValidatedInt("Enter a number between 20 and 30: ", 20, 30);
    std::cout << "You entered: " << userInput << std::endl;

    int randomNumber = Helper::RandomNumber(1, 100);
    std::cout << "Random Number: " << randomNumber << std::endl;

    Helper::clearInputBuffer();

    int numberToPrint = 42;
    Helper::printBinary(numberToPrint, nullptr);
    Helper::printHex(numberToPrint, nullptr);

    // Create a sample menu
    std::vector<std::string> menu = { "Apple", "Banana", "Cherry", "Date", "Elderberry" };

    // Print the menu and get the user's selection
    int selection = Helper::printMenu(menu);

    // Print the selected menu item
    if (selection != -1) {
        std::cout << "You selected: " << menu[selection - 1] << std::endl;
    }
    else {
        std::cout << "Invalid selection." << std::endl;
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
