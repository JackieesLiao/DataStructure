#include "linkedlist_stack.h"
#include <iostream>
Status InitStack(LinkedStack* s)
{
	if (s == nullptr) {
		return ERROR;
	}
	s->top = nullptr;
	s->count = 0;
	return OK;
}

Status ClearStack(LinkedStack* s)
{
	LinkStackPtr ptr{};
	if (s == nullptr) return ERROR;
	while (s->top) {
		ptr = s->top;
		s->top = s->top->next;
		free(ptr);
	}
   s->count = 0;
   return OK;
}

Status DestroyStack(LinkedStack* s)
{
	return Status();
}

int StackEmpty(LinkedStack* s)
{
	if (s == nullptr) return TRUE;
	return s->count == 0 ? TRUE : FALSE;
}

Status Push(LinkedStack* s, ElemType e)
{
	LinkStackPtr ptr = (LinkStackPtr)malloc(sizeof(StackNode));
	if (ptr == nullptr) return ERROR;
	ptr->data = e;
	ptr->next = s->top;//1.�²���Ľڵ�����ָ��ջ��ָ��ָ��Ľڵ�
	s->top = ptr;      //2.Ȼ��ջ��ָ��ָ���²���Ľڵ�
	s->count++;
	return OK;
}

Status Pop(LinkedStack* s, ElemType& e)
{
	LinkStackPtr ptr{};
	if (s == nullptr) return ERROR;
	if (s->count <= 0) return ERROR;
	e = s->top->data;   //1.����ȡ��ջ����ֵ
	ptr = s->top;       //2.����ջ��ָ��ԭ����ָ��
	s->top = s->top->next;//3.ջ��ָ��ָ����һ���ڵ�
	free(ptr);          //4.�ͷŵ�ջ��ָ��ԭ��ָ��Ľڵ�
	s->count--;
	return OK;
}

int StackOfLength(LinkedStack* s)
{
	if (s == nullptr) return 0;
	return s->count;
}

Status StackTraverse(LinkedStack* s)
{
	LinkStackPtr ptr{};
	if (s == nullptr) return ERROR;
	if (s->count <= 0) return ERROR;
	ptr = s->top;
	while (ptr) {
		Visit(ptr->data);
		ptr = ptr->next;
	}
	std::cout << "\n";
	return OK;
}

Status GetTop(LinkedStack* s, ElemType& e)
{
	if (s == nullptr) return ERROR;
	if (s->count == 0) return ERROR;
	e = s->top->data;
	return OK;
}
