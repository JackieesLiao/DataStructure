#ifndef SQQUEUE_H
#define SQQUEUE_H
#include "Public.h"
typedef struct {
	ElemType data[kMaxSize];
	int front;//ͷ�ڵ�ָ��
	int rear; //β�ڵ�ָ��
}SqQueue;
Status InitQueue(SqQueue* queue);
Status ClearQueue(SqQueue* queue);
Status QueueEmpty(SqQueue queue);
int QueueLength(SqQueue queue);
Status GetHead(SqQueue queue, ElemType& e);
Status EnQueue(SqQueue* q, ElemType e);
Status DeQueue(SqQueue* q, ElemType&e);
Status QueueTraverse(SqQueue queue);
#endif // !SQQUEUE_H