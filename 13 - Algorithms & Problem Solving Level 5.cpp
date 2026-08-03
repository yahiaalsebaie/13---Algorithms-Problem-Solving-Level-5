#include "clsDblLinkedList.h"
#include "clsDynamicArray.h"
#include "clsMyQueue.h"
#include "clsMyQueueArr.h"
#include "clsMyStack.h"
#include "clsMyStackArr.h"
#include "clsQueueLine.h"
#include "clsString.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==================== HELPER FUNCTIONS ====================

void PrintHeader(const string& title, int shift = 45)
{
	cout << "\n" << string(66, '=') << endl;
	cout << setw(shift) << right << title << endl;
	cout << string(66, '=') << endl;
}

void PrintMenu(const string& title, const vector<string>& options)
{
	PrintHeader(title);
	for (size_t i = 0; i < options.size(); i++)
	{
		cout << "  [" << (i + 1) << "] " << options[i] << endl;
	}
	cout << "\n  Choose an option: ";
}

// ==================== DYNAMIC ARRAY DEMO ====================

void DemoDynamicArray()
{
	PrintHeader("DYNAMIC ARRAY DEMONSTRATION");

	clsDynamicArray<int> arr(5);

	cout << "\n1. Creating Dynamic Array with size 5" << endl;
	cout << "   Array Size: " << arr.Size() << endl;

	cout << "\n2. Adding elements: 10, 20, 30, 40, 50" << endl;
	for (int i = 0; i < 5; i++)
	{
		arr.SetItem(i, (i + 1) * 10);
	}

	cout << "\n3. Printing array elements:" << endl;
	cout << "   ";
	for (int i = 0; i < arr.Size(); i++)
	{
		cout << arr.GetItem(i) << " ";
	}
	cout << endl;

	cout << "\n[OK] Dynamic Array demonstration complete!" << endl;
}

// ==================== DOUBLY LINKED LIST DEMO ====================

void DemoDoublyLinkedList()
{
	PrintHeader("DOUBLY LINKED LIST DEMONSTRATION");

	clsDblLinkedList<int> list;

	cout << "\n1. Creating empty Doubly Linked List" << endl;
	cout << "   Size: " << list.Size() << endl;

	cout << "\n2. Inserting elements at end: 10, 20, 30" << endl;
	list.InsertAtEnd(10);
	list.InsertAtEnd(20);
	list.InsertAtEnd(30);
	cout << "   Size after insertion: " << list.Size() << endl;

	cout << "\n3. Printing list (Forward):" << endl;
	cout << "   ";
	list.PrintList("  ->  ");

	cout << "\n4. Inserting 15 after position 0" << endl;
	list.InsertAfter(0, 15);
	cout << "   ";
	list.PrintList("  ->  ");
	cout << "   Size: " << list.Size() << endl;

	cout << "\n[OK] Doubly Linked List demonstration complete!" << endl;
}

// ==================== QUEUE (LINKEDLIST-BASED) DEMO ====================

void DemoQueueLinkedList()
{
	PrintHeader("QUEUE (LINKEDLIST-BASED) DEMONSTRATION");

	clsMyQueue<int> queue;

	cout << "\n1. Creating empty Queue (using Doubly Linked List)" << endl;
	cout << "   Queue Size: " << queue.Size() << endl;

	cout << "\n2. Enqueuing (pushing) elements: 100, 200, 300" << endl;
	queue.push(100);
	queue.push(200);
	queue.push(300);
	cout << "   Queue Size: " << queue.Size() << endl;

	cout << "\n3. Queue contents (FIFO order):" << endl;
	cout << "   ";
	queue.Print("  ->  ");

	cout << "\n4. Dequeuing (popping) one element" << endl;
	queue.pop();
	cout << "   Remaining queue:" << endl;
	cout << "   ";
	queue.Print("  ->  ");
	cout << "   Queue Size: " << queue.Size() << endl;

	cout << "\n[OK] Queue (LinkedList-based) demonstration complete!" << endl;
}

// ==================== QUEUE (ARRAY-BASED) DEMO ====================

void DemoQueueArray()
{
	PrintHeader("QUEUE (ARRAY-BASED) DEMONSTRATION");

	clsMyQueueArr<int> queue;

	cout << "\n1. Creating Array-based Queue with capacity 5" << endl;
	cout << "   Queue Size: " << queue.Size() << endl;

	cout << "\n2. Enqueuing elements: 10, 20, 30, 40" << endl;
	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);
	cout << "   Queue Size: " << queue.Size() << endl;

	cout << "\n3. Queue contents:" << endl;
	cout << "   ";
	queue.Print("  | ");

	cout << "\n[OK] Queue (Array-based) demonstration complete!" << endl;
}

// ==================== STACK (LINKEDLIST-BASED) DEMO ====================

void DemoStackLinkedList()
{
	PrintHeader("STACK (LINKEDLIST-BASED) DEMONSTRATION", 50);

	clsMyStack<char> stack;

	cout << "\n1. Creating empty Stack (using Doubly Linked List)" << endl;
	cout << "   Stack Size: " << stack.Size() << endl;

	cout << "\n2. Pushing elements: 'A', 'B', 'C', 'D'" << endl;
	stack.push('A');
	stack.push('B');
	stack.push('C');
	stack.push('D');
	cout << "   Stack Size: " << stack.Size() << endl;

	cout << "\n3. Stack contents (LIFO order):" << endl;
	cout << "   ";
	stack.Print("  ->  ");

	cout << "\n4. Popping (removing) one element" << endl;
	stack.pop();
	cout << "   Remaining stack:" << endl;
	cout << "   ";
	stack.Print("  ->  ");
	cout << "   Stack Size: " << stack.Size() << endl;

	cout << "\n[OK] Stack (LinkedList-based) demonstration complete!" << endl;
}

// ==================== STACK (ARRAY-BASED) DEMO ====================

void DemoStackArray()
{
	PrintHeader("STACK (ARRAY-BASED) DEMONSTRATION", 50);

	clsMyStackArr<int> stack;

	cout << "\n1. Creating Array-based Stack with capacity 5" << endl;
	cout << "   Stack Size: " << stack.Size() << endl;

	cout << "\n2. Pushing elements: 7, 14, 21, 28" << endl;
	stack.push(7);
	stack.push(14);
	stack.push(21);
	stack.push(28);
	cout << "   Stack Size: " << stack.Size() << endl;

	cout << "\n3. Stack contents:" << endl;
	cout << "   ";
	stack.Print("  | ");

	cout << "\n[OK] Stack (Array-based) demonstration complete!" << endl;
}

// ==================== CUSTOM STRING WITH UNDO/REDO DEMO ====================

void DemoCustomString()
{
	PrintHeader("CUSTOM STRING WITH UNDO/REDO ENGINE DEMONSTRATION");

	clsString str("Hello World");

	cout << "\n1. Creating string: \"Hello World\"" << endl;
	cout << "   String: " << str.Value << endl;

	cout << "\n2. String is fully customizable with Undo/Redo capabilities" << endl;
	cout << "   - Insert, Delete, Replace operations supported" << endl;
	cout << "   - Full history tracking for Undo/Redo" << endl;
	cout << "   - Memory-efficient implementation from scratch" << endl;

	cout << "\n[OK] Custom String demonstration complete!" << endl;
}

// ==================== QUEUE LINE SIMULATION DEMO ====================

void DemoQueueLine()
{
	PrintHeader("QUEUE LINE SYSTEM SIMULATION DEMONSTRATION", 55);

	clsQueueLine queueLine("A", 5);

	cout << "\n1. Creating Queue Line System" << endl;
	cout << "   Prefix: A | Average Service Time: 5 minutes" << endl;

	cout << "\n2. IssueTicket() - System generates unique ticket numbers" << endl;
	queueLine.IssueTicket();
	queueLine.IssueTicket();
	cout << "   Tickets Issued: 2" << endl;
	cout << "   Waiting Clients: " << queueLine.WaitingClients() << endl;

	cout << "\n3. Key Features:" << endl;
	cout << "   - Automatic ticket generation" << endl;
	cout << "   - Customer arrival tracking" << endl;
	cout << "   - Service time measurement" << endl;
	cout << "   - Queue statistics and analytics" << endl;

	cout << "\n[OK] Queue Line System demonstration complete!" << endl;
}

// ==================== MAIN MENU ====================

int main()
{
	//system("color 0A");  // Dark background with bright green text

	PrintHeader("CUSTOM C++ DATA STRUCTURES & ALGORITHMS LIBRARY (LEVEL 5)");

	cout << "\n  Welcome to the Data Structures & Algorithms Explorer!" << endl;
	cout << "\n  This project demonstrates 8 fundamental data structures" << endl;
	cout << "  implemented COMPLETELY FROM SCRATCH using OOP principles," << endl;
	cout << "  without relying on STL container shortcuts." << endl;

	cout << "\n  [OK] Dynamic Arrays (automatic resizing)." << endl;
	cout << "  [OK] Doubly Linked Lists (bidirectional traversal)." << endl;
	cout << "  [OK] Queues (LinkedList-based and Array-based)." << endl;
	cout << "  [OK] Stacks (LinkedList-based and Array-based)." << endl;
	cout << "  [OK] Custom Strings with Undo/Redo Engine." << endl;
	cout << "  [OK] Queue Line Simulation System." << endl;

	cout << "\n  Please read the [ABOUT THIS PROJECT] section." << endl;

	bool running = true;
	while (running)
	{
		vector<string> mainOptions = {
			"Dynamic Array",
			"Doubly Linked List",
			"Queue (LinkedList-based)",
			"Queue (Array-based)",
			"Stack (LinkedList-based)",
			"Stack (Array-based)",
			"Custom String with Undo/Redo",
			"Queue Line System Simulation",
			"About This Project",
			"Exit"
		};

		PrintMenu("MAIN MENU - SELECT A DATA STRUCTURE TO EXPLORE", mainOptions);

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			DemoDynamicArray();
			break;

		case 2:
			DemoDoublyLinkedList();
			break;

		case 3:
			DemoQueueLinkedList();
			break;

		case 4:
			DemoQueueArray();
			break;

		case 5:
			DemoStackLinkedList();
			break;

		case 6:
			DemoStackArray();
			break;

		case 7:
			DemoCustomString();
			break;

		case 8:
			DemoQueueLine();
			break;

		case 9:
		{
			PrintHeader("ABOUT THIS PROJECT", 40);

			cout << "\n  PROJECT INFORMATION:" << endl;
			cout << "  This repository contains my solutions and implementations" << endl;
			cout << "  for Course #13: Algorithms & Problem Solving Level 5" << endl;
			cout << "  from Programming Advices." << endl;

			cout << "\n  COURSE LINK:" << endl;
			cout << "  https://programmingadvices.com/courses/13-algorithms-problem-solving-level-5/" << endl;

			cout << "\n  IMPLEMENTATION PHILOSOPHY:" << endl;
			cout << "  All core data structures are implemented completely from scratch" << endl;
			cout << "  to understand their internal implementation and memory management." << endl;

			cout << "\n  PROJECT STRUCTURE:" << endl;
			cout << "  * Every header file (clsXXX.h) has its own dedicated" << endl;
			cout << "    test/demo source file (XXXTest.cpp)." << endl;
			cout << "  * The examples shown by this application are only a quick overview." << endl;
			cout << "  * They DO NOT replace exploring and running the individual" << endl;
			cout << "    test files, which contain many additional examples and scenarios." << endl;

			cout << "\n  STL NOTE:" << endl;
			cout << "  If you find an implementation that uses STL containers" << endl;
			cout << "  (such as queue or stack), check the previous commit." << endl;
			cout << "  The previous commit demonstrates the same project" << endl;
			cout << "  implemented without STL using custom data structures." << endl;

			cout << "\n  EXAMPLES:" << endl;
			cout << "  * QueueLine v3 (Class clsTicket + STL queue/stack)" << endl;
			cout << "    Commit: b64e10e4" << endl;

			cout << "  * QueueLine v2 (Custom Queue + struct stTicket)" << endl;
			cout << "    Commit: 706110db" << endl;

			cout << "  * QueueLine v1" << endl;
			cout << "    Commit: 8de42623" << endl;

			cout << "\n  REPOSITORY:" << endl;
			cout << "  https://github.com/yahiaalsebaie/CppDataStructuresFromScratch" << endl;

			cout << "\n  RELATED PROJECTS:" << endl;
			cout << "  You can explore more of my C++ learning journey,\n";
			cout << "  including building custom libraries and classes from scratch," << endl;
			cout << "  through the following repositories:" << endl;

			cout << "\n  * MyCppToolboxLibraries" << endl;
			cout << "    Custom C++ libraries and reusable components built from scratch." << endl;
			cout << "    https://github.com/yahiaalsebaie/MyCppToolboxLibraries" << endl;

			cout << "\n  * Bank System (OOP)" << endl;
			cout << "    Object-Oriented Banking System with integrated Currency Exchange." << endl;
			cout << "    https://github.com/yahiaalsebaie/Bank-System-OOP" << endl;

			cout << "\n  * Bank Management System (Procedural Programming)" << endl;
			cout << "    Banking System implemented using Procedural Programming." << endl;
			cout << "    https://github.com/yahiaalsebaie/Bank-Management-System-Cpp" << endl;

			cout << "\n  * ATM System" << endl;
			cout << "    ATM simulation project from Course #8." << endl;
			cout << "    https://github.com/yahiaalsebaie/ATM-System-Course08" << endl;

			cout << "\n  * Dual Calendar System" << endl;
			cout << "    Gregorian & Hijri calendar with date calculations," << endl;
			cout << "    astronomical conversions, date arithmetic and comparisons." << endl;
			cout << "    https://github.com/yahiaalsebaie/Dual-Calendar-System-MiladiAndHijiri" << endl;

			cout << "\n  * Math Game" << endl;
			cout << "    Console-based educational math game." << endl;
			cout << "    https://github.com/yahiaalsebaie/cpp-Math-Game" << endl;

			cout << "\n  * Stone Paper Scissors Game" << endl;
			cout << "    Classic console game implemented in C++." << endl;
			cout << "    https://github.com/yahiaalsebaie/stone-paper-scissors-cpp-game" << endl;

			cout << "\n[OK] Information displayed!" << endl;
			break;
		}

		case 10:
		{
			PrintHeader("EXIT");
			cout << "\n  Thank you for exploring My Data Structures Library!" << endl;
			cout << "  Keep learning and mastering C++!\n" << endl;
			running = false;
			break;
		}

		default:
			cout << "\n  [X] Invalid choice! Please enter a number between 1 and 10." << endl;
		}

		if (running && choice >= 1 && choice <= 9)
		{
			cout << "\n  Press Enter to continue...";
			cin.ignore();
			cin.get();
		}
	}

	return 0;
}

