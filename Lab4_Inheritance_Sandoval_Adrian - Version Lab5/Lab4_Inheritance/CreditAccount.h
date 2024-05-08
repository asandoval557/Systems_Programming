#pragma once
#include "BaseAccount.h"

class CreditAccount :
    public BaseAccount
{
public:
    void Withdraw(float amount) override;

private:
    int amountSpent =0;
    int const spendingLimit = 40;
};

