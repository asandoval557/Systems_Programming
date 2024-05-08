#pragma once
class TriangleHeap
{
public:
	//Default constructor
	TriangleHeap() 
	{
		mBase = new float(0.0f);
		mHeight = new float(0.0f);
	}

	//Copy constructor
	TriangleHeap(const TriangleHeap& other) 
	{
		mBase = new float(*other.mBase);
		mHeight = new float(*other.mHeight);
	}


	//Destructor
	~TriangleHeap() 
	{
		delete mBase;
		delete mHeight;
	}

	//Copy assignment operator
	TriangleHeap& operator=(const TriangleHeap& other);

	//Setters for memberfields
	void setBase(float base)
	{
		*mBase = base;
	}

	void setHeight(float height)
	{
		*mHeight = height;
	}

	//Get area function
	float GetArea() const;


private:
	float* mBase;
	float* mHeight;
};

