
#include "clsMyQueue.h"
#include <iostream>

using namespace std;

int main()
{

	clsMyQueue <int> MyQueue;

	MyQueue.pushAtFirst(10);
	MyQueue.pushAtFirst(20);
	MyQueue.pushAtFirst(30);
	MyQueue.pushAtFirst(40);
	MyQueue.pushAtFirst(50);


	cout << "\nQueue: \n";
	MyQueue.Print();

	cout << "\nQueue Size: " << MyQueue.Size();
	cout << "\nQueue Front: " << MyQueue.front();
	cout << "\nQueue Back: " << MyQueue.back();

	MyQueue.pop();

	cout << "\n\nQueue after pop() : \n";
	MyQueue.Print();





	system("pause>0");

}