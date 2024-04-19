#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "Public.h"
typedef struct DoubleNode
{
	struct DoubleNode* prior;
	ElemType data;
	struct DoubleNode* next;
}DoubleNode,*DoubleLinkedList;

DoubleLinkedList InitList();
ElemType ListLength(DoubleLinkedList L);
Status GetItem(DoubleLinkedList L, ElemType e);
ElemType GetElemByIndex(DoubleLinkedList L, int index,ElemType&e);
Status ListInsert(DoubleLinkedList L,int index,ElemType e);
Status ListDelete(DoubleLinkedList L, int index);
Status ListClear(DoubleLinkedList& L);
void Print(DoubleLinkedList L);
#endif // !DOUBLELINKEDLIST_H