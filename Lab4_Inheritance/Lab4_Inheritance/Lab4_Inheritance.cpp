#include <iostream>
#include "BaseAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include <crtdbg.h>
#define MEMORY_LEAK_LINE
#include "Helper.h"

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

    //Initialize default balances for each account
    checkingAccount->Deposit(1500);
    savingsAccount->Deposit(10000);
    creditAccount->Deposit(1000);

    //Menu system that will allow for deposits and withdrawals to be made to the various accounts
    int transactionInput;
    int accountAction;
    float amount;
 
    
    while (true)
    {
        //Initial menu and prompting the user to choose to either deposit or withdraw
        std::cout << "\n ***************************************";
        std::cout << "\n Galactic Empire Banking Menu:\n 1. Deposit\n 2. WithDraw\n 3. Display Account Balances\n 4. Exit\n ***************************************\n Please pick from the options above: ";
        
        //brining updated banking menu that was added as part of lab5 showing account balances. 
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
        accountAction = Helper::GetValidatedInt("", 1, 3);

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
    
    //clean up memory
    delete checkingAccount;
    delete savingsAccount;
    delete creditAccount;
}