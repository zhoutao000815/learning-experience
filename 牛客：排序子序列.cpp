//链接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471
//来源：牛客网
//
//牛牛定义排序子序列为一个数组中一段连续的子序列, 并且这段子序列是非递增或者非递减排序的。牛牛有一个长度为n的整数数组A, 他现在有一个任务是把数组A分为若干段排序子序列, 牛牛想知道他最少可以把这个数组分为几段排序子序列.
//如样例所示, 牛牛可以把数组A划分为[1, 2, 3]和[2, 2, 1]两个排序子序列, 至少需要划分为2个排序子序列, 所以输出2
//
//输入描述 :
//输入的第一行为一个正整数n(1 ≤ n ≤ 10 ^ 5)
//
//第二行包括n个整数A_i(1 ≤ A_i ≤ 10 ^ 9), 表示数组A的每个数字。
//
//
//输出描述 :
//输出一个整数表示牛牛可以将A最少划分为多少段排序子序列
//示例1
//输入
//6
//1 2 3 2 2 1
//输出
//2

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int size = 0;
	cin >> size;
	vector<int> sum(size, 0);
	for (auto &e : sum)
	{
		cin >> e;
	}
	sum.resize(size + 1);
	//多开一个配合序列变化的检测。
	//当最后一个元素可以配在之前的子序列里，直接i==size结束退出。
	//当最后一个元素单独为一个子序列时，在检测时，如果不多开一个空间，+1会导致越界。
	//多开后，检测结果不重要，因为多开的那个是无效数据，最后元素单独为排序子序列。
	//i++后，i==size，ret++。刚好完成计数。
	int ret = 0;
	for (int i = 0; i<size; i++)
	{
		if (sum[i]>sum[i + 1])
		{
			while (i<size && sum[i]>sum[i + 1])
			{
				i++;
			}
			ret++;

		}
		else if (sum[i] == sum[i + 1])
		{
			while (i<size && sum[i] == sum[i + 1])
			{
				i++;
			}
		}
		else
		{
			while (i<size && sum[i]<sum[i + 1])
			{
				i++;
			}
			ret++;
		}
	}
	cout << ret;
	return 0;
}