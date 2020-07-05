#pragma once
#ifndef __QUEUE_H_
#define __QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#endif //__QUEUE_H_

typedef int QUDataType;
typedef struct QueueNode
{
	QUDataType data;
	struct QueueNode* nest;
}QueueNode;

typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue;

void QueueInit(Queue* pq);//初始化

void QueueDsetory(Queue* pq);//销毁

QueueNode* BuyQueueNode(QUDataType x);//创建新的结点

void QueuePush(Queue* pq, QUDataType x);//入队

void QueuePop(Queue* pq);//出队

QUDataType QueueFront(Queue* pq);//返回队首

QUDataType QueueBack(Queue* pq);//返回队尾

int QueueEmpty(Queue* pq);//判断是否为空

int QueueSize(Queue* pq);//返回队元素个数

void QueueDisplay(Queue* pq);//打印

void TestQueue();