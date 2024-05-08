#include <iostream>
#include "BaseAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include <crtdbg.h>
#define MEMORY_LEAK_LINE
#include "Helper.h"
#include <fstream>
#include <format>

//Create a function for withdraw and one for deposit that will take in a BaseAccount*. Then pass the selected account pointer to this function.
void withdraw(BaseAccount* account, float amount)
    {
    account->Withdraw(amount);
    std::cout << "\nAmount of $" << amount << " withdrawn from your account.\n" << "Updated Balance $" << account->GetBalance() << std::endl;
    }
void deposit(BaseAccount* account, float amount)
    {
    account->Deposit(amount);
    std::cout << "\nAmount of $" << amount << " accepted and deposited to you account.\n" << "Updated Balance $" << account->GetBalance() << std::endl;
    }



int main()
{
    //Enable memory leak detection
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetBreakAlloc(-1);
    _CrtDumpMemoryLeaks();

    //Create an instance of each derived class; CheckingAccount*, SavingsAccount*, and CreditAccount*,these instances should be initialized with new making the heap variables
    CheckingAccount* checkingAccount = new CheckingAccount();
    SavingsAccount* savingsAccount = new SavingsAccount();
    CreditAccount* creditAccount = new CreditAccount();

    //read in Binary.bin file and deposit into each of the accounts, if the file does not exist then deposit the default balances into each account.
    std::ifstream readFile("Binary.bin", std::ios::binary);
    if(readFile.is_open())
    {
        float balance;
        readFile.read(reinterpret_cast<char*>(&balance), sizeof(float));
        checkingAccount->Deposit(balance);
        readFile.read(reinterpret_cast<char*>(&balance), sizeof(float));
        savingsAccount->Deposit(balance);
        readFile.read(reinterpret_cast<char*>(&balance), sizeof(float));
        creditAccount->Deposit(balance);
        readFile.close();
    }
    else
    {
        //Initialize default balances for each account
        checkingAccount->Deposit(1500);
        savingsAccount->Deposit(10000);
        creditAccount->Deposit(1000);
    }
    //Menu system that will allow for deposits and withdrawals to be made to the various accounts
    int transactionInput;
    int accountAction;
    float amount;
 
    
    while (true)
    {
        //Initial menu and prompting the user to choose to either deposit or withdraw
        std::cout << "\n ***************************************";
        std::cout << "\n Galactic Empire Banking Menu:\n 1. Deposit\n 2. WithDraw\n 3. View Account Balance\n 4. Exit \n ***************************************\n Please pick from the options above: ";
        
        //updated banking menu with a view balances option that was not added in lab 4, this will only show the current balances for the user and will display the last updated balances when loading the Binary.bin file when restarting the program. 
        transactionInput = Helper::GetValidatedInt("", 1, 4);
        if (transactionInput == 3)
        {
            std::cout << " \nChecking Account Balance $" << checkingAccount->GetBalance() << std::endl;
            std::cout << " \nSavings Account Balance $" << savingsAccount->GetBalance() << std::endl;
            std::cout << " \nCredit Account Balance $" << creditAccount->GetBalance() << std::endl;
            continue;
        }
        else if (transactionInput == 4)
            break;

        //Secondary menu with options to access checking, saving, or credit accounts
        std::cout << "\n ****************************************";
        std::cout << "\n Galactic Empire Banking Account Options:\n 1. Checking\n 2. Savings\n 3. Credit\n ****************************************\n Please pick from the options above: ";
        accountAction = Helper::GetValidatedInt("", 1, 4);

        //Prompt the user for the amount of withdrawal or deposit
        std::cout << "\nEnter the total amount(Galactic Credits only): $";
        std::cin >> amount;
        std::cin.clear();
        std::cin.ignore(INT_MAX,'\n');


        switch (transactionInput)
        {
        case 1: //deposit action from all user accounts
            switch (accountAction) //choose account
            {
            case 1:
                deposit(checkingAccount, amount);
                break;
            case 2:
                deposit(savingsAccount, amount);
                break;
            case 3:
                deposit(creditAccount, amount);
                break;
            default:
                break;
            }
            break;
        case 2: //withdraw action from all user accounts
            switch (accountAction) //choose account
            {
            case 1:
                withdraw(checkingAccount, amount);
                break;
            case 2:
                withdraw(savingsAccount, amount);
                break;
            case 3:
                withdraw(creditAccount, amount);
                break;
            default:
                break;
            }
            break;
        default:
            std::cout << "Invalid transaction or account action, Emperor Palpatine is disapointed in your choice, try Again. " << std::endl;
        }
    }
    
    //declare a vector called balances to store the account balances from each of the accounts, using of stream write to the Binary.bin file and push the balances of each account to the balances vector. Using a for range loop write the balances to the binary.bin file and close the file when done. If the write fail;s, notify the user with "Cannot open the Binary.bin for writing..." message via consoleout statement. 
    std::vector<float> balances;

    std::ofstream writeFile("Binary.bin", std::ios::binary);

    balances.push_back(checkingAccount->GetBalance());
    balances.push_back(savingsAccount->GetBalance());
    balances.push_back(creditAccount->GetBalance());


    if (writeFile.is_open())
    {
        for (float balance : balances)
        {
            writeFile.write((char*)&balance, sizeof(float));
        }
    
        writeFile.close();
    }
    else
    {
        std::cerr << "Cannot open the Binary.bin for writing..." << std::endl;
    }

    //clean up memory
    delete checkingAccount;
    delete savingsAccount;
    delete creditAccount;

}