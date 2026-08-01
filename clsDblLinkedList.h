#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class clsDblLinkedList
{
public:

	struct Node
	{
		T value;
		Node* next = nullptr;
		Node* prev = nullptr;
	};

private:
	Node* _head = nullptr;
	Node* _tail = nullptr;
	int _size = 0;



public:

	/*clsDblLinkedList()
	{
		_head = nullptr;
		_tail = nullptr;
		_size = 0;
	}*/
	clsDblLinkedList() = default;

	~clsDblLinkedList()
	{
		Clear();
	}

	T GetHeadValue() const
	{
		return (_head == nullptr) ? T() : _head->value; // T() == Default Value / Default Constructor Call
	}
	T GetTailValue() const
	{
		return (_tail == nullptr) ? T() : _tail->value;
	}


	size_t Size() const // const = Read-Only Observer
	{
		return _size;
	}

	bool IsEmpty() const
	{
		return (_size == 0);
	}

	void InsertAtBeginning(T value)
	{
		Node* newNode = new Node();
		newNode->value = value;
		newNode->prev = nullptr;
		newNode->next = _head;

		if (_head != nullptr)
			_head->prev = newNode;
		else _tail = newNode;


		_head = newNode;
		_size++;
	}

	void PrintList(string Separator = "  ")
	{
		Node* temp = _head;
		while (temp != nullptr)
		{
			cout << temp->value << Separator;
			temp = temp->next;
		}
		cout << endl;
	}
	void PrintListDetails(string Separator = " <--> ")
	{
		Node* temp = _head;

		cout << "NULL" << Separator;
		while (temp != nullptr)
		{
			cout << temp->value << Separator;
			temp = temp->next;
		}
		cout << "NULL\n";
	}


	Node* Find(T value)
	{
		Node* temp = _head;
		while (temp != nullptr)
		{
			if (temp->value == value) return temp;
			temp = temp->next;
		}
		return nullptr;
	}

	void InsertAfter(Node*& current, T value)
	{
		if (current == nullptr) return;

		if (current == _tail)
		{
			InsertAtEnd(value);
			return;
		}

		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = current->next;
		newNode->prev = current;

		if (current->next != nullptr) current->next->prev = newNode;

		current->next = newNode;
		_size++;
	}



	void InsertAtEnd(T value)
	{
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = nullptr;

		if (_head == nullptr)
		{
			newNode->prev = nullptr;
			_head = newNode;
			_tail = newNode;
			_size++;
			return;
		}

		//Node* current = _head;
		////find next null node //O(n)
		//while (current->next != nullptr) current = current->next;
		//current->next = newNode;
		//newNode->prev = current;
		//_size++;

		//O(1) using tail
		newNode->prev = _tail;
		_tail->next = newNode;
		_tail = newNode;
		_size++;
	}

	void DeleteFirstNode()
	{
		if (_head == nullptr) return;

		Node* temp = _head;
		_head = _head->next;
		if (_head != nullptr)
			_head->prev = nullptr;
		else _tail = nullptr;

		delete temp;
		_size--;
	}

	void DeleteLastNode()
	{
		if (_head == nullptr) return;

		/*if (_head->next == nullptr)
		{
			delete _head;
			_head = nullptr;
			return;
		}
		Node* current = _head;
		//O(n)
		while (current->next->next != nullptr) current = current->next;

		delete current->next;
		current->next = nullptr;
		_size--;*/

		//Had only one node
		if (_head == _tail)
		{
			delete _head;
			_head = nullptr;
			_tail = nullptr;
			_size--;
			return;
		}

		//O(1) Using tail
		Node* temp = _tail;
		_tail = _tail->prev;
		_tail->next = nullptr;

		delete temp;
		_size--;
	}


	void DeleteNode(Node*& NodeToDelete)
	{
		if (_head == nullptr || NodeToDelete == nullptr) return;

		if (_head == NodeToDelete) _head = NodeToDelete->next;
		
		if (_tail == NodeToDelete)
			_tail = NodeToDelete->prev;
		
		if (NodeToDelete->next != nullptr)
			NodeToDelete->next->prev = NodeToDelete->prev;

		if (NodeToDelete->prev != nullptr)
			NodeToDelete->prev->next = NodeToDelete->next;

		delete NodeToDelete;
		NodeToDelete = nullptr;
		_size--;
	}
	void Clear()
	{
		/*while (_size > 0)
			DeleteFirstNode();

		_head = nullptr;
		_tail = nullptr;*/
		while (!IsEmpty()) DeleteFirstNode();
	}

	void Reverse()
	{
		if (_head == nullptr || _size == 1) return;

		Node* current = _head;
		Node* temp = nullptr;

		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}

		_tail = _head;
		_head = temp->prev;

		/*if(temp != nullptr)
		{
			_tail = _head;
			_head = temp->prev;
		}*/
	}

	Node* GetNode(size_t index)
	{
		if (index < 0 || index >= _size) return nullptr; // throw nullptr exception

		// O(N/2)
		if (index < (_size / 2))
		{
			Node* temp = _head;
			for (size_t i = 0; i < index; i++)
				temp = temp->next;
			
			return temp;
		}

		Node* temp = _tail;
		for (size_t i = _size-1; i > index; i--)
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
		Node* nodeItem = GetNode(index);
		return (nodeItem == nullptr) ? T() : nodeItem->value; // T() == Default Value / Default Constructor Call
	}

	bool UpdateItem(size_t index, T value)
	{
		Node* node = GetNode(index);
		
		if (node != nullptr)
		{
			node->value = value;
			return true;
		}
		return false;
	}

	bool InsertAfter(size_t index, T value)
	{
		Node* node = GetNode(index);
		if (node != nullptr)
		{
			InsertAfter(node, value);
			return true;
		}
			return false;
	}


};
