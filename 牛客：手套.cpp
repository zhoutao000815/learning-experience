//链接：https://www.nowcoder.com/questionTerminal/365d5722fff640a0b6684391153e58d8
//来源：牛客网
//
//手套
//热度指数：2418时间限制：C / C++ 3秒，其他语言6秒空间限制：C / C++ 32M，其他语言64M
//算法知识视频讲解
//在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。
//
//给定颜色种数n(1≤n≤13), 同时给定两个长度为n的数组left, right, 分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。
//
//测试样例：
//4, [0, 7, 1, 6], [1, 5, 0, 6]
//返回：10(解释：可以左手手套取2只，右手手套取8只)


//思路:当有一种颜色左手或右手为0时，取出这种颜色所有手套，删掉。
//剩下的都是两只手都有的，保证将手套总数最小的那只手的所有颜色取出；另外一只手，取一只即可。

class Gloves {
public:
	int getadd(vector<int> &v)//总数最小的那只手，排序，最小的取一只，其他累加。
	{
		sort(v.begin(), v.end());
		int count = 1;      //最小的手套数取一只。
		for (int i = v.size() - 1; i>0; i--)
		{
			count += v[i];
		}
		return count;
	}

	int findMinimum(int n, vector<int> left, vector<int> right) {
		int min = 0;
		for (size_t i = 0; i<left.size(); i++)
		{
			if (left[i] == 0 || right[i] == 0)
			{
				min += left[i];
				min += right[i];
				left.erase(left.begin() + i);
				right.erase(right.begin() + i);
				i--;
			}
		}
		int leftsize = 0, rightsize = 0;
		for (size_t i = 0; i<left.size(); i++)
		{
			leftsize += left[i];
			rightsize += right[i];
		}
		if (leftsize<rightsize)
		{
			min += getadd(left);
		}
		else
		{
			min += getadd(right);
		}
		min++;//另外一只手，取一只即可。
		return min;
	}
};