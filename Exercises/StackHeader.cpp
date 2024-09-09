#include "StackHeader.h"
//À≥–Ú’ª
bool SequentialStack::Stack::isEmpty() const
{
	if (top == -1)
		return true;
	return false;
}

bool SequentialStack::Stack::isFull() const
{
	return top == MaxSize - 1;
}

bool SequentialStack::Stack::push(int value)
{
	if (isFull()) return false;
	data[++top] = value;
	return true;
}

bool SequentialStack::Stack::pop(int& value)
{
	if (isEmpty()) return false;
	value = data[top--];
	return true;
}