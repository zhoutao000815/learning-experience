#include"sort.h"
//交换函数
void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
//将最后一个数据，插入到之前的有序数组中。
void ForInsert(int *a, int n)//  n代表元素个数
{
//==============从后向前比较===============
	int end = n - 2;
	int temp = a[end+1];
	while (end >= 0)
	{
		if (a[end] > temp)
		{
			a[end + 1] = a[end];
			end--;
		}
		else
		{
			break;
		}
	}
	a[end + 1] = temp;

}
// 插入排序算法
void InsertSort(int* a, int n)
{
//方法一：
	//  i代表元素个数
	for (int i = 1; i <= n; ++i)
	{
		ForInsert(a, i);
	}
//方法二：
	//   i代表数组下标
	//for (int i = 0; i < n-1; ++i)
	//{
	//	int end = i;
	//	int temp = a[end + 1];
	//	while (end >= 0)
	//	{
	//		if (a[end] > temp)
	//		{
	//			a[end + 1] = a[end];
	//			end--;
	//		}
	//		else
	//		{
	//			break;
	//		}
	//	}
	//	a[end + 1] = temp;
	//}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	// 1.gap>1相当于预排序，让数组接近有序
	// 2.gap==1就相当于直接插入排序，保证有序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

// 选择排序
void SelectSort1(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		for (int i = begin+1; i <= end; i++)
		{
			if (a[begin] > a[i])
			{
				Swap(&a[begin], &a[i]);
			}
		}
		begin++;
	}
}
void SelectSort2(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int Max = begin;
		int Min = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[Min] > a[i])
			{
				Min = i;
			}
			if (a[Max] < a[i])
			{
				Max = i;
			}
		}
		Swap(&a[begin], &a[Min]);
		if (begin == Max)
		{
			Max = Min;
		}
		Swap(&a[end], &a[Max]);
		begin++;
		end--;
	}
}
// 堆排序
void AdjustDwon(int* a, int n, int root)
{
	int parents = root;
	int child = parents * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[parents] < a[child])
		{
			Swap(&a[parents], &a[child]);
			parents = child;
			child = parents * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
//===建堆===
	int lastchild = n - 1;
	int lastparents = (lastchild - 1) / 2;
	for (int i = lastparents; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
//===堆排序===
	int end = n - 1;
	while (end >= 1)
	{
		Swap(&a[0], &a[end]);  //end代表数组中最后一个元素的下标
		AdjustDwon(a, end, 0);  //end代表数组中剩下的有效数据个数
		end--;
	}
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int change = 0;//默认没有改变
	while (begin < end)
	{
		for (int i = 0; i < end; i++)
		{
			if (a[i+1] < a[i])
			{
				Swap(&a[i+1], &a[i]);
				change = 1; //进入判定交换后，则改变。
			}
		}
		if (!change)
		{
			break;
		}
		end--;
	}
}

//// 快速排序递归实现
//// 1、快速排序hoare版本
//int PartSort1(int* a, int left, int right)
//{
//
//}
////2、 快速排序挖坑法
//int PartSort2(int* a, int left, int right);

//3、快速排序前后指针法
//假设左边是尾巴，右边是头。                        
//prev是小火车的头，cur是大火车的头，大火车先走，大火车遇到属于小火车的车厢了，让这个车厢去当小火车的头，遇到大火车的车厢，让这个车厢当大火车的头。
int PartSort3(int* a, int begin, int end)
{
	int prev = begin - 1;
	int cur = begin;
	int key = end;
	while (cur < end)
	{
		if (a[key] > a[cur] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[end], &a[++prev]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}	
	int div=PartSort3(a, left, right);
	//[left, div - 1] div [div+1,right]
	QuickSort(a, left, div-1);
	QuickSort(a,div+1,right);
}

//// 快速排序 非递归实现
//void QuickSortNonR(int* a, int left, int right);
//
//// 归并排序递归实现
//void MergeSort(int* a, int n);
//// 归并排序非递归实现
//void MergeSortNonR(int* a, int n);
//
//// 计数排序
//void CountSort(int* a, int n);
//
void PrintArray(int *a, int asize)
{
	for (int i = 0; i < asize; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
}