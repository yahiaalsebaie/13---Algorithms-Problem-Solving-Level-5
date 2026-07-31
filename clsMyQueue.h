#pragma once
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

template <class T>
class clsMyQueue
{
public:

	struct Queue
	{
		T value;
		Queue* next = nullptr;
		Queue* prev = nullptr;
	};

private:
	Queue* _front = nullptr;
	Queue* _back = nullptr;
	int _size = 0;

public:
	clsMyQueue()
	{
		_front = nullptr;
		_back = nullptr;
		_size = 0;
	}

	~clsMyQueue()
	{
		Clear();
	}

	int Size() const // const = Read-Only Observer
	{
		return _size;
	}

	bool IsEmpty() const
	{
		return (_size == 0);
	}

	T front() const
	{
		return	_front->value;
	}

	T back() const
	{
		return	_back->value;
	}

	void pushAtFirst(T value)
	{
		Queue* newQueue = new Queue();
		newQueue->value = value;
		newQueue->prev = nullptr;
		newQueue->next = _front;

		if (_front != nullptr)
			_front->prev = newQueue;
		else _back = newQueue;


		_front = newQueue;
		_size++;
	}

	void Print(string Separator = "  ")
	{
		Queue* temp = _front;
		while (temp != nullptr)
		{
			cout << temp->value << Separator;
			temp = temp->next;
		}
		cout << endl;
	}
	void PrintDetails(string Separator = " <--> ")
	{
		Queue* temp = _front;

		cout << "NULL" << Separator;
		while (temp != nullptr)
		{
			cout << temp->value << Separator;
			temp = temp->next;
		}
		cout << "NULL\n";
	}


	Queue* Find(T value)
	{
		Queue* temp = _front;
		while (temp != nullptr)
		{
			if (temp->value == value) return temp;
			temp = temp->next;
		}
		return nullptr;
	}

	void pushAfter(Queue*& current, T value)
	{
		if (current == nullptr) return;

		if (current == _back)
		{
			pushAtEnd(value);
			return;
		}

		Queue* newQueue = new Queue();
		newQueue->value = value;
		newQueue->next = current->next;
		newQueue->prev = current;

		if (current->next != nullptr) current->next->prev = newQueue;

		current->next = newQueue;
		_size++;
	}



	void pushAtEnd(T value)
	{
		Queue* newQueue = new Queue();
		newQueue->value = value;
		newQueue->next = nullptr;

		if (_front == nullptr)
		{
			newQueue->prev = nullptr;
			_front = newQueue;
			_back = newQueue;
			_size++;
			return;
		}

		//Queue* current = _front;
		////find next null Queue //O(n)
		//while (current->next != nullptr) current = current->next;
		//current->next = newQueue;
		//newQueue->prev = current;
		//_size++;

		//O(1) using tail
		newQueue->prev = _back;
		_back->next = newQueue;
		_back = newQueue;
		_size++;
	}

	void pop()
	{
		if (_front == nullptr) return;

		Queue* temp = _front;
		_front = _front->next;
		if (_front != nullptr)
			_front->prev = nullptr;
		else _back = nullptr;

		delete temp;
		_size--;
	}

	void DeleteLastQueue()
	{
		if (_front == nullptr) return;

		/*if (_front->next == nullptr)
		{
			delete _front;
			_front= nullptr;
			return;
		}
		Queue* current = _front;
		//O(n)
		while (current->next->next != nullptr) current = current->next;

		delete current->next;
		current->next = nullptr;
		_size--;*/

		//Had only one Queue
		if (_front == _back)
		{
			delete _front;
			_front == nullptr;
			_back == nullptr;
			_size--;
		}

		//O(1) Using tail
		Queue* temp = _back;
		_back = _back->prev;
		_back->next = nullptr;

		delete temp;
		_size--;
	}


	void DeleteQueue(Queue*& QueueToDelete)
	{
		if (_front == nullptr || QueueToDelete == nullptr) return;

		if (_front == QueueToDelete) _front = QueueToDelete->next;

		if (QueueToDelete->next != nullptr)
			QueueToDelete->next->prev = QueueToDelete->prev;

		if (QueueToDelete->prev != nullptr)
			QueueToDelete->prev->next = QueueToDelete->next;

		delete QueueToDelete;
		QueueToDelete = nullptr;
		_size--;
	}
	void Clear()
	{
		while (_size > 0)
			pop();

		_front = nullptr;
		_back = nullptr;
	}

	void Reverse()
	{
		if (_front == nullptr || _size == 1) return;

		Queue* current = _front;
		Queue* temp = nullptr;

		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}

		_back = _front;
		_front = temp->prev;

		/*if(temp != nullptr)
		{
			_back= _front;
			_front= temp->prev;
		}*/
	}

	Queue* GetQueue(size_t index)
	{
		if (index < 0 || index >= _size) return nullptr; // throw nullptr exception

		// O(N/2)
		if (index < (_size / 2))
		{
			Queue* temp = _front;
			for (size_t i = 0; i < index; i++)
				temp = temp->next;

			return temp;
		}

		Queue* temp = _back;
		for (size_t i = _size - 1; i > index; i--)
		{
			temp = temp->prev;
		}
		return temp;

		//O(N)
		/*size_t count = 0;

		while (count != index)
		{
			count++;
			temp = temp->next;
		}
		return temp;*/
	}

	T GetItem(size_t index)
	{
		Queue* QueueItem = GetQueue(index);
		return (QueueItem == nullptr) ? T() : QueueItem->value; // T() == Default Value / Default Constructor Call
	}

	bool UpdateItem(size_t index, T value)
	{
		Queue* Queue = GetQueue(index);

		if (Queue != nullptr)
		{
			Queue->value = value;
			return true;
		}
		return false;
	}

	bool pushAfter(size_t index, T value)
	{
		Queue* Queue = GetQueue(index);
		if (Queue != nullptr)
		{
			pushAfter(Queue, value);
			return true;
		}
		return false;
	}
};
