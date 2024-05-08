#pragma once
#include "BaseAccount.h"

class SavingsAccount :
    public BaseAccount
{
    void Withdraw(float amount) override;
};

