#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->a == NULL)
	{
		return;
	}
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		size_t newC = (ps->capacity == 0 ? 3 : 2 * ps->capacity);
		ps->a = (Stack*)realloc(ps->a, sizeof(int)* newC);
		ps->capacity = newC;
	}
	ps->a[ps->top++] = x;
}

void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->top > 0)
		--ps->top;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->a[ps->top - 1];
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return (ps->top == 0 ? 1 : 0);
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

void StackPrint(Stack* ps)
{
	assert(ps);
	while (StackEmpty(ps) != 1)
	{
		printf("%d ", StackTop(ps));
		StackPop(ps);
	}
}

void TestStack()
{
	Stack head;
	StackInit(&head);
	StackPush(&head, 1);
	StackPush(&head, 2);
	StackPush(&head, 3);
	StackPush(&head, 4);
	StackPrint(&head);
	StackDestory(&head);
}