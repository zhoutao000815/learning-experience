#include "Heap2.h"
//===���ڶѣ�����ѣ�������ȵ���ⲩ�ͣ�
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
		//======================���¼����������ڵ����ӿ�¼�룬¼��������Ǿֲ�����ʱ������malloc��֤�������ڡ��ǵ��ͷţ�Destory��
		php->_arr = (HPDatatype*)malloc(sizeof(HPDatatype)*n);
		memcpy(php->_arr, arr, sizeof(HPDatatype)*n);
		//======================
		//php->_arr = arr;  //������ʹ��ʱ��ȫ�ֱ���ʱ��ֱ��ָ�򼴿ɣ�Ҳ����Ҫ�ͷţ�Destory����
		php->_size = n;
		php->_capacity = n;
	}
	//������
	//�����һ��˫�׽ڵ㿪ʼ���µ�����ֱ����һ���������е�˫�׽ڵ㶼�������ˣ����Ƕ��ˡ�
	int lastparents = (n - 1 - 1) / 2;//Ϊʲô������һ��? lastchild=n-1��֮ǰ֤����child=parents*2+1�� lastparents=��lastchild-1��/2��
	int i = 0;
	for (i = lastparents; i >= 0; i--) // iҪ����0����Ϊ�����±�Ϊ0������a��0���ǵ�һ��˫�׽ڵ㣬һ��Ҫ����
	{
		ADjustDown(php->_arr, n, i);
	}
}

//β�����Ժ�Ϊ�˱�֤�ѵ�˳�򣬽���һ�����ϵ������ɡ�
void HeapPush(Heap *php, HPDatatype x)
{
	assert(php);
	if (HeapFull(php))
	{
		HPDatatype *a = (HPDatatype*)realloc(php->_arr, sizeof(HPDatatype)*php->_capacity * 2);
		if (a != NULL)
		{
			php->_arr = a;
			php->_capacity *= 2;
			php->_arr[php->_size] = x;
			php->_size++;
		}
	}
	else
	{
		php->_arr[php->_size] = x;
		php->_size++;
	}
	ADjustUp(php->_arr, php->_size, 0);
}

//ɾ���Ѷ������Ѷ�������󣬵�һ�����ݲ����㣬�����µ�����������������ɾ����
void HeapPop(Heap *php)
{
	assert(php);
	if (HeapEmpty(php))
	{
		return;
	}
	else
	{
		swap(&php->_arr[0], &php->_arr[php->_size - 1]);  //����  //Ϊʲô��һ�� ��һ�����һ��Ԫ�ص��±ꡣ
		ADjustDown(php->_arr, php->_size-1, 0);  //���µ���       //Ϊʲô��һ?  ����Ҫ�������һ���������������µ������������ٽ��е�����
		php->_size--;                          //ɾ��
	}
}
HPDatatype HeapTop(Heap *php)
{
	assert(php);
	return php->_arr[0];
}
int MyHeapSize(Heap*php)
{
	assert(php);
	printf("%d\n", php->_size);
	return php->_size;
}
int HeapEmpty(Heap* php)
{
	assert(php);
	if (php->_size==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int HeapFull(Heap* php)
{
	assert(php);
	if (php->_capacity == php->_size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void HeapDestory(Heap *php)
{
	assert(php);
	free(php->_arr);  //Ҫע�⣬_arr��malloc���������ͷţ���Ϲ�á�
	php->_capacity = 0;
	php->_size = 0;
	php = NULL;
}

// ��������ж�����
void HeapSort(HPDatatype *arr, int n)
{
	int lastparents = (n - 1 - 1) / 2;
	int i = 0;
	for (i = lastparents; i >= 0; i--)
	{
		ADjustDown(arr, n, i);
	}
	int end = n - 1;  //�������һ��Ԫ�ص��±꣬�����Ѿ�����Ԫ�ظ���-1�����֡�
	while (end > 0)
	{
		swap(&arr[end],&arr[0]);   //�����һ��Ԫ�ؽ���
		ADjustDown(arr, end, 0);   //�Ѿ������ӵ����һ��Ԫ���ˡ���Ϊ���ǵ����µ����㷨��ڶ��������ĺ����ǣ�����Ԫ�ظ�����
		end--;
	}
}

//���µ����㷨
//ʾ��Ϊ��ѣ������ΪС��ֻҪѡ��С���ӣ������׻���ȥ��
//���˵�һ�����ݣ������Ķ�����ȷ�Ķ���ʽ�����������µ����㷨�������ȷ�������Ķ�
void ADjustDown(HPDatatype*arr, int n, int root)
{
	int parents = root;
	int child = parents * 2 + 1;
	while (child < n) //һ�ν����ǲ����ģ����ܻ��ƻ�����Ķ� ������ֱ����һ�������ҵ����ʵ�λ�ò�ֹͣ��
	{
		if (arr[child] < arr[child+1] && child + 1 < n)//ѡ�����ӣ� ��ֹ+1Խ�硣
		{
			child++;
		}
		if (arr[child] > arr[parents]) //�������С�ں����򽻻���
		{
			swap(&arr[child], &arr[parents]);
			parents = child;                //��һ��ѭ�������� ������ýڵ�ĺ��ӽ��м�⣬�Ƿ��ƻ���ԭ���Ķѣ�����Ҫ�����±�
			child = parents * 2 + 1;
		}
		else
		{
			break;       //�ҵ��˺��ʵ�λ�á�
		}
	}
}

//���ϵ����㷨
//ʾ��Ϊ������ѡ������С��ֻҪ�����״��ں����򽻻���
void ADjustUp(HPDatatype*arr, int n, int root)
{
	int child = n - 1;
	int parents = (child - 1) / 2;
	while (parents > root)
	{
		if (arr[child] > arr[parents]) //�������С�ں����򽻻���
		{
			swap(&arr[child], &arr[parents]);
			child = parents;            //��һ��ѭ�������� ������ýڵ�ĺ��ӽ��м�⣬�Ƿ��ƻ���ԭ���Ķѣ����Ե����±�
			parents = (child - 1) / 2;
		}
		else
		{
			break;       //�ҵ��˺��ʵ�λ�á�
		}
	}
}
void PrintTopK(HPDatatype *arr, int n, int k)
{
	//=========���ŷ�ʽ��ע��ʹ�ó�����================
	//1��ֱ�Ӷ���������������������Ǻ��������û���ã����������ر���ʱ��Ҳ�޷��š�
	//2������һ���ѣ������ֵ�����ǵ�һ����ֵ���ݣ���K>2ʱ�������ֵ�����ԶѶ������һ�����ݽ����������µ���������ֵ�����ȥ�ˣ�����size--����k����ֵ��������K-1�Ρ�
	//3��
}
void arrprint(Heap* php)
{
	int i = 0;
	if (php->_size == 0)
	{
		printf("�նѣ�");
	}
	for (i = 0; i < php->_size; i++)
	{
		printf("%4d", php->_arr[i]);
	}
	printf("\n");
}