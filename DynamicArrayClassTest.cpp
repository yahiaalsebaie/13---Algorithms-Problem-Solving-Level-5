#include "clsDynamicArray.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	cout << "==================================================\n";
	cout << "      TESTING CLSDYNAMICARRAY IMPLEMENTATION      \n";
	cout << "==================================================\n\n";

	// 1. Creation & Initial Setup
	cout << "[1] Creating Dynamic Array with size 5...\n";
	clsDynamicArray<int> MyArray(5);

	cout << "Is Empty? " << (MyArray.IsEmpty() ? "Yes" : "No") << "\n";
	cout << "Current Size: " << MyArray.Size() << "\n";

	// Filling Array with SetItem
	for (size_t i = 0; i < MyArray.Size(); i++)
	{
		MyArray.SetItem(i, (i + 1) * 10);
	}
	cout << "Array Items: ";
	cout << "\n"; 	MyArray.PrintList();

	cout << "\n--------------------------------------------------\n";

	// 2. Testing Accessors (GetItem, Find)
	cout << "[2] Testing GetItem & Find...\n";
	cout << "Item at index 2: " << MyArray.GetItem(2) << "\n";
	cout << "Item at out-of-bounds index 10: " << MyArray.GetItem(10) << " (Returns default value T())\n";

	int searchVal = 30;
	int index = MyArray.Find(searchVal);
	if (index != -1)
		cout << "Value " << searchVal << " found at index: " << index << "\n";
	else
		cout << "Value " << searchVal << " not found!\n";

	cout << "\n--------------------------------------------------\n";

	// 3. Testing Insert Methods
	cout << "[3] Testing Insertion Methods...\n";

	MyArray.InsertAtBeginning(5);
	cout << "After InsertAtBeginning(5): ";
	cout << "\n";
	cout << "\n"; 	MyArray.PrintList();

	MyArray.InsertAtEnd(60);
	cout << "After InsertAtEnd(60): ";
	cout << "\n"; 	MyArray.PrintList();

	MyArray.InsertAt(3, 25);
	cout << "After InsertAt(index 3, value 25): ";
	cout << "\n"; 	MyArray.PrintList();

	MyArray.InsertBefore(2, 15);
	cout << "After InsertBefore(index 2, value 15): ";
	cout << "\n"; 	MyArray.PrintList();

	MyArray.InsertAfter(4, 35);
	cout << "After InsertAfter(index 4, value 35): ";
	cout << "\n"; 	MyArray.PrintList();

	cout << "Current Size: " << MyArray.Size() << "\n";

	cout << "\n--------------------------------------------------\n";

	// 4. Testing Reverse
	cout << "[4] Testing Reverse...\n";
	MyArray.Reverse();
	cout << "Array after Reverse(): ";
	cout << "\n"; 	MyArray.PrintList();

	cout << "\n--------------------------------------------------\n";

	// 5. Testing Delete Methods
	cout << "[5] Testing Deletion Methods...\n";

	MyArray.DeleteFirstItem();
	cout << "After DeleteFirstItem(): ";
	cout << "\n"; 	MyArray.PrintList();

	MyArray.DeleteLastItem();
	cout << "After DeleteLastItem(): ";
	cout << "\n"; 	MyArray.PrintList();

	MyArray.DeleteItemAt(2);
	cout << "After DeleteItemAt(index 2): ";
	cout << "\n"; 	MyArray.PrintList();

	MyArray.DeleteItem(25);
	cout << "After DeleteItem(value 25): ";
	cout << "\n"; 	MyArray.PrintList();

	cout << "Current Size: " << MyArray.Size() << "\n";

	cout << "\n--------------------------------------------------\n";

	// 6. Testing Resize
	cout << "[6] Testing Resize...\n";

	MyArray.Resize(10);
	cout << "After Resize(10): ";
	cout << "\n"; 	MyArray.PrintList();
	cout << "New Size: " << MyArray.Size() << "\n";

	MyArray.Resize(3);
	cout << "After Resize(3) [Truncating]: ";
	cout << "\n"; 	MyArray.PrintList();
	cout << "New Size: " << MyArray.Size() << "\n";

	cout << "\n--------------------------------------------------\n";

	// 7. Testing Clear & Edge Cases
	cout << "[7] Testing Clear & Edge Cases...\n";

	MyArray.Clear();
	cout << "After Clear():\n";
	cout << "Is Empty? " << (MyArray.IsEmpty() ? "Yes" : "No") << "\n";
	cout << "Size: " << MyArray.Size() << "\n";

	// Trying operations on empty array
	cout << "Trying to DeleteItem from empty array: " << (MyArray.DeleteItem(10) ? "Success" : "Failed (Safe)") << "\n";

	// Re-inserting into cleared array
	MyArray.InsertAtEnd(100);
	cout << "After InsertAtEnd(100) on cleared array: ";
	cout << "\n"; 	MyArray.PrintList();

	cout << "\n==================================================\n";
	cout << "           ALL TESTS COMPLETED SUCCESSFULLY        \n";
	cout << "==================================================\n";

	system("pause>0");
	return 0;
}