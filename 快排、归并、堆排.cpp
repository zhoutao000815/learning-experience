#include <iostream>
#include <vector>
using namespace std;

//快速排序：时间复杂度：最坏情况下（有序）：O(n²)   最好情况下（key每次都取到了中位数）：O（n log n）。稳定性：不稳定，空间复杂度（O（1））;
int part_sort(vector<int> &arry,int left,int right)
{
	int key = right;
	while (left < right)
	{
		while (arry[left] <= arry[key] && left < right)
			left++;
		while (arry[right] >= arry[key] && left < right)
			right--;
		swap(arry[left], arry[right]);
	}
	swap(arry[left], arry[key]);
	return left;
}

void quick_sort(vector<int> &arry, int begin, int end)
{
	if (begin >= end)
		return;
	int div = part_sort(arry, begin, end);
	quick_sort(arry, begin, div - 1);
	quick_sort(arry, div + 1, end);
}

//归并排序：时间复杂度：O（n log n）。空间复杂度：O（n）。稳定性：稳定。
void merge(vector<int> &arry, int left1, int right1, int left2, int right2,vector<int> &tmp)
{
	int index = left1;
	int begin = left1;
	int end = right2;
	while (left1 <= right1 && left2 <= right2)
	{
		if (arry[left1] < arry[left2])
			tmp[index++] = arry[left1++];
		else
			tmp[index++] = arry[left2++];
	}
	while (left1<=right1)
		tmp[index++] = arry[left1++];
	while (left2 <= right2)
		tmp[index++] = arry[left2++];
	memcpy(&arry[0] + begin, &tmp[0] + begin, (end - begin + 1)*sizeof(int));
}

void merge_sort(vector<int> &arry, int begin, int end, vector<int> &tmp)
{
	if (begin == end)
		return;
	int left1 = begin;
	int right1 = (begin + end) >> 1;
	int left2 = right1 + 1;
	int right2 = end;
	merge_sort(arry, left1, right1,tmp);
	merge_sort(arry, left2, right2,tmp);
	merge(arry, left1, right1, left2, right2,tmp);
}

//堆排序：时间复杂度：O（n log n）。空间复杂度：O（1）。稳定性：不稳定。
void ADjustdown(vector<int> &arry,int root,int end)
{
	int parents = root;
	int child = parents * 2 + 1; 
	while (child < end)
	{
		if (child + 1 < end && arry[child+1] > arry[child])
			child++;
		if (arry[parents] < arry[child])
		{
			swap(arry[parents], arry[child]);
			parents = child;
			child = parents * 2 + 1;
		}
		else
			break;
	}
}

void heap_sort(vector<int> &arry)
{
	//建堆 （时间复杂度：O（logn））
	for (int i = ((arry.size() - 2) >> 1); i >= 0; i--)
	{
		ADjustdown(arry, i,arry.size());
	}
	////堆排 （时间复杂度：O（n））
	for (int i = arry.size(); i > 1; i--)
	{
		swap(arry[0], arry[i - 1]);
		ADjustdown(arry, 0, i - 1);
	}
}
int main()
{
	std::vector<int> arry = { 6, 2, 5, 6, 8, 1, 9, 3, 4 };

	//quick_sort(arry, 0, arry.size() - 1);

	//vector<int> tmp(arry.size(), 0);
	//merge_sort(arry, 0, arry.size()-1, tmp);

	heap_sort(arry);

	for (auto &v : arry)
		std::cout << v << " ";
	std::cout << std::endl;
	return 0;
}