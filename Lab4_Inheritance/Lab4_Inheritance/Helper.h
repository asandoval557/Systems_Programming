#pragma once
#include <iostream>
#include <vector>

namespace Helper {
	int GetValidatedInt(const char* strMessage, int nMinimumRange, int nMaximumRange);
	int RandomNumber(int minRange, int maxRange);
	void clearInputBuffer();
	void printBinary(int value, int* pointer);
	void printHex(int value, int* pointer);
	int printMenu(std::vector<std::string> menu);
	void CopyString(const char* source, char*& destination);
}

