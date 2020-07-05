#pragma once
#ifndef __LISTNODE_H_
#define __LISTNODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#endif //__LISTNODE_H_

typedef struct ListNode
{
	int date;
	struct ListNode *next;
	struct ListNode *prev;
}ListNode;

typedef struct List
{
	ListNode *head;
}List;

void ListInit(List* plist);
void ListDestory(List* plist);

ListNode* BuyListNode(int x);

void ListPushFront(List* plist, int x);
void ListPopFront(List* plist);
void ListPushBack(List* plist, int x);
void ListPopBack(List* plist);

ListNode *ListFind(List* plist, int x);

void ListInsert(ListNode* pos, int x);
void ListErase(List*plist, ListNode* pos);
void ListRemove(List* plist);
void ListPrint(List* plist);