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
	//tail尾指针是不能指向有元素的值位置的 
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
/// 入队
/// </summary>
/// <param name="q"></param>
/// <param name="e"></param>
/// <returns></returns>
Status EnQueue(SqQueue* q, ElemType e)
{
	//如果已经满
	if ((q->rear + 1) % kMaxSize == q->front) return ERROR;
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % kMaxSize;  //确保尾指针在0~kMaxSize区间内递增
	return OK;
}
/// <summary>
/// 出队
/// </summary>
/// <param name="q"></param>
/// <param name="e"></param>
/// <returns></returns>
Status DeQueue(SqQueue* q, ElemType&e)
{
	if (q->front == q->rear) return ERROR;//队列空无需删除
	e = q->data[q->front];
	q->front = (q->front + 1) % kMaxSize; //确保front指针在0~kMaxSize区间内递增
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
