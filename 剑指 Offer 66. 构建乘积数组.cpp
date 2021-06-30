//剑指 Offer 66. 构建乘积数组
//给定一个数组 A[0, 1, …, n - 1]，请构建一个数组 B[0, 1, …, n - 1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 
//即 B[i] = A[0]×A[1]×…×A[i - 1]×A[i + 1]×…×A[n - 1]。不能使用除法。
//
//示例 :
//
//输入 : [1, 2, 3, 4, 5]
//输出 : [120, 60, 40, 30, 24]
//
//
//提示：
//
//所有元素乘积之和不会溢出 32 位整数
//a.length <= 100000
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//解法一：暴力法+剪枝；
// class Solution {
// public:
//     vector<int> constructArr(vector<int>& a) {
//         vector<int> res(a.size(),1);
//         for(int i=0;i<a.size();i++)
//         {
//             if(a[i]==1)      //剪枝：1*任何数==任何数
//                 continue;
//             for(int j=0;j<a.size();j++)
//             {
//                 if(i==j)
//                 {
//                     continue;
//                 }
//                 res[j]*=a[i];
//             }
//         }
//         return res;
//     }
// };

//解法二：动态规划：res[i]=left[i] * right[i];  即每个元素==左边元素集合的乘积+右边元素集合的乘积。
//先得到left[i]  和  right[i] ； 再相乘得到结果。

//多浪费了一点空间，方便理解，可以直接在left的基础上乘right，节省空间。或者在求right的时候，求出right直接与left相乘得到结果。
class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		//判空？

		vector<int> res(a.size(), 1);
		vector<int> left(a.size(), 1);
		vector<int> right(a.size(), 1);

		for (int i = 1; i<a.size(); i++)
		{
			left[i] = left[i - 1] * a[i - 1];
		}

		for (int i = a.size() - 2; i >= 0; i--)
		{
			right[i] = right[i + 1] * a[i + 1];
		}

		for (int i = 0; i<a.size(); i++)
		{
			res[i] = left[i] * right[i];
		}
		return res;
	}
};