#ifndef SEQUENCESTACK_H
#define SEQUENCESTACK_H
#include "Public.h"
typedef struct {
	ElemType data[kMaxSize];
	int top;
}SqStack;
SqStack* InitStack();
Status DestroyStack(SqStack* s);
Status ClearStack(SqStack* s);
int StackEmpty(SqStack* s);
Status Push(SqStack* s, ElemType e);
Status Pop(SqStack* s, ElemType& e);
int StackOfLength(SqStack* s);
Status StackTraverse(SqStack* s);
Status GetTop(SqStack* s, ElemType& e);
#endif // !SEQUENCESTACK_H