#pragma once
#include "clsDblLinkedList.h"
#include <string>

using namespace std;

template <class T>
class clsMyQueue
{
protected: clsDblLinkedList<T> _myList; // Composition / Wrapper

public:

	void push(T item)
	{
		_myList.InsertAtEnd(item);
	}

	void pop() 
	{
		_myList.DeleteFirstNode();
	}

	void Print(string Separator = "  ")
	{
		_myList.PrintList(Separator);
	}

	size_t Size() const
	{
		return _myList.Size();
	}

	bool IsEmpty() const
	{
		return _myList.IsEmpty();
	}

	T front() const
	{
		return _myList.GetHeadValue();
		//		return _MyList.GetItem(0);
	}

	T back() const
	{
		return _myList.GetTailValue();
		//		return _myList.GetItem(Size() - 1);
	}

};


