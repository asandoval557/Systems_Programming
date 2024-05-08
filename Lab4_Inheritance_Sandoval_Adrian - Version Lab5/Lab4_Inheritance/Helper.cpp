#include "Helper.h"
#include <bitset>

int Helper::GetValidatedInt(const char* strMessage, int nMinimumRange = 0, int nMaximumRange = 0)
{
    int userInput;
    bool isUserInputValid = false;

    while (!isUserInputValid)
    {
        std::cout << strMessage;
        std::cin >> userInput;


        if (std::cin.fail())
        {
            std::cout << "The Emperor is displeased with your choice! Please try again\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        }
        else
        {
            //Condition checking for no limits
            if (nMinimumRange != 0 && nMaximumRange != 0 && (userInput < nMinimumRange || userInput > nMaximumRange))
            {
                std::cout << "The Emperor is displeased with your choice! Please enter a value between "
                    << nMinimumRange << " and " << nMaximumRange << "." << std::endl;
            }

            //Condition checking for minimum
            else if (nMinimumRange != 0 && userInput < nMinimumRange)
            {
                std::cout << "The Emperor is displeased with your choice! Please enter a value between "
                    << nMinimumRange << " and " << nMaximumRange << "." << std::endl;
            }

            //Condition checking for maximum
            else if (nMaximumRange != 0 && userInput > nMaximumRange)
            {
                std::cout << "The Emperor is displeased with your choice! Please enter a value between "
                    << nMinimumRange << " and " << nMaximumRange << "." << std::endl;
            }
            else
            {
                isUserInputValid = true;

            }
        }
    }

    return userInput;
}

int Helper::RandomNumber(int minRange, int maxRange)
{
    int randNumber = std::rand() % (maxRange - minRange + 1) + minRange;
    return randNumber;
    std::cout << std::endl;
}

void Helper::clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}

void Helper::printBinary(int value, int* pointer)
{
    std::cout << "Value: " << value << "\tBinary: " << std::bitset<32>(value) << std::endl;
    std::cout << std::endl;
}

void Helper::printHex(int value, int* pointer)
{
    std::cout << "Hex: " << value << "\t0Ctal: " << std::oct << value << std::endl;
    std::cout << std::endl;
}

int Helper::printMenu(std::vector<std::string> menu)
{
    int menuSelect = -1;

    for (size_t i = 0; i < menu.size(); i++)
    {
        std::cout << i + 1 << ". " << menu[i] << std::endl;
    }

    std::cout << "Please enter your selection: ";
    std::cin >> menuSelect;


    if (menuSelect < 1 || menuSelect >menu.size())
    {
        menuSelect = -1;
        std::cout << "Your entry is invalid. Try again." << std::endl;
    }

    return menuSelect;
}

void Helper::CopyString(const char* source, char*& destination)
{
    delete[] destination;

    size_t len = strlen(source) + 1;
    destination = new char[len];
    strcpy_s(destination, len, source);
}

