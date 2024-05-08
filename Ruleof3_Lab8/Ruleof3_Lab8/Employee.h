#pragma once
#include "Base.h"
class Employee :
    public Base
{
public:
    //Default constructor
    Employee() {}
    //
    Employee(const char* name, int salary)
    {
        SetName(name);
        SetSalary(salary);
    }

    //Salary Setter 
    void SetSalary(int Salary)
    {
        salary = Salary;
    }

    //Salary Accessor
    int GetSalary() const
    {
        return salary;
    }

    //Display function
    void DisplayRecord() override;

private:
    int salary = 0;
};

