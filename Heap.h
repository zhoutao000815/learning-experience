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

// ��������ж�����
void HeapSort(HPDatatype *arr, int n);

//���µ����㷨
void ADjustDown(HPDatatype*arr, int n, int root);

//���ϵ����㷨
void ADjustUp(HPDatatype*arr, int n, int root);
void PrintTopK(HPDatatype *arr, int n, int k);
void arrprint(Heap* php);