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

void SListInit(SList* plist);//初始化
void SListDestory(SList* plist);//销毁
SListNode* BuySListNode(int x);//添加结点
void SListPushFront(SList* plist, int x);//头插
void SListPopFront(SList* plist);//头删
void SListPushBack(SList* plist, int x);//尾插
void SListPopBack(SList* plist);//尾删
SListNode* SListFind(SList* plist, int x);//查找
void SListInsertAfter(SListNode* pos, int x);//任意插
void SListEraseAfter(SListNode* pos);//任意删
void SListRemove(SList* plist, int x);//删除所有值为x的结点
void SListPrint(SList* plist);//打印