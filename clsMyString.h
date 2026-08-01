#pragma once
#include "clsMyStack.h"
#include <string>

using namespace std;

class clsMyString
{
private:

	string _value = "";
	// clsMyString HAS two stacks. == Composition.
	// clsMyString IS NOT A Stack. No need to Inheritance.
	clsMyStack <string> _undoStack;
	clsMyStack <string> _redoStack;
	
public:
	clsMyString() = default;

	clsMyString(const string& value) { _value = value; }
	
	void SetValue(const string& value)
	{
		if (_value == value) return;

		_undoStack.push(_value);
		_value = value;
	
		while (!_redoStack.IsEmpty())
		{
			_redoStack.pop();
		}
	}
	const string& GetValue() const
	{
		/*if (_undoStack.Size() == 0) return "";
		return _undoStack.Top();*/
		return _value;
	}
	__declspec (property(get = GetValue, put = SetValue)) string Value;


	void Undo()
	{
		if (_undoStack.IsEmpty()) return;

		_redoStack.push(_value);

		_value = _undoStack.Top();
		_undoStack.pop();

	}
	void Redo()
	{
		if (_redoStack.IsEmpty()) return;
		
		_undoStack.push(_value);
		
		_value = _redoStack.Top();
		_redoStack.pop();
	}

};
