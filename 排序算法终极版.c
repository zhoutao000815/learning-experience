#include"sort.h"
#include"Stack.h"
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
		//��beginλ�øպ����������ʱ�򣬵�һ�ν����������ˡ����ǽ���������
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
// 1����������hoare�汾
//����汾
int PartSort1(int* a, int left, int right)
{
	int key = right;
	//keyȷ��Ϊ���ұߵģ���Ҫ������ȿ�ʼ�ң�ȷ��Ϊ����ߵģ��ʹ����ұ߿�ʼ�ҡ�
	//Ϊʲô��?   ԭ���ȴ��Ǳ߿�ʼ�ң��˳�ѭ��ʱ����ָ��ָ��ľ����������������У�ָ�������Լ���һ�εġ�
	//�����������ұ�Ϊkey�����ұ��ȿ�ʼ��С�ģ�����˳�ѭ��ʱ��ָ���غ�ָ����Ǳ�keyС�ģ���������λ��λ�ô���
	while (left < right)
	{
		//��ǰ���б�key���
		while (a[left] <= a[key] && left < right)//һ��Ҫ��left<right���������Ѿ����������»�Խ�硣
		{
			left++;
		}
		//�Һ���б�keyС��
		while (a[right] >= a[key] && left < right)
		{
			right--;
		}
		//�ҵ��󽻻���
		Swap(&a[left], &a[right]);
	}
	//��󽻻�key���������ָ���غϵ�λ�ã�ȷ������λ����
	Swap(&a[left], &a[key]);
	return left;
}
////2�� ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int key = right;//����Ӿ�����λ����
	//��һ���汾�ı��Σ���Զ��Ժ����һЩ��
	//���������ұ��ڿӣ��ʹ���߿�ʼ�����ݣ�ȥ�����ӣ�����ߵ�����ȥ���ұߵĿӣ���߳����µĿӣ��ٴ��ұ�����������ߵĿӣ�ѭ��������
	//ֱ������ָ���غϣ�����غ�λ�þ��ǿӣ�����ȷ��λ�õ���λ����
	while (left < right)
	{
		while (a[left] <= a[key] && left < right)
		{
			left++;
		}
		Swap(&a[left], &a[key]);
		key = left;
		while (a[right] >= a[key] && left < right)
		{
			right--;
		}
		Swap(&a[right], &a[key]);
		key = right;
	}
	//Swap(&a[left], &a[key]);
	return left;
}

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
int Mid3nums(int *arr,int a, int b, int c)
{
	if (arr[a] <arr[b] && arr[b] <arr[c])
		return b;
	else if (arr[c] < arr[b] && arr[b] < arr[a])
		return b;
	else if (arr[c] <arr[a] && arr[a] < arr[b])
		return a;
	else if (arr[b] < arr[a] && arr[a] <arr[c])
		return a;
	else if (arr[b]< arr[c] && arr[c] < arr[a])
		return c;
	else //(arr[a]< arr[c] && arr[c] < arr[b])
		return c;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	//����Ūһ������ȡ�з���ȷ��������������������ʱ�临�Ӷȡ�
	int mid = (left + right) / 2;
	int Midarr=Mid3nums(a,left, mid, right);
	Swap(&a[Midarr], &a[right]);
	int div=PartSort3(a, left, right);
	//[left, div - 1] div [div+1,right]
	QuickSort(a, left, div-1);
	QuickSort(a,div+1,right);
}

//// �������� �ǵݹ�ʵ��
//����ջ����Ҫ����������±꣬�ֶ�����±�������ֱ��ջΪ�գ�������Ҫ�ٶ��������򡣽�����
void QuickSortNonR(int* a, int left, int right)
{
	if (a == NULL)
	{
		return;
	}
	Stack* ps=StackInit();
	StackPush(ps, right);
	StackPush(ps, left);
	while (!StackEmpty(ps))
	{
		int begin = StackTop(ps);
		StackPop(ps);
		int end = StackTop(ps);
		StackPop(ps);
		int div = PartSort3(a, begin ,end);
		if (begin<div-1)
		{
			StackPush(ps, div - 1);
			StackPush(ps, begin);
		}
		if (div + 1 < end)
		{
			StackPush(ps, end);
			StackPush(ps, div + 1);
		}
	}
	StackDestroy(ps);
}


//�鲢����ԭ��:�ϲ������������ݶΣ�һ������ʱ��������ģ�������ֻ����һ�����ݿ�ʼ�����������ϲ������������Ϻϲ���
//// �鲢����ݹ�ʵ��
void MergeTwoOrderedarr(int *a, int* arr2, int left1, int right1, int left2, int right2, int*returnA)//��Ϊ��������һ������ֳ����ι鲢������ֻ����a��û��arr2.
{
	int begin = left1;
	int end = right2;
	int keyindex = left1;
	while (right1 >= left1 && right2 >= left2)
	{	
		if (a[left1] < a[left2])
		{
			returnA[keyindex++] = a[left1];
			left1++;
		}
		else
		{
			returnA[keyindex++] = a[left2];
			left2++;
		}
	}
	while (left1 <= right1)
	{
		returnA[keyindex++] = a[left1];
		left1++;
	}
	while (left2 <= right2)
	{
		returnA[keyindex++] = a[left2];
		left2++;
	}
	memcpy(a + begin, returnA + begin, sizeof(int)*(end - begin + 1));//ΪʲôҪ��ָ���begin��? ��ע���ָ��+1�������ָ����ָ�����������+1��
	//��Ϊÿ�ο����ź�˳�����ʱ������ÿ�ζ��������һ����ʼ������
	//                                 ��Ϊ���õ�[ ]���䣬����end��begin��ʾ�±꣬����+1��ʾ��ȷ������Ԫ�ظ�����
}
void _MergeSort(int *a, int begin, int end, int *returnA)//����[ ]����ұա�
{
	if (end == begin)
	{
		return ;
	}
	int keyindex = begin; //����ָ��returnA�������±ꡣ
	int left1 = begin;
	int right1 = (end+begin) / 2;  //��Ϊ�����������±�����[ ]���������/2�����������ݵ��±ꡣ
	int left2 = right1 + 1;
	int right2 = end;
	_MergeSort(a, left1, right1, returnA);
	_MergeSort(a, left2, right2, returnA);
	MergeTwoOrderedarr(a, NULL, left1, right1, left2, right2, returnA);
}

void MergeSort(int* a, int n)
{
	//��Ϊ��������Ҫ������С�ϲ����������ԭ������������ܻᵼ�����ݶ�ʧ�����Դ����ȴ�С�����飬��ΪҪ�ݹ飬�����������ڣ�����maclloc��
	int* returnA = (int *)malloc(n*sizeof(a[0]));
	_MergeSort(a, 0, n-1, returnA);
	free(returnA);
}

//// �鲢����ǵݹ�ʵ�� 
//��Ϊ�������ݸ�����һ������2��n�η������ԣ���ѭ�������������ݵ��±꣬�ڱ�֤��Խ�������£������鲢��
//����ײ��������飨GroupSize=1���鲢��ȫ���鲢�ú��٣�GroupSize=2���鲢���٣�GroupSize=4���鲢��......����GroupSize=n/2)ʱ���ڶ����±����aSizeʱ�������ڶ����±ꡣ�鲢������
void MergeSortNonR(int* a, int aSize)
{
	//��Ϊ��������Ҫ������С�ϲ����������ԭ������������ܻᵼ�����ݶ�ʧ�����Դ����ȴ�С�����飬��ΪҪ�ݹ飬�����������ڣ�����maclloc��
	int* returnA = (int*)malloc(aSize*sizeof(a[0]));
	int GroupSize = 1;
	int left1 ;	     //����[ ]����
	int right1;  
	int left2;
	int right2;
	int i = GroupSize;
	while (GroupSize < aSize)  //������������С��
	{
		for (i = 1; i < aSize; i += (2 * GroupSize))//����ÿһ������鲢
		{
			left1 = i-1;
			right1 = left1 + GroupSize - 1;
			left2 = right1 + 1;
			right2 = left2 + GroupSize - 1;
			//���ݸ��������飬�����������
			//���1�����ݲ�����һ��
			//���2�����ݹ���һ�飬�����ڶ��顣
			//���3�����ݹ����������顣
			if (right1 < aSize)
			{
				if (right2 < aSize)
				{
					MergeTwoOrderedarr(a, NULL, left1, right1, left2, right2, returnA); //���3��
				}
				else
				{			
					right2 = aSize - 1;
					MergeTwoOrderedarr(a, NULL, left1, right1, left2, right2, returnA);//���2��
				} 
			}
			else
			{
				break;  //���1.
			}
		}
		GroupSize *= 2;
	}
	free(returnA);
}

// ��������
void CountSort(int* a, int n)
{
	//���ԭ����������Сֵ�����+1���Ǽ�������Ĵ�С��
	int Min = a[0];
	int Max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i]>Max)
		{
			Max = a[i];
		}
		if (a[i]<Min)
		{
			Min = a[i];
		}
	}
	int CountSize = abs(Max - Min + 1);
	int* CountArr = (int*)calloc(CountSize,sizeof(a[0]));
	//��ʼ����
	for (int i = 0; i < n; i++)
	{
		CountArr[a[i] - Min]++;        //CountArr[a[i] - a[Min]+1-1]++;+1��Ϊ��Ӧ�ļ����еڼ�����-1��Ϊ�±ꡣ
	}
	//���������������ԭ���飬�������
	int j = 0;
	int aKey = 0;
	for (j; j < CountSize; j++)
	{
		while (CountArr[j]--)
		{
			a[aKey++] = j + Min;
		}
	}
	free(CountArr);
}

void PrintArray(int *a, int asize)
{
	for (int i = 0; i < asize; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
}