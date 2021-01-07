#pragma once
#include <stdio.h>
#include<Windows.h>
#include <assert.h>
typedef int HPDatatype;
typedef struct Heap
{
	HPDatatype *_arr;
	int _size;
	int _capacity;
}Heap;
void swap(HPDatatype *a1, HPDatatype *a2);
void MyHeapCreate(Heap *php, HPDatatype *arr, int n);
void HeapPush(Heap *php, HPDatatype x);
void HeapPop(Heap *php);
HPDatatype HeapTop(Heap *php);
int MyHeapSize(Heap*php);
int HeapEmpty(Heap* php);
void HeapDestory(Heap *php);

// 对数组进行堆排序
void HeapSort(HPDatatype *arr, int n);

//向下调整算法
void ADjustDown(HPDatatype*arr, int n, int root);

//向上调整算法
void ADjustUp(HPDatatype*arr, int n, int root);
void PrintTopK(HPDatatype *arr, int n, int k);
void arrprint(Heap* php);