#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"

void HeapInit(Heap* hp, HPDataType* arr, int n)
{
	hp->a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	int i;
	for (i = 0; i < n; i++)
	{
		hp->a[i] = arr[i];
	}
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		ShiftDown(hp->a, n, i);
	}
	hp->size = hp->capacity = n;
}


void Swap(HPDataType* pa, HPDataType* pb)
{
	HPDataType pc = *pa;
	*pa = *pb;
	*pb = pc;
}

void XiaoDui(HPDataType* arr, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] < arr[child])
			child++;
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void ShiftDown(HPDataType* arr, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
			++child;
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapDestory(Heap* hp)
{
	if (hp->a)
	{
		free(hp->a);
		hp->a = NULL;
		hp->capacity = hp->size = 0;
	}
}

void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->size == hp->capacity)
	{
		hp->capacity = hp->capacity * 2;
		hp->a = (int*)realloc(hp->a, sizeof(int)* hp->capacity);
	}
	hp->a[hp->size] = x;
	hp->size++;
	for (int i = hp->size / 2; i >= 0; i--)
	{
		ShiftDown(hp->a, hp->size, i);
	}
}

void HeapPop(Heap* hp)
{
	int x = hp->a[0];
	hp->a[0] = hp->a[hp->size - 1];
	hp->a[hp->size - 1] = x;
	hp->size--;
	ShiftDown(hp->a, hp->size, 0);
}

HPDataType HeapTop(Heap* hp)
{
	if (hp->size > 0)
	{
		return hp->a[0];
	}
	return 0;
}

int HeapSize(Heap* hp)
{
	return hp->size;
}

int HeapEmpty(Heap* hp)
{
	if (hp->size == 0)
		return 1;
	return 0;
}

void HeapSort(Heap *hp)
{
	int len = hp->size;
	while (hp->size != 0)
	{
		HeapPop(hp);
	}
	hp->size = len;
}

void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}

void TestHeap()
{
	int a[] = { 1, 5, 3, 8, 7, 6 };//876513
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	HeapPush(&hp, 9);
	HeapPrint(&hp);
}