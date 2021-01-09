#include "Heap.h"
void Heaptest()
{
//==================¶Ñ²âÊÔ´úÂë=====================
	HPDatatype arr[] = { 23, 65, 45, 31, 29, 66, 99, 66, 815, 1, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Heap php;
	MyHeapCreate(&php, arr, n);
	arrprint(&php);


}
int main()
{
	//Heaptest();

	//=====¶ÑÅÅĞò²âÊÔ´úÂë
	HPDatatype arr[] = { 23, 65, 45, 31, 29, 66, 99, 66, 815, 1, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, n);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%4d",arr[i]);
	}
	printf("\n");

	system("pause");
}