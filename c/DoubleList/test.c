#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "listnode.h"

void test()
{
	List phead;
	ListNode* ret;
	ListInit(&phead);

	ListPushBack(&phead, 5);
	ListPushBack(&phead, 4);
	ListPushBack(&phead, 2);
	ListPushBack(&phead, 3);
	ListPushBack(&phead, 1);
	//ret = ListFind(&phead, 3);
	//printf("%d\n", ret->date);
	ListPopFront(&phead);
	ListPopFront(&phead);
	ListPopFront(&phead);
	ListPopFront(&phead);
	ListPrint(&phead);
	ListDestory(&phead);
}

int main()
{
	test();
	system("pause");
	return 0;
}