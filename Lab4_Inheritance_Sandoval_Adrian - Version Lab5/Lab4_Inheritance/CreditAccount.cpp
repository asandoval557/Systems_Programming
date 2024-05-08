#include "CreditAccount.h"
#include <iostream>

//withdraw function from credit account when the user withdraws more than $40, there will be a $5000 fee applied to the account
void CreditAccount::Withdraw(float amount)
{
	if (amountSpent + amount > spendingLimit)
	{
		accountBalance -= 5000;
		std::cout << "You have exceed the $40.00 purchase limit of you credit account. A fee of $5,0000.00 has been applied to your account." << std::endl;
	}
	else
	{
		amountSpent += amount;
	}
	BaseAccount::Withdraw(amount);

	
}
