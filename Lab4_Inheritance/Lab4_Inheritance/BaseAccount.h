#pragma once

class BaseAccount
{
public:
	virtual void Withdraw(float amount);
	virtual void Deposit(float amount);
	float GetBalance() const;


protected:
	float accountBalance = 0;
	int withdrawals = 0;

};

