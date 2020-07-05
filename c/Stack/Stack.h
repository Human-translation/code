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

void StackInit(Stack* ps);//��ʼ��

void StackDestory(Stack* ps);//����

void StackPush(Stack* ps, STDataType x);//����

void StackPop(Stack* ps);//ɾ��

STDataType StackTop(Stack* ps);//����ջ��Ԫ��

int StackEmpty(Stack* ps);//�ж�ջ�Ƿ�Ϊ��

int StackSize(Stack* ps);//����ջԪ�ظ���

void StackPrint(Stack* ps);//��ӡ

void TestStack();//����