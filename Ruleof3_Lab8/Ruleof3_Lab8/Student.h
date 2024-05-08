#pragma once
#include "Base.h"
class Student :
    public Base
{
public:
    //Default constructor
    Student() {}
    //
    Student(const char* name, float gpa)
    {
        SetName(name);
        SetGPA(gpa);
    }
    //GPA Setter
    void SetGPA(float GPA)
    {
        gpa = GPA;
    }
    //GPA Accessor
    float GetGPA() const
    {
        return gpa;
    }

    //Display function
    void DisplayRecord() override;

private:
    float gpa = 0;
};

