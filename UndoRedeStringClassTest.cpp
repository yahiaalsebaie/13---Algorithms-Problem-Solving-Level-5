
#include "clsMyString.h"
#include <iostream>

using namespace std;

int main()
{

	cout << "\n\n\t\t\t\t\t\t Undo/Redo Project\n\n";

	clsMyString S1;

	cout << "\nS1  = " << S1.Value << "\n";

	S1.Value = "Mohammed";

	cout << "S1  = " << S1.Value << "\n";

	S1.Value = "Mohammed2";

	cout << "S1  = " << S1.Value << "\n";

	S1.Value = "Mohammed3";

	cout << "S1  = " << S1.Value << "\n";

	cout << "\n\nUndo: ";
	cout << "\n__________\n";

	S1.Undo();
	cout << "\nS1  after undo = " << S1.Value << "\n";

	S1.Undo();
	cout << "S1  after undo = " << S1.Value << "\n";

	S1.Undo();
	cout << "S1  after undo = " << S1.Value << "\n";

	cout << "\n\nRedo: ";
	cout << "\n__________\n";

	S1.Redo();
	cout << "\nS1  after Redo = " << S1.Value << "\n";

	S1.Redo();
	cout << "S1  after Redo = " << S1.Value << "\n";

	S1.Redo();
	cout << "S1  after Redo = " << S1.Value << "\n";


	cout << "\n==================================================\n";
	cout << "           ALL TESTS COMPLETED SUCCESSFULLY        \n";
	cout << "==================================================\n";


	system("pause>0");
	return 0;
}

