#include "LinkedQueue.h"

Status InitQueue(LinkedQueue* queue)
{
	queue->front = (QueuePtr)malloc(sizeof(QNode));
	queue->rear = queue->front;
	if (queue->front == nullptr) {
		exit(OVERFLOW);
	}
	queue->front->next = nullptr;
	return OK;
}

Status DestroyQueue(LinkedQueue* queue)
{
	while (queue->front) {
		queue->rear = queue->front->next;
		free(queue->front);
		queue->front = queue->rear;
	}
	return OK;
}

Status ClearQueue(LinkedQueue* queue)
{
	QueuePtr p{}, q{};
	queue->rear = queue->front;
	p = queue->front->next;
	queue->front->next = nullptr;
	while (p) {
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}

Status QueueEmpty(LinkedQueue queue)
{
	if (queue.front == queue.rear) return TRUE;
	return FALSE;
}

int QueueLength(LinkedQueue queue)
{
	auto count{ 0 };
	QueuePtr p = queue.front;
	while (p != queue.rear && (p != nullptr)) {
		p = p->next;
		count++;
	}
	return count;
}

Status GetHead(LinkedQueue queue, ElemType& e)
{
	QueuePtr p{};
	if (queue.front == queue.rear) return ERROR;
	p = queue.front->next;
	e = p->data;
	return OK;
}
/// <summary>
/// ���
/// </summary>
/// <param name="q"></param>
/// <param name="e"></param>
/// <returns></returns>
Status EnQueue(LinkedQueue* q, ElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (s == nullptr) exit(OVERFLOW);
	s->data = e;      //1.�洢�½ڵ��ֵ
	s->next = nullptr;
	q->rear->next = s;//2.���½ڵ�s���뵽����β��
	q->rear = s;      //3.���¶�βָ��Ϊs
	return OK;
}
/// <summary>
/// ����
/// </summary>
/// <param name="q"></param>
/// <param name="e"></param>
/// <returns></returns>
Status DeQueue(LinkedQueue* q, ElemType& e)
{
	QueuePtr p{};
	if (q->front == q->rear) return ERROR;
	p = q->front->next; //1.ָ����Ҫ���ӵĽڵ�
	e = p->data;        //2.�洢���ӽڵ��ֵ�����ӡ
	q->front->next = p->next;//3.ͷ�ڵ�ָ����ӽڵ����һ���ڵ�
	if (q->rear == p) {
		q->rear = q->front;
	}
	free(p);
	return OK;
}

Status QueueTraverse(LinkedQueue queue)
{
	QueuePtr p = queue.front->next;
	while (p) {
		Visit(p->data);
		p = p->next;
	}
	std::cout << "\n";
	return OK;
}
