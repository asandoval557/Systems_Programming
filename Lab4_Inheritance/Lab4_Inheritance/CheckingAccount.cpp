#include "CheckingAccount.h"
#include <iostream>

void CheckingAccount::Withdraw(float amount)
{
	/*Condition checking if # of withdrawals is more than 10 then a $5 fee will be applied to the account. When the fee is applied their is a notification informing the user of the fee.*/
	if (withdrawals >= 10)
	{
		accountBalance -= 5;
		std::cout << "You have exceeded 10 withdrawals and a $5.00 fee has been applied to your checking account" << std::endl;
	}
	BaseAccount::Withdraw(amount);
}
