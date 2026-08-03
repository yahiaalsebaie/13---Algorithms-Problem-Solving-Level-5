
#include "clsDblLinkedList.h"
#include <cstdlib>
#include <iostream>

using namespace std;


int main()
{

	clsDblLinkedList <int> MyDblLinkedList;

	cout << "\nIs Linked List Empty ?: " << MyDblLinkedList.IsEmpty();
	cout << "\nLinked List Size: " << MyDblLinkedList.Size() << endl;

	cout << "\nAdding Content:\n";
	MyDblLinkedList.InsertAtBeginning(5);
	MyDblLinkedList.InsertAtBeginning(4);
	MyDblLinkedList.InsertAtBeginning(3);
	MyDblLinkedList.InsertAtBeginning(2);
	MyDblLinkedList.InsertAtBeginning(1);


	cout << "\nLinked List Content:\n";
	MyDblLinkedList.PrintList();
	cout << "\nLinked List Size: " << MyDblLinkedList.Size() << endl;
	cout << "\nIs Linked List Empty ?: " << MyDblLinkedList.IsEmpty() << endl;


	clsDblLinkedList<int>::Node* N;
	N = MyDblLinkedList.GetNode(2);
	cout << "\nNode with index 2 value is : " << N->value << endl;

	cout << "\nItem(2) value is : " << MyDblLinkedList.GetItem(2) << endl;


	cout << "\nAfter Updating Item(2):\n";
	MyDblLinkedList.UpdateItem(2, 300);
	MyDblLinkedList.PrintList();


	MyDblLinkedList.InsertAfter(2, 350);
	cout << "\nAfter Inserting 350 after index 3 \n";
	MyDblLinkedList.PrintList();
	cout << "\nSize: " << MyDblLinkedList.Size() << endl;

	cout << "\nLinked List Reversed Content:\n";
	MyDblLinkedList.Reverse();
	MyDblLinkedList.PrintList();
	cout << "\nLinked List Size: " << MyDblLinkedList.Size() << endl;
	cout << "\nIs Linked List Empty ?: " << MyDblLinkedList.IsEmpty();

	clsDblLinkedList<int>::Node* N1 = MyDblLinkedList.Find(2);

	if (N1 != NULL)
		cout << "\n Node with value " << N1->value << " is Found ^ _ ^ \n";
	else
		cout << "\n Node Is not found :-(\n";


	MyDblLinkedList.InsertAfter(N1, 500);
	cout << "\nAfter Inserting 500 after " << N1->value << " :\n";
	MyDblLinkedList.PrintList();
	cout << "\nSize: " << MyDblLinkedList.Size() << endl;


	MyDblLinkedList.InsertAtEnd(700);
	cout << "\nAfter Inserting 700 at end:\n";
	MyDblLinkedList.PrintList();
	cout << "\nSize: " << MyDblLinkedList.Size() << endl;

	clsDblLinkedList<int>::Node* N2 = MyDblLinkedList.Find(4);
	MyDblLinkedList.DeleteNode(N2);
	cout << "\nAfter Deleting 4:\n";
	MyDblLinkedList.PrintList();
	cout << "\nSize: " << MyDblLinkedList.Size() << endl;

	MyDblLinkedList.DeleteFirstNode();
	cout << "\nAfter Deleting First Node:\n";
	MyDblLinkedList.PrintList();
	cout << "\nSize: " << MyDblLinkedList.Size() << endl;

	cout << "\nAfter Deleting Last Node:\n";
	MyDblLinkedList.DeleteLastNode();
	MyDblLinkedList.PrintList();
	cout << "\nSize: " << MyDblLinkedList.Size() << endl;

	cout << "\nAfter Clear Linked List:\n";
	MyDblLinkedList.Clear();
	MyDblLinkedList.PrintList();
	cout << "Size: " << MyDblLinkedList.Size() << endl;
	cout << "Is Linked List Empty ?: " << MyDblLinkedList.IsEmpty();

	cout << "\n==================================================\n";
	cout << "           ALL TESTS COMPLETED SUCCESSFULLY        \n";
	cout << "==================================================\n";

	system("pause>0");
	return 0;
}
