#include "TriangleHeap.h"

TriangleHeap& TriangleHeap::operator=(const TriangleHeap& other)
{
    if (this != &other)
    {
        delete mBase;
        delete mHeight;

        mBase = new float(*other.mBase);
        mHeight = new float(*other.mHeight);
    }
    return *this;
}

float TriangleHeap::GetArea() const
{
    return *mBase * *mHeight / 2.0f;
}
