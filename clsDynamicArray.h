#pragma once
#include <iostream>
#include <string>
#include <utility>

using namespace std;

template <class T>
class clsDynamicArray
{
protected:
	size_t _size = 0;
	T* _OriginalArray;
	T* _TempArray;

	void _Swap(T& item1, T& item2)
	{
		T temp = item1;
		item1 = item2;
		item2 = temp;
	}
public:

	clsDynamicArray(size_t size = 0)
	{
		if (size < 0) size = 0;

		_size = size;

		_OriginalArray = new T[_size];
	}

	~clsDynamicArray()
	{
		Clear();
	}

	bool SetItem(size_t index, T value)
	{
		if (index >= _size || _size < 0)
			return false;

		_OriginalArray[index] = value;
		return true;
	}

	bool IsEmpty()
	{
		return (_size == 0);
	}

	size_t Size()
	{
		return _size;
	}

	void PrintList(std::string Separator = " ")
	{
		for (size_t i = 0; i < _size; i++)
		{
			std::cout << _OriginalArray[i] << Separator;
		}
		std::cout << std::endl;
	}

	void Resize(size_t newSize)
	{
		if (newSize < 0) newSize = 0;

		_TempArray = new T[newSize];

		if (newSize < _size)
			_size = newSize;

		for (size_t i = 0; i < _size; i++)
		{
			_TempArray[i] = _OriginalArray[i];
		}

		_size = newSize;

		delete[] _OriginalArray;
		_OriginalArray = _TempArray;
	}

	T GetItem(size_t index)
	{
		return (index >= _size || _OriginalArray == nullptr) ? T() : _OriginalArray[index];
	}



	void Reverse()
	{
		if (_size <= 1 || _OriginalArray == nullptr) return;

		/*_TempArray = new T[_size];
		size_t counter = 0;

		for (size_t i = 0; i < _size; i++)
		{
			_TempArray[i] = _OriginalArray[_size - 1 - i];
		}
		delete[] _OriginalArray;
		_OriginalArray = _TempArray;*/

		//O(n/2)
		for (size_t i = 0; i < _size / 2; i++)
		{
			_Swap(_OriginalArray[i], _OriginalArray[_size - 1 - i]);
		}
	}

	void Clear()
	{
		delete[] _OriginalArray;
		_OriginalArray = nullptr;
		_size = 0;
	}

	bool DeleteItemAt(size_t index)
	{
		if (_OriginalArray == nullptr || index >= _size) return false;
		if (_size <= 1)
		{
			Clear();
			return true;
		}
		for (size_t i = index; i < _size - 1; i++)
		{
			_OriginalArray[i] = _OriginalArray[i + 1];
		}
		_size--;

		return true;
	}

	bool DeleteFirstItem()
	{
		return DeleteItemAt(0);
	}

	bool DeleteLastItem()
	{
		return DeleteItemAt(_size-1);
	}

	int Find(T value)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (_OriginalArray[i] == value) return i;
		}
		return -1;
	}

	bool DeleteItem(T value)
	{

		if (_OriginalArray == nullptr || IsEmpty() ) return false;
		
		int index =  Find(value);
		if (index == -1) return false;
		
		return DeleteItemAt(index);
		return true;
	}


};

