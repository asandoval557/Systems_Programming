#include <iostream>
#include "TriangleStack.h"
#include "TriangleHeap.h"
#include <vector>
#include <crtdbg.h>

#define MEMORY_LEAK_LEAK -1;

//Return the sum of the datas pointed at by the two int pointers
int AddNumbersReturnInt(int* a, int* b);

//Function should not return anything but instead store the result of the sum of a and b into the data of the sum pointer
void AddNumbersReturnVoid(int a, int b, int* sum);

//This function should swap the data pointed at by both pointers.Example: a’s data is 5 and b’s data is 10 : the function will make a’s data 10 and b’s data 5.
void SwapValues(int* a, int* b);

int main()
{


    //Declare a vector<TriangleStack> and vector<TriangleHeap>
    std::vector<TriangleStack> triangleStack;
    std::vector<TriangleHeap> triangleHeap;

    //Decalare 2 TriangleStack Variables and set the base and height members to a value
    TriangleStack triangle1;
    triangle1.setBase(8.0f);
    triangle1.setHeight(9.0f);

    TriangleStack triangle2;
    triangle2.setBase(20.0f);
    triangle2.setHeight(30.0f);

    //add the two triangles to the triangleStack vector using its .push_back()
    triangleStack.push_back(triangle1);
    triangleStack.push_back(triangle2);

    //loop through the vector and print each triangle’s area to the screen
    for (const auto& triangle : triangleStack)
    {
        std::cout << "TriangleStack Area: " << triangle.GetArea() << std::endl;
    }

    //Decalare 2 TriangleHeap Variables and set the base and height members to a value
    TriangleHeap triangle3;
    triangle3.setBase(7.0f);
    triangle3.setHeight(9.0f);

    TriangleHeap triangle4;
    triangle4.setBase(15.0f);
    triangle4.setHeight(16.0f);

    //add the two triangles to the triangleStack vector using its .push_back()
    triangleHeap.push_back(triangle3);
    triangleHeap.push_back(triangle4);

    //loop through the vector and print each triangle’s area to the screen
    for (const auto& triangle : triangleHeap)
    {
        std::cout << "TriangleHeap Area: " << triangle.GetArea() << std::endl;
    }
}


int AddNumbersReturnInt(int* a, int* b)
{
    return (*a + *b);
}

void AddNumbersReturnVoid(int a, int b, int* sum)
{
    *sum = a + b;
}

void SwapValues(int* a, int* b)
{
    int swapValue = *a;
    *a = *b;
    *b = swapValue;
}
