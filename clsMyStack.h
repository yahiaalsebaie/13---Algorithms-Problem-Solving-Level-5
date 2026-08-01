#pragma once
#include "clsMyQueue.h"

using namespace std;

template <class T>
class clsMyStack : public clsMyQueue <T>
{

public:

	void push(T item)
	{
		clsMyQueue<T>::InsertAtFront(item);
	}

	
	const T& Top() const
	{
		return clsMyQueue<T>::front();
	}

	const T& Bottom() const
	{
		return clsMyQueue<T>::back();
	}

};

/* // Composition Way
template <class T>
class clsMyStack
{
private:
	clsDblLinkedList<T> _myList; // Or clsMyQueue<T> _myQueue;

public:
	void push(T item)  { _myList.InsertAtBeginning(item); }
	void pop()         { _myList.DeleteFirstNode(); }
	T Top()            { _myList.GetHeadValue(); }
	T Bottom()         { _myList.GetTailValue(); }
	bool IsEmpty()     { return _myList.IsEmpty(); }
	size_t Size()      { return _myList.Size(); }
};

*/

