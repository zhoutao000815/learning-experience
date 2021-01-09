#include "Heap2.h"
void Heaptest()
{
//==================∂—≤‚ ‘¥˙¬Î=====================
	HPDatatype arr[] = { 23, 65, 45, 31, 29, 66, 99, 66, 815, 1, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Heap php;
	MyHeapCreate(&php, arr, n);
	arrprint(&php);
	MyHeapSize(&php);
	HeapPush(&php, 2);
	HeapPush(&php, 3);
	HeapPush(&php, -1);
	arrprint(&php);
	MyHeapSize(&php);
	HeapPop(&php);
	HeapTop(&php);
	arrprint(&php);
	MyHeapSize(&php);
	Heap* p = &php;
	HeapSort(p->_arr,p->_size);
	arrprint(&php);
	MyHeapSize(&php);
	HeapDestory(p);
}
int main()
{
	Heaptest();

	//=====∂—≈≈–Ú≤‚ ‘¥˙¬Î
	//HPDatatype arr[] = { 23, 65, 45, 31, 29, 66, 99, 66, 815, 1, 0 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	/*HeapSort(arr, n);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%4d",arr[i]);
	}
	printf("\n");*/

	system("pause");
}