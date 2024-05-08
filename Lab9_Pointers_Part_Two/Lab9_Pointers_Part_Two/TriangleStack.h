#pragma once

class TriangleStack
{
public:
	//Default Constructor
	TriangleStack() : mBase(0.0f), mHeight(0.0f) {};

	//Destructor
	~TriangleStack() {};


	//Setters for member fields
	void setBase(float base)
	{
		mBase = base;
	}
	void setHeight(float height)
	{
		mHeight = height;
	}


	//GetArea() Function
	float GetArea() const;


private:
	float mBase = 0;
	float mHeight= 0;
};

