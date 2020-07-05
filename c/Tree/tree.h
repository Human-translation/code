#pragma once
#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>

#endif //__TREE_H__

typedef int HPDataType;
typedef struct headp
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* arr, int n);

void XiaoDui(HPDataType* arr, int n, int root);

void ShiftDown(HPDataType* a, int n, int root);

void HeapDestory(Heap* hp);

void HeapPush(Heap* hp, HPDataType x);

void HeapPop(Heap* hp);

HPDataType HeapTop(Heap* hp);

int HeapSize(Heap* hp);

int HeapEmpty(Heap* hp);

void HeapSort(int* a, int n);

void HeapPrint(Heap* hp);

void TestHeap();