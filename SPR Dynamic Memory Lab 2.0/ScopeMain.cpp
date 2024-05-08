#include "main.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <math.h>
#include "Store.h"
#include "DList.h"
#include <cassert>


// TODO
// Change this number to the line number the Output window shows you
// to follow a memory leak. Put -1 to disable.
#define MEMORY_LEAK_LINE -1

void ScopeMain()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(MEMORY_LEAK_LINE); // DO NOT COMMENT OUT THIS LINE
	_CrtDumpMemoryLeaks();

	Store* s = new Store();
	s->Print();

	delete s;

    DList<int> list;

    // Test push_back
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    assert(list.GetCount() == 3);

    // Test operator[]
    assert(list[0] == 1);
    assert(list[1] == 2);
    assert(list[2] == 3);

    // Test Push_Front
    list.Push_Front(0);
    assert(list.GetCount() == 4);
    assert(list[0] == 0);

    // Test Erase
    list.Erase(2);
    assert(list.GetCount() == 3);
    assert(list[2] == 3);

    // Test Clear
    list.Clear();
    assert(list.GetCount() == 0);
}