#include "Base.h"
#include <memory>

//Using the copystring function from my helper.h and adapted for ruleof3_lab
void Base::CopyString(const char* source, char*& destination)
{
    delete[] destination;

    size_t len = strlen(source) + 1;
    destination = new char[len];
    strcpy_s(destination, len, source);

}

void Base::SetName(const char* newName)
{
    if (newName != nullptr)
        CopyString(newName,name);
}

Base& Base::operator=(const Base& assignedObject)
{
    if (this != &assignedObject)
    {
        CopyString(assignedObject.name,name);
    }
    return *this;
}


