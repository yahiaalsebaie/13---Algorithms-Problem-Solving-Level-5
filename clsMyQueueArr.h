#pragma once
#include "clsDynamicArray.h"
#include <string>

using namespace std;

template <class T>
class clsMyQueueArr
{
protected: clsDynamicArray<T> _myArr; // Composition / Wrapper

public:

	void push(T item)
	{
		_myArr.InsertAtEnd(item);
	}

	void pop()
	{
		_myArr.DeleteFirstItem();
	}

	void Print(string Separator = "  ")
	{
		_myArr.PrintList(Separator);
	}

	size_t Size() const
	{
		return _myArr.Size();
	}

	bool IsEmpty() const
	{
		return _myArr.IsEmpty();
	}

	T front() const
	{
		//return _myArr.GetHeadValue();
				return _myArr.GetItem(0);
	}

	T back() const
	{
		//return _myArr.GetTailValue();
		return _myArr.GetItem(Size() - 1);
	}

	T GetItem(size_t index)
	{
		return	_myArr.GetItem(index);
	}

	void Reverse()
	{
		return	_myArr.Reverse();
	}


	void UpdateItem(size_t index, T value)
	{
		//_myArr.UpdateItem(index, value);
		_myArr.SetItem(index, value);
	}

	bool InsertAfter(size_t index, T value)
	{
		return _myArr.InsertAfter(index, value);
	}

	void InsertAtFront(T value)
	{
		_myArr.InsertAtBeginning(value);
	}

	void InsertAtBack(T value)
	{
		_myArr.InsertAtEnd(value);
	}

	void Clear()
	{
		_myArr.Clear();
	}

};



