#pragma once
#ifndef __STACK_H_
#define __STACK_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#endif //__STACK_H_

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps);//初始化

void StackDestory(Stack* ps);//销毁

void StackPush(Stack* ps, STDataType x);//插入

void StackPop(Stack* ps);//删除

STDataType StackTop(Stack* ps);//返回栈顶元素

int StackEmpty(Stack* ps);//判断栈是否为空

int StackSize(Stack* ps);//返回栈元素个数

void StackPrint(Stack* ps);//打印

void TestStack();//调用