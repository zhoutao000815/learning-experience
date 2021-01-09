#include "Heap.h"
void swap(HPDatatype *a1, HPDatatype *a2)
{
	HPDatatype temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}
void MyHeapCreate(Heap *php, HPDatatype *arr, int n)
{
	assert(php);
	if (php != NULL)
	{
		//======================如果录入的数据是在单独接口录入，录入的数据是局部变量时，采用malloc保证生命周期。
		//php->_arr = (HPDatatype*)malloc(sizeof(HPDatatype)*n);
		//memcpy(php->_arr, arr, sizeof(HPDatatype)*n);
		//======================
		php->_arr = arr;  //数据是使用时的全局变量时。
		php->_size = n;
		php->_capacity = n;
	}
	//构建堆
	int lastparents = (n - 1) / 2;
	int i = 0;
	for (i = lastparents; i >= 0; i--)
	{
		ADjustDown(php->_arr, n, i);
	}
}
void HeapPush(Heap *php, HPDatatype x);
void HeapPop(Heap *php);
HPDatatype HeapTop(Heap *php);
int MyHeapSize(Heap*php);
int HeapEmpty(Heap* php);
void HeapDestory(Heap *php);

// 对数组进行堆排序
void HeapSort(HPDatatype *arr, int n)
{
	Heap php;
	MyHeapCreate(&php, arr, n);
	Heap*p = &php;
	int end = n - 1;
	while (end > 0)
	{
		swap(&p->_arr[end], &p->_arr[0]);
		//end--;   为什么不能先把交换后的数据划掉呢？
		ADjustDown(arr, end, 0);
		end--;
	}
}

//向下调整算法
//示例为小堆，（想变为大堆只要选出大孩子，将小父亲换下去）
//除了第一个数据，其他的都是正确的堆形式，可以用向下调整算法。变成正确的完整的堆
void ADjustDown(HPDatatype*arr, int n, int root)
{
	int parents = root;
	int child = parents * 2 + 1;
	while (child < n) //一次交换是不够的，可能会破坏下面的堆 。所以直到第一个数据找到合适的位置才停止。
	{
		if (arr[child] > arr[child+1] && child + 1 < n)//选出小孩子， 防止+1越界。
		{
			child++;
		}
		if (arr[child] < arr[parents]) //如果父亲大于孩子则交换，
		{
			swap(&arr[child], &arr[parents]);
			parents = child;                //下一次循环进来， 继续向该节点的孩子进行检测，是否破坏了原本的堆
			child = parents * 2 + 1;
		}
		else
		{
			break;       //找到了合适的位置。
		}
	}
}

//向上调整算法
void ADjustUp(HPDatatype*arr, int n, int root);
void PrintTopK(HPDatatype *arr, int n, int k);
void arrprint(Heap* php)
{
	int i = 0;
	for (i = 0; i < php->_size; i++)
	{
		printf("%4d", php->_arr[i]);
	}
	printf("\n");
}