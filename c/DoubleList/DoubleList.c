#define _CRT_SECURE_NO_WARNINGS

#include "DoubleList.h"

void ListInit(List* plist)
{
	assert(plist);
	plist->head = BuyListNode(-1);
	plist->head->next = plist->head;
	plist->head->prev = plist->head;
}

ListNode* BuyListNode(int x)
{
	ListNode *plist = (ListNode*)malloc(sizeof(ListNode));
	plist->date = x;
	plist->next = NULL;
	plist->prev = NULL;
	return plist;
}

void ListDestory(List* plist)
{
	ListNode *p = plist->head->next;
	ListNode *q;
	while (p != plist->head)
	{
		q = p->next;
		p = q;
	}
	free(plist->head);
	plist->head = NULL;
}

void ListPushFront(List* plist, int x)
{
	ListInsert(plist->head->next, x);

	//ListNode *p = plist->head;
	//ListNode *newplist = BuyListNode(x);
	//newplist->next = p->next;
	//p->next->prev = newplist;
	//p->next = newplist;
	//newplist->prev = p;
}

void ListPopFront(List* plist)
{
	ListErase(plist, plist->head->next);

	//assert(plist);
	//ListNode *p = plist->head->next;
	//plist->head->next = p->next;
	//p->next->prev = plist->head;
	//free(p);
}

void ListPushBack(List* plist, int x)
{

	ListInsert(plist->head, x);

	//ListNode *p = plist->head;
	//ListNode *newplist = BuyListNode(x);
	//while (p->next != plist->head)
	//{
	//	p = p->next;
	//}
	//p->next = newplist;
	//newplist->prev = p;
	//plist->head->prev = newplist;
	//newplist->next = plist->head;

}

void ListPopBack(List* plist)
{
	ListErase(plist, plist->head->prev);

	//ListNode *p = plist->head;
	//while (p->next != plist->head)
	//{
	//	p = p->next;
	//}
	//plist->head->prev = p->prev;
	//p->prev->next = plist->head;
	//free(p);
}


ListNode *ListFind(List* plist, int x)
{
	ListNode *p = plist->head;
	while (p->next != plist->head)
	{
		if (p->date == x)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, int x)
{
	ListNode *newplist = BuyListNode(x);
	ListNode *p = pos->prev;
	p->next = newplist;
	newplist->prev = p;
	pos->prev = newplist;
	newplist->next = pos;
}

void ListErase(List*plist, ListNode* pos)
{
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
}

void ListPrint(List* plist)
{
	assert(plist);
	ListNode* ret = plist->head->next;
	while (ret != plist->head)
	{
		printf("%d  ", ret->date);
		ret = ret->next;
	}
	printf("\n");
}