#pragma once
#include "BaseAccount.h"

class CheckingAccount :
    public BaseAccount
{
    void Withdraw(float amount) override;
};

