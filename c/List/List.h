#pragma once
#ifndef __LIANBIAO_H_
#define __LIANBIAO_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#endif //__LIANBAIO_H_

typedef struct SListNode
{
	int date;
	struct SListNode *next;
}SListNode;

typedef struct SList
{
	SListNode *head;
}SList;

void SListInit(SList* plist);//��ʼ��
void SListDestory(SList* plist);//����
SListNode* BuySListNode(int x);//��ӽ��
void SListPushFront(SList* plist, int x);//ͷ��
void SListPopFront(SList* plist);//ͷɾ
void SListPushBack(SList* plist, int x);//β��
void SListPopBack(SList* plist);//βɾ
SListNode* SListFind(SList* plist, int x);//����
void SListInsertAfter(SListNode* pos, int x);//�����
void SListEraseAfter(SListNode* pos);//����ɾ
void SListRemove(SList* plist, int x);//ɾ������ֵΪx�Ľ��
void SListPrint(SList* plist);//��ӡ