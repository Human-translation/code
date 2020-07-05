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

void QueueInit(Queue* pq);//��ʼ��

void QueueDsetory(Queue* pq);//����

QueueNode* BuyQueueNode(QUDataType x);//�����µĽ��

void QueuePush(Queue* pq, QUDataType x);//���

void QueuePop(Queue* pq);//����

QUDataType QueueFront(Queue* pq);//���ض���

QUDataType QueueBack(Queue* pq);//���ض�β

int QueueEmpty(Queue* pq);//�ж��Ƿ�Ϊ��

int QueueSize(Queue* pq);//���ض�Ԫ�ظ���

void QueueDisplay(Queue* pq);//��ӡ

void TestQueue();