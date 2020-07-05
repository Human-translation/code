#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->front = NULL;
	pq->rear = NULL;
}

void QueueDsetory(Queue* pq)
{
	assert(pq);
	if (!QueueEmpty(pq))
	{
		return;
	}
	QueueNode* p = pq->front;
	while (pq->front)
	{
		p = pq->front;
		pq->front = pq->front->nest;
		free(p);

	}
	pq->front = NULL;
	pq->rear = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode *p = (QueueNode*)malloc(sizeof(QueueNode));
	p->data = x;
	p->nest = NULL;
	return p;
}

void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	QueueNode* p = BuyQueueNode(x);
	if (!QueueEmpty(pq))
	{
		pq->front = p;
		pq->rear = p;
	}
	else
	{
		pq->rear->nest = p;
		pq->rear = p;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* p = pq->front;
	if (p == NULL)
	{
		return;
	}
	if (pq->front == pq->rear)
	{
		pq->front = NULL;
		pq->rear = NULL;
	}
	else
	{
		pq->front = pq->front->nest;
		free(p);
	}
}

QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->front->data;
}

QUDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->rear->data;
}

int QueueEmpty(Queue* pq)
{
	return pq->front != NULL;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int count = 0;
	QueueNode *p = pq->front;
	while (p)
	{
		p = p->nest;
		count++;
	}
	return count;
}

void QueueDisplay(Queue* pq)
{
	assert(pq);
	QueueNode *p = pq->front;
	while (p)
	{
		printf("%d ", p->data);
		p = p->nest;
	}
}

void TestQueue()
{
	Queue head;
	int count, front, back;
	QueueInit(&head);
	QueuePush(&head, 1);
	QueuePush(&head, 2);
	QueuePush(&head, 3);
	QueuePop(&head);
	QueuePop(&head);
	front = QueueFront(&head);
	back = QueueBack(&head);
	count = QueueSize(&head);
	QueueDisplay(&head);
	QueueDsetory(&head);
}