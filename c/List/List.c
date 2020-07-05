#define _CRT_SECURE_NO_WARNINGS

#include "lianbiao.h"

void SListInit(SList* plist)//��ʼ��
{
	assert(plist);
	plist->head = NULL;
}

void SListDestory(SList* plist)//����
{
	assert(plist);
	SListNode *p = plist->head;
	SListNode *q = plist->head;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	plist->head = NULL;
}

SListNode* BuySListNode(int x)//��ӽ��
{
	SListNode *plist = (SListNode *)malloc(sizeof(SListNode));
	plist->date = x;
	plist->next = NULL;
	return plist;
}

void SListPushFront(SList* plist, int x)//ͷ��
{
	SListNode *newplist = BuySListNode(x);
	assert(newplist);
	newplist->next = plist->head;
	plist->head = newplist;
}

void SListPopFront(SList* plist)//ͷɾ
{
	assert(plist);
	assert(plist->head != NULL);
	SListNode *p = plist->head;
	plist->head = p->next;
	free(p);
}

void SListPushBack(SList* plist, int x)
{
	if (plist->head == NULL)
	{
		SListPushFront(plist, x);
		return;
	}
	SListNode *newplist = BuySListNode(x);
	SListNode *p = plist->head;
	assert(newplist);
	while (p->next)
	{
		p = p->next;
	}
	p->next = newplist;
}

void SListPopBack(SList* plist)
{
	assert(plist);
	assert(plist->head != NULL);
	SListNode *p = plist->head;
	if (p->next == NULL)
	{
		SListPopFront(plist);
		return;
	}
	SListNode *q = plist->head;
	while (q->next)
	{
		p = q;
		q = q->next;
	}
	free(q);
	p->next = NULL;
}

SListNode* SListFind(SList* plist, int x)//����
{
	assert(plist);
	assert(plist->head);
	SListNode *p = plist->head;
	while (p)
	{
		if (p->date == x)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, int x)//�����
{
	assert(pos);
	SListNode *p = BuySListNode(x);
	p->next = pos->next;
	pos->next = p;
}

void SListEraseAfter(SListNode* pos)//����ɾ
{
	assert(pos);
	pos->next = pos->next->next;
}

void SListRemove(SList* plist, int x)//ɾ������ֵΪx�Ľ��
{
	assert(plist);
	while (plist->head != NULL && plist->head->date == x)
	{
		SListPopFront(plist);
	}
	SListNode* prev = plist->head;
	SListNode* cur = plist->head->next;
	for (; cur != NULL; cur = prev->next)
	{
		if (cur->date == x)
		{
			prev->next = cur->next;
			free(cur);
		}
		else
		{
			prev = cur;
		}
	}
}

void SListPrint(SList* plist)//��ӡ
{
	assert(plist);
	SListNode *p = plist->head;
	while (p)
	{
		printf("%d ", p->date);
		p = p->next;
	}
}