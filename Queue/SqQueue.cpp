#include "SqQueue.h"

Status InitQueue(SqQueue* queue)
{
	queue->front = 0;
	queue->rear = 0;
	return OK;
}

Status ClearQueue(SqQueue* queue)
{
	queue->front = 0;
	queue->rear = 0;
	return OK;
}

Status QueueEmpty(SqQueue queue)
{
	if (queue.front == queue.rear) return TRUE;
	return FALSE;
}

int QueueLength(SqQueue queue)
{
	//tailβָ���ǲ���ָ����Ԫ�ص�ֵλ�õ� 
	return (queue.rear - queue.front + kMaxSize) % kMaxSize;
}

Status GetHead(SqQueue queue, ElemType& e)
{
	if (queue.front == queue.rear) {
		return ERROR;
	}
	e = queue.data[queue.front];
	return OK;
}
/// <summary>
/// ���
/// </summary>
/// <param name="q"></param>
/// <param name="e"></param>
/// <returns></returns>
Status EnQueue(SqQueue* q, ElemType e)
{
	//����Ѿ���
	if ((q->rear + 1) % kMaxSize == q->front) return ERROR;
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % kMaxSize;  //ȷ��βָ����0~kMaxSize�����ڵ���
	return OK;
}
/// <summary>
/// ����
/// </summary>
/// <param name="q"></param>
/// <param name="e"></param>
/// <returns></returns>
Status DeQueue(SqQueue* q, ElemType&e)
{
	if (q->front == q->rear) return ERROR;//���п�����ɾ��
	e = q->data[q->front];
	q->front = (q->front + 1) % kMaxSize; //ȷ��frontָ����0~kMaxSize�����ڵ���
	return OK;
}

Status QueueTraverse(SqQueue queue)
{
	auto i = queue.front;
	while (i != queue.rear) {
		Visit(queue.data[i]);
		i = (i + 1) % kMaxSize;
	}
	std::cout << "\n";
	return OK;
}
