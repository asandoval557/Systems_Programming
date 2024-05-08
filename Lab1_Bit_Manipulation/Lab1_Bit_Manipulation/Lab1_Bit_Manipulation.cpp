// Lab1_Bit_Manipulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


// Declare the unsigned int bitField globally
unsigned int bitField;

// TurnOn Helper function
void TurnOn(int bit)
{
    bitField |= (1 << bit);
}
// TurnOff Helper function
void TurnOff(int bit)
{
    bitField &= ~(1 << bit);
}
// Toggle Helper function
void Toggle(int bit)
{
    bitField ^= (1 << bit);
}
// Negate Helper function
void Negate()
{
    bitField = ~bitField;
}
// LeftShift Helper function
void LeftShift()
{
    bitField <<= 1;
}
// RightShift Helper function
void RightShift()
{
    bitField >>= 1;
}

//Print method
void showBitField(unsigned int bitField)
{
    std::cout << "Bits: ";
    for (int i = 31; i >= 0; --i)
    {
        std::cout << ((bitField >> i) & 1);
        if (i % 4 == 0)
        {
            std::cout << " ";
        }
    }
    std::cout << "\n=============================================" << std::endl;
}



int main()
{
    //Initialize bitField variable
    bitField = 19;
    
    //Declare and define bit and menuOptions
    int bit;
    int menuOptions = 0;

    do
    {
        //Display the initial value of bitField
        std::cout << "bitField: " << bitField << std::endl;

        //Print the on/off state of each of the 32 bits within the integer
        showBitField(bitField);

        //Display menu options and ask user for the operation that they would like to choose
        std::cout << "\nTurnOn = 1, TurnOff = 2, Toggle = 3, Negate = 4, LeftShift = 5, RightShift = 6, Exit = 7" << std::endl;
        std::cout << "\nChoose Operation: ";
        
        //Handle user input
        //Ensure proper validation of user input to prevent errors
        if(!(std::cin >> menuOptions))
        {
            std::cout << "Invalid choice. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch (menuOptions)
        {
        case 1:
        {
            std::cout << "Choose bit index: ";
            std::cin >> bit;
            TurnOn(bit);
            break;
        }
        case 2:
        {
            std::cout << "Choose bit index: ";
            std::cin >> bit;
            TurnOff(bit);
            break;
        }
        case 3:
        {
            std::cout << "Choose bit index: ";
            std::cin >> bit;
            Toggle(bit);
            break;
        }
        case 4:
        {
            Negate();
            break;
        }
        case 5:
        {
            LeftShift();
            break;
        }
        case 6:
        {
            RightShift();
            break;
        }
        default:
        {
            std::cout << "Invalid choice, try again." << std::endl;
            break;
        }

    }

    } while (menuOptions != 7);

    return 0;
}

