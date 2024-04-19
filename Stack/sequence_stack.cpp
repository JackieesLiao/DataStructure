#include "sequence_stack.h"
#include <iostream>
SqStack* InitStack()
{
	SqStack* ret = (SqStack*)malloc(sizeof(SqStack));
	ret->top = 0;
	return ret;
}

Status DestroyStack(SqStack* s)
{
	if (s != nullptr) {
		free(s);
	}
	return OK;
}

Status ClearStack(SqStack* s)
{
	s->top = 0;
	return OK;
}

int StackEmpty(SqStack* s)
{
	if (s == nullptr) return TRUE;
	if (s->top == 0) return TRUE;
	return FALSE;
}

Status Push(SqStack* s, ElemType e)
{
	if (s == nullptr) return ERROR;
	if (s->top >= kMaxSize) return ERROR;
	s->data[s->top++] = e;
	return OK;
}

Status Pop(SqStack* s, ElemType& e)
{
	if (s == nullptr) return ERROR;
	if (s->top == 0) return ERROR;
	e = s->data[s->top - 1];
	s->top--;
	return OK;
}

int StackOfLength(SqStack* s)
{
	if (s == nullptr) return 0;
	return s->top;
}

Status StackTraverse(SqStack* s)
{
	if (s == nullptr) return ERROR;
	for (auto i = 0; i < s->top; i++) {
		if (i > 0) std::cout << "->";
		std::cout << s->data[i];
	}
	std::cout << "\n";
	return OK;
}
/// <summary>
/// ªÒ»°’ª∂•
/// </summary>
/// <param name="s"></param>
/// <param name="e"></param>
/// <returns></returns>
Status GetTop(SqStack* s, ElemType& e)
{
	if (s == nullptr) return FALSE;
	if (s->top == 0) return FALSE;
	e = s->data[s->top - 1];
	return TRUE;
}
