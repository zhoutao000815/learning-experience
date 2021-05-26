//链接：https://www.nowcoder.com/questionTerminal/b89b14a3b5a94e438b518311c5156366
//来源：牛客网
//
//奇数位上都是奇数或者偶数位上都是偶数
//热度指数：2587时间限制：C / C++ 1秒，其他语言2秒空间限制：C / C++ 32M，其他语言64M
//算法知识视频讲解
//给定一个长度不小于2的数组arr。 写一个函数调整arr，使arr中要么所有的偶数位上都是偶数，要么所有的奇数位上都是奇数上。 
//要求：如果数组长度为N，时间复杂度请达到O(N)，额外空间复杂度请达到O(1), 下标0, 2, 4, 6...算作偶数位, 下标1, 3, 5, 7...算作奇数位，
//例如[1, 2, 3, 4]调整为[2, 1, 4, 3]即可
//
class Solution {
public:
	/**
	*  奇数位上都是奇数或者偶数位上都是偶数
	*  输入：数组arr，长度大于2
	*  len：arr的长度
	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	*/

	//这破烂题目真的辣鸡！！！一点都不严谨！
	//一定要从尾巴开始调整吗？
	//下面那种从头开始调整不符合题意吗？
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int i = 0, j = 1, end = len - 1;
		while (i < len && j < len)
		{
			if (arr[end] % 2 == 0)
			{
				swap(arr[i], arr[end]);
				i += 2;
			}
			else
			{
				swap(arr[j], arr[end]);
				j += 2;
			}
		}
		/*
		int two=0,one=1;
		while(one<len && two<len)
		{
		while(two<len && arr[two]&1==0)
		{
		two+=2;
		}
		while(one<len && arr[one]&1==1)
		{
		one+=2;
		}
		if(one<len && two<len)
		swap(arr[one],arr[two]);
		else
		return;
		}*/
	}
};