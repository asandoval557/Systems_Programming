#pragma once


class Base
{
public:
	//default constructor 
	Base() {};

	//copy constructor
	Base(const Base& copy) { *this = copy; }
	
	//Base Destructor
	~Base()
	{
		delete[] name;
	}

	//Functions for Base.h
	void CopyString(const char* source, char*& destination);
	
	Base& operator = (const Base& assignedObject);

	virtual void DisplayRecord() = 0;
	
	void SetName(const char* newName);

	//Accessor
	const char* GetName() const { return name; }


	
private:
	char* name = nullptr;
};

