#pragma once
#include "clsMyQueueArr.h"

using namespace std;

template <class T>
class clsMyStackArr : public clsMyQueueArr <T>
{

public:

public:
	
	void push(T item)
	{
		clsMyQueueArr<T>::InsertAtFront(item);
	}


	T Top()
	{
		return clsMyQueueArr<T>::front();
	}

	T Bottom()
	{
		return clsMyQueueArr<T>::back();
	}

};

/* // Composition Way
template <class T>
class clsMyStackArr
{
private:
	clsDblLinkedList<T> _myList; // Or clsMyQueueArr<T> _myQueue;

public:
	void push(T item)  { _myList.InsertAtBeginning(item); }
	void pop()         { _myList.DeleteFirstNode(); }
	T Top()            { _myList.GetHeadValue(); }
	T Bottom()         { _myList.GetTailValue(); }
	bool IsEmpty()     { return _myList.IsEmpty(); }
	size_t Size()      { return _myList.Size(); }
};

*/



