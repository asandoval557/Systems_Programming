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
	void Clear();
	void Push_Front(Type _data);
	void Erase(int index);
	//void Push_Front();
	int GetCount() { return count; }

	void push_back(Type _data);

	Type& operator[](int _index);
	const Type& operator[](int _index) const;

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
void DList<Type>::Clear()
{
	while (first)
	{
		node* temp = first;
		first = first->next;
		delete temp;
	}

	first = nullptr;
	last = nullptr;
	count = 0;
}

template<typename Type>
void DList<Type>::Push_Front(Type _data)
{
	node* Node = new node(_data);

	if (first)
	{
		Node->next = first;
		first->prev = Node;
	}
	else
	{
		last = Node;
	}

	first = Node;
	++count;
}

template<typename Type>
void DList<Type>::Erase(int index)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index out of range");
	}

	if (count == 1)
	{
		delete first;
		first = nullptr;
		last = nullptr;
	}
	else if (index == 0)
	{
		node* temp = first;
		first = first->next;
		first->prev = nullptr;
		delete temp;
	}
	else
	{
		node* current = first;
		for (int i = 0; i < index - 1; ++i)
		{
			current = current->next;
		}

		node* temp = current->next;
		current->next = temp->next;
		if (temp->next)
		{
			temp->next->prev = current;
		}
		else
		{
			last = current;
		}
		delete temp;
	}
	--count;
}
