#include "Heap2.h"
//===关于堆，构造堆，堆排序等的理解博客：
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
		//======================如果录入的数据是在单独接口录入，录入的数据是局部变量时，采用malloc保证生命周期。记得释放（Destory）
		php->_arr = (HPDatatype*)malloc(sizeof(HPDatatype)*n);
		memcpy(php->_arr, arr, sizeof(HPDatatype)*n);
		//======================
		//php->_arr = arr;  //数据是使用时的全局变量时。直接指向即可，也不需要释放（Destory）。
		php->_size = n;
		php->_capacity = n;
	}
	//构建堆
	//从最后一个双亲节点开始向下调整，直至第一个。当所有的双亲节点都调整好了，就是堆了。
	int lastparents = (n - 1 - 1) / 2;//为什么减两次一呢? lastchild=n-1，之前证明了child=parents*2+1； lastparents=（lastchild-1）/2；
	int i = 0;
	for (i = lastparents; i >= 0; i--) // i要等于0，因为数组下标为0，而且a【0】是第一个双亲节点，一定要调整
	{
		ADjustDown(php->_arr, n, i);
	}
}

//尾插入以后，为了保证堆的顺序，进行一次向上调整即可。
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

//删除堆顶：将堆顶换到最后，第一个数据不满足，再向下调整。调整结束后再删除。
void HeapPop(Heap *php)
{
	assert(php);
	if (HeapEmpty(php))
	{
		return;
	}
	else
	{
		swap(&php->_arr[0], &php->_arr[php->_size - 1]);  //交换  //为什么减一？ 减一是最后一个元素的下标。
		ADjustDown(php->_arr, php->_size-1, 0);  //向下调整       //为什么减一?  我们要无视最后一个，令他满足向下调整的条件，再进行调整。
		php->_size--;                          //删除
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
	free(php->_arr);  //要注意，_arr是malloc出来的再释放，别瞎用。
	php->_capacity = 0;
	php->_size = 0;
	php = NULL;
}

// 对数组进行堆排序
void HeapSort(HPDatatype *arr, int n)
{
	int lastparents = (n - 1 - 1) / 2;
	int i = 0;
	for (i = lastparents; i >= 0; i--)
	{
		ADjustDown(arr, n, i);
	}
	int end = n - 1;  //既是最后一个元素的下标，又是已经数组元素个数-1的数字。
	while (end > 0)
	{
		swap(&arr[end],&arr[0]);   //和最后一个元素交换
		ADjustDown(arr, end, 0);   //已经是无视掉最后一个元素了。因为我们的向下调整算法里，第二个参数的含义是：数组元素个数，
		end--;
	}
}

//向下调整算法
//示例为大堆，（想变为小堆只要选出小孩子，将大父亲换下去）
//除了第一个数据，其他的都是正确的堆形式，可以用向下调整算法。变成正确的完整的堆
void ADjustDown(HPDatatype*arr, int n, int root)
{
	int parents = root;
	int child = parents * 2 + 1;
	while (child < n) //一次交换是不够的，可能会破坏下面的堆 。所以直到第一个数据找到合适的位置才停止。
	{
		if (arr[child] < arr[child+1] && child + 1 < n)//选出大孩子， 防止+1越界。
		{
			child++;
		}
		if (arr[child] > arr[parents]) //如果父亲小于孩子则交换，
		{
			swap(&arr[child], &arr[parents]);
			parents = child;                //下一次循环进来， 继续向该节点的孩子进行检测，是否破坏了原本的堆，所以要调整下标
			child = parents * 2 + 1;
		}
		else
		{
			break;       //找到了合适的位置。
		}
	}
}

//向上调整算法
//示例为建立大堆。（变成小堆只要当父亲大于孩子则交换）
void ADjustUp(HPDatatype*arr, int n, int root)
{
	int child = n - 1;
	int parents = (child - 1) / 2;
	while (parents > root)
	{
		if (arr[child] > arr[parents]) //如果父亲小于孩子则交换，
		{
			swap(&arr[child], &arr[parents]);
			child = parents;            //下一次循环进来， 继续向该节点的孩子进行检测，是否破坏了原本的堆，所以调整下标
			parents = (child - 1) / 2;
		}
		else
		{
			break;       //找到了合适的位置。
		}
	}
}
void PrintTopK(HPDatatype *arr, int n, int k)
{
	//=========三张方式，注意使用场景。================
	//1、直接堆排序，求出所有排名，但是后面的排名没有用，当数据量特别大的时候，也无法排。
	//2、建立一个堆，求出最值，这是第一个最值数据，当K>2时，求次最值，可以堆顶和最后一个数据交换，再向下调整，次最值到最后去了，无视size--，求k个最值，交换并K-1次。
	//3、
}
void arrprint(Heap* php)
{
	int i = 0;
	if (php->_size == 0)
	{
		printf("空堆！");
	}
	for (i = 0; i < php->_size; i++)
	{
		printf("%4d", php->_arr[i]);
	}
	printf("\n");
}