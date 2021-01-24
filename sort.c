#include"sort.h"
//��������
void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
//�����һ�����ݣ����뵽֮ǰ�����������С�
void ForInsert(int *a, int n)//  n����Ԫ�ظ���
{
//==============�Ӻ���ǰ�Ƚ�===============
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
// ���������㷨
void InsertSort(int* a, int n)
{
//����һ��
	//  i����Ԫ�ظ���
	for (int i = 1; i <= n; ++i)
	{
		ForInsert(a, i);
	}
//��������
	//   i���������±�
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

// ϣ������
void ShellSort(int* a, int n)
{
	// 1.gap>1�൱��Ԥ����������ӽ�����
	// 2.gap==1���൱��ֱ�Ӳ������򣬱�֤����
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

// ѡ������
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
// ������
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
//===����===
	int lastchild = n - 1;
	int lastparents = (lastchild - 1) / 2;
	for (int i = lastparents; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
//===������===
	int end = n - 1;
	while (end >= 1)
	{
		Swap(&a[0], &a[end]);  //end�������������һ��Ԫ�ص��±�
		AdjustDwon(a, end, 0);  //end����������ʣ�µ���Ч���ݸ���
		end--;
	}
}

// ð������
void BubbleSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int change = 0;//Ĭ��û�иı�
	while (begin < end)
	{
		for (int i = 0; i < end; i++)
		{
			if (a[i+1] < a[i])
			{
				Swap(&a[i+1], &a[i]);
				change = 1; //�����ж���������ı䡣
			}
		}
		if (!change)
		{
			break;
		}
		end--;
	}
}

//// ��������ݹ�ʵ��
//// 1����������hoare�汾
//int PartSort1(int* a, int left, int right)
//{
//
//}
////2�� ���������ڿӷ�
//int PartSort2(int* a, int left, int right);

//3����������ǰ��ָ�뷨
//���������β�ͣ��ұ���ͷ��                        
//prev��С�𳵵�ͷ��cur�Ǵ�𳵵�ͷ��������ߣ������������С�𳵵ĳ����ˣ����������ȥ��С�𳵵�ͷ��������𳵵ĳ��ᣬ��������ᵱ��𳵵�ͷ��
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

//// �������� �ǵݹ�ʵ��
//void QuickSortNonR(int* a, int left, int right);
//
//// �鲢����ݹ�ʵ��
//void MergeSort(int* a, int n);
//// �鲢����ǵݹ�ʵ��
//void MergeSortNonR(int* a, int n);
//
//// ��������
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