#include "SavingsAccount.h"
#include <iostream>

void SavingsAccount::Withdraw(float amount)
{	/*Condition checking if # of withdrawals has exceeded the monthly limit of 3, if the number is greater than 3 then the user is notified. If the number is less than 3, the account will accept the withdrawal.*/
	if (withdrawals >= 3 )
	{
		std::cout << "We are unable to process your request at this time. Your account is limited to 3 withdrawals per month." << std::endl;
	}
	else
	{
		BaseAccount::Withdraw(amount);
	}
}
