//剑指 Offer 64. 求1 + 2 + … + n
//求 1 + 2 + ... + n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。
//
//
//
//示例 1：
//
//输入 : n = 3
// 输出 : 6
//	  示例 2：
//
//  输入 : n = 9
//   输出 : 45
//
//https ://leetcode-cn.com/problems/qiu-12n-lcof/

// class add {
//     friend class Solution;
// public:
//     add()
//     {
//         rel+=_n;
//         _n++;
//     }
//     static int getrel()
//     {
//         return rel;
//     }
//     static void Init()
//     {
//         rel=0;
//         _n=1;
//     }
// private:
//     static int rel;
//     static int _n;
// };
// int add:: rel=0;
// int add:: _n=1;

// class Solution {
// public:
//     int Sum_Solution(int n) {
//         //由于测试用例是连着测试，不进行初始化会累加上一个用例。

//         //方法一:不用友元，用静态成员函数去初始化。
//         //add::Init();  
//         //==========================
//         //方法二：用友元类去初始化
//         add::rel=0;
//         add::_n=1;
//         //===========
//         //方法三：内部类，既保证了封装，又可以访问add类。
//         add sums[n];
//         return add::getrel();
//     }
// };
//方法三：内部类
class Solution{
public:
	int sumNums(int n) {
		rel = 0;
		_n = 1;
		add sums[n];
		return rel;
	}
	class add{
	public:
		add()
		{
			rel += _n;
			_n++;
		}

	};
private:
	static int rel;
	static int _n;
};
int Solution::rel = 0;
int Solution::_n = 1;