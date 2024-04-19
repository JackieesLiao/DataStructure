#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "Public.h"
typedef struct QNode {
	ElemType data;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkedQueue;
Status InitQueue(LinkedQueue* queue);
Status DestroyQueue(LinkedQueue* queue);
Status ClearQueue(LinkedQueue* queue);
Status QueueEmpty(LinkedQueue queue);
int QueueLength(LinkedQueue queue);
Status GetHead(LinkedQueue queue, ElemType& e);
Status EnQueue(LinkedQueue* q, ElemType e);
Status DeQueue(LinkedQueue* q, ElemType& e);
Status QueueTraverse(LinkedQueue queue);
#endif // !LINKEDQUEUE_H