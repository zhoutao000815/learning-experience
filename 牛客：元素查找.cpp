//链接：https://www.nowcoder.com/questionTerminal/72ff6503455c4a008675e79247ef2a3a
//来源：牛客网
//
//元素查找
//热度指数：8271时间限制：C / C++ 3秒，其他语言6秒空间限制：C / C++ 32M，其他语言64M
//
//给定一个数组A及其大小n，同时给定需要查找的元素值x，已知数组A是由一个排过序的数组向左移位了一定长度得到的，请返回x在现数组的位置(位置从零开始)。保证数组中元素互异。
//
//测试样例：
//[6, 1, 2, 3, 4, 5], 6, 6
//返回：0

#include<iostream>
#include<vector>
using namespace std;

//=====================================================================
	//解法一:两次二分查找

	/*int binsearch(vector<int> & tmp, int x)
	{
		if (x<tmp[0] || x>tmp[tmp.size() - 1])
		{
			return -1;
		}
		int left = 0, right = tmp.size() - 1;
		int mid = left + (right - left) / 2;
		while (left<=right)
		{
			mid = left + (right - left) / 2;
			if (x>tmp[mid])
			{
				left = mid + 1;
			}
			else if (x<tmp[mid])
			{
				right = mid - 1;
			}
			else
			{
				return mid;
			}
		}
		return -1;
	}

	int findElement(vector<int> A, int n, int x) {
		if (A.size() == 0)
		{
			return 0;
		}
		size_t i = 0;
		while (i<A.size() - 1 && A[i]<A[i + 1])
		{
			i++;
		}
		vector<int>::iterator begin = A.begin();
		vector<int> halfA0(A.begin(), A.begin() + i + 1);
		vector<int> halfA1(A.begin() + i + 1, A.end());
		int rel0 = binsearch(halfA0, x);
		int rel1 = binsearch(halfA1, x);
		if (rel0 != -1)
		{
			return rel0;
		}
		if (rel1 != -1)
		{
			return rel1+halfA0.size();
		}
		return -1;
	}

	int main()
	{
		int arr[6] = {6 ,1, 2, 3, 4, 5 };

		vector<int> A(arr, arr + 6);
		cout<<findElement(A, 6, 3);

		return 0;
	}
*/

//=====================================================================

//=====================================================================
		//解法二：加强版二分查找
		//发生左旋后，原数组会分成两个长度不一的递增子数组，判断出x是哪一个子数组里的后，调整位置，就变成了普通二分。
		int findElement(vector<int> A, int n, int x) {
			int left = 0, right = n - 1, mid;
			while (left <= right) {
				mid = (left + right) / 2;
				if (A[mid] == x)
					return mid;
				if (A[mid]<x) {
					//A[mid]<A[left] 说明右边的子数组长（无重复元素），且x>A[right]说明x在左边的短子数组里，
					if (A[mid]<A[left] && x>A[right])  right = mid - 1;
					else left = mid + 1;      //x<A[right]则说明在右边的长子数组里。
				}
				else {
					//A[mid]>A[left]说明左边的子数组长（无重复元素），且x<A[left]，说明x在右边的短子数组里，
					if (A[mid]>A[left] && x<A[left])  left = mid + 1;
					else right = mid - 1;      //x>A[left]说明在左边的长子数组里。
				}
			}
			return -1;
		}