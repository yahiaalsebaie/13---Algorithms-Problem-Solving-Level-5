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

	T GetItem(size_t index)
	{
		return	_myList.GetItem(index);
	}

	void Reverse()
	{
		return	_myList.Reverse();
	}


	void UpdateItem(size_t index, T value)
	{
		_myList.UpdateItem(index, value);
	}

	bool InsertAfter(size_t index, T value)
	{
		return _myList.InsertAfter(index, value);
	}

	void InsertAtFront(T value)
	{
		_myList.InsertAtBeginning(value);
	}

	void InsertAtBack(T value)
	{
		_myList.InsertAtEnd(value);
	}

	void Clear()
	{
		_myList.Clear();
	}


};


