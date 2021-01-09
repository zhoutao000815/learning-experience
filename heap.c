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
		//======================���¼����������ڵ����ӿ�¼�룬¼��������Ǿֲ�����ʱ������malloc��֤�������ڡ�
		//php->_arr = (HPDatatype*)malloc(sizeof(HPDatatype)*n);
		//memcpy(php->_arr, arr, sizeof(HPDatatype)*n);
		//======================
		php->_arr = arr;  //������ʹ��ʱ��ȫ�ֱ���ʱ��
		php->_size = n;
		php->_capacity = n;
	}
	//������
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

// ��������ж�����
void HeapSort(HPDatatype *arr, int n)
{
	Heap php;
	MyHeapCreate(&php, arr, n);
	Heap*p = &php;
	int end = n - 1;
	while (end > 0)
	{
		swap(&p->_arr[end], &p->_arr[0]);
		//end--;   Ϊʲô�����Ȱѽ���������ݻ����أ�
		ADjustDown(arr, end, 0);
		end--;
	}
}

//���µ����㷨
//ʾ��ΪС�ѣ������Ϊ���ֻҪѡ�����ӣ���С���׻���ȥ��
//���˵�һ�����ݣ������Ķ�����ȷ�Ķ���ʽ�����������µ����㷨�������ȷ�������Ķ�
void ADjustDown(HPDatatype*arr, int n, int root)
{
	int parents = root;
	int child = parents * 2 + 1;
	while (child < n) //һ�ν����ǲ����ģ����ܻ��ƻ�����Ķ� ������ֱ����һ�������ҵ����ʵ�λ�ò�ֹͣ��
	{
		if (arr[child] > arr[child+1] && child + 1 < n)//ѡ��С���ӣ� ��ֹ+1Խ�硣
		{
			child++;
		}
		if (arr[child] < arr[parents]) //������״��ں����򽻻���
		{
			swap(&arr[child], &arr[parents]);
			parents = child;                //��һ��ѭ�������� ������ýڵ�ĺ��ӽ��м�⣬�Ƿ��ƻ���ԭ���Ķ�
			child = parents * 2 + 1;
		}
		else
		{
			break;       //�ҵ��˺��ʵ�λ�á�
		}
	}
}

//���ϵ����㷨
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