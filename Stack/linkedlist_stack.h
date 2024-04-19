#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H
#include "Public.h"
typedef struct StackNode {
	ElemType data;
	struct StackNode* next;
}StackNode,*LinkStackPtr;
typedef struct {
	LinkStackPtr top;
	int count;
}LinkedStack;
Status InitStack(LinkedStack*s);
Status ClearStack(LinkedStack* s);
Status DestroyStack(LinkedStack* s);
int StackEmpty(LinkedStack* s);
Status Push(LinkedStack* s, ElemType e);
Status Pop(LinkedStack* s, ElemType& e);
int StackOfLength(LinkedStack* s);
Status StackTraverse(LinkedStack* s);
Status GetTop(LinkedStack* s, ElemType& e);
#endif // !LINKEDLISTSTACK_H