#pragma once

#include <iostream>
#define TH template<typename Type>

template<typename Type = int>
class DList
{
private:

	struct node
	{
		node* next, * prev;
		Type data;

		node(Type& _data, node* _prev) : data(_data), prev(_prev), next(nullptr) {}
	};

	int count;
	node* first, * last;

public:
	DList() { first = last = nullptr; count = 0; }
	~DList();

	int GetCount() { return count; }

	void push_back(Type _data);

	Type& operator[](int _index);
	const Type& operator[](int _index) const;

	void Clear();
	void Push_Front(Type _data);
	void Erase(int _index);

};



TH
void DList<Type>::push_back(Type _data)
{
	node* n = new node(_data, last);

	if (last)
		last->next = n;
	else
		first = n;

	last = n;

	++count;
}

template<typename Type>
DList<Type>::~DList()
{
	Clear();
}

template<typename Type>
Type& DList<Type>::operator[](int _index)
{
	node* temp = first;

	int i = 0;
	for (; i < _index; ++i)
		temp = temp->next;

	return temp->data;
}

template<typename Type>
const Type& DList<Type>::operator[](int _index) const
{
	node* temp = first;

	int i = 0;
	for (; i < _index; ++i)
		temp = temp->next;

	return temp->data;
}


template<typename Type>
inline void DList<Type>::Clear()
{
	//Start with the first node
	//using Uppercase N as a quick reference to node* n in the construtor
	node* N = first;
	// Delete the current node
	while (N != nullptr)
	{
		// Store the next node before deleting the current node
		node* next = N->next;
		// Delete the current node
		delete N;
		// Move to the next node
		N = next;
	}
	// Reset list state
	first = nullptr;
	last = nullptr;
	count = 0;
}


template<typename Type>
inline void DList<Type>::Push_Front(Type _data)
{
	// Create a new node with the specified data and no previous node
	node* n = new node(_data, nullptr);
	// If the list is empty, set both first and last pointers to the new node
	if (first == nullptr)
	{
		first = n;
		last = n;
	}
	// If the list is not empty, insert the new node at the beginning
	else
	{
		// Link the new node to the old first node
		n->next = first;
		// Link the old first node to the new node
		first->prev = n;
		// Update the first pointer to the new node
		first = n;
	}
	// Increment the count of elements in the list
	++count;
}

template<typename Type>
inline void DList<Type>::Erase(int _index)
{
	// Check if the index is out of bounds
	if (_index < 0 || _index >= count)
	{
		std::cerr << "Index is out of bounds" << std::endl;
	}
	// If the list contains only one node
	if (count == 1)
	{
		delete first;
		first = nullptr;
		last = nullptr;
		count = 0;
	}
	// If deleting the first node
	if (_index == 0)
	{
		node* temp = first;
		first = first->next;
		first->prev = nullptr;
		delete temp;
		--count;
	}
	// If deleting the last node
	if (_index == count - 1)
	{
		node* temp = last;
		last = last->prev;
		last->next = nullptr;
		delete temp;
		--count;
	}
	// Deleting a node from the middle of the list
	node* current = first;
	for(int i = 0; i < _index; ++i)
		current = current->next;
	// Adjust pointers of neighboring nodes to bypass the node to be deleted
	current->prev->next = current->next;
	current->next->prev = current->prev;

	// Delete the node at the specified index
	delete current;

	// Decrement the count of elements in the list
	--count;

}


