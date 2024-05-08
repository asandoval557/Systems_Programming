#include "BaseAccount.h"

void BaseAccount::Withdraw(float amount)
{
	// decreases balance by amount
	accountBalance -=  amount;
	
	// adds to number of withdrawals
	withdrawals++;
}

//deposit and getbalance base functions that will be called later in lab4_inheritance.cpp
void BaseAccount::Deposit(float amount)
{
	accountBalance += amount;
}

float BaseAccount::GetBalance() const
{
	return accountBalance;
}


