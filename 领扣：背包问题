//125 · 背包问题（二）
//
//描述
//有 n 个物品和一个大小为 m 的背包.给定数组 A 表示每个物品的大小和数组 V 表示每个物品的价值.
//
//问最多能装入背包的总价值是多大 ?
//
//A[i], V[i], n, m 均为整数
//你不能将物品进行切分
//你所挑选的要装入背包的物品的总大小不能超过 m
//每个物品只能取一次
//m <= 1000m <= 1000\
//len(A), len(V) <= 100len(A), len(V) <= 100
//
//样例
//样例 1：
//
//输入：
//
//m = 10
//A = [2, 3, 5, 7]
//V = [1, 5, 2, 4]
//输出：
//
//9
//解释：
//
//装入 A[1] 和 A[3] 可以得到最大价值, V[1] + V[3] = 9
//
//样例 2：
//
//输入：
//
//m = 10
//A = [2, 3, 8]
//V = [2, 5, 8]
//输出：
//
//10
//解释：
//
//装入 A[0] 和 A[2] 可以得到最大价值, V[0] + V[2] = 10
//
//挑战
//O(nm) 空间复杂度可以通过, 你能把空间复杂度优化为O(m)吗？
//
//领扣链接：https ://www.lintcode.com/problem/125/

class Solution {
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A: Given n items with size A[i]
	* @param V: Given n items with value V[i]
	* @return: The maximum value
	*/

	//  经典01背包问题：思路：动态规划:
	/*
	状态：
	F(i, j): 前i个物品放入大小为j的背包中所获得的最大价值
	状态递推：对于第i个商品，有一种例外，装不下，两种选择，放或者不放
	如果装不下：此时的价值与前i-1个的价值是一样的
	F(i,j) = F(i-1,j)
	如果可以装入：需要在两种选择中找最大的
	F(i, j) = max{F(i-1,j), F(i-1, j - A[i]) + V[i]}
	F(i-1,j): 表示不把第i个物品放入背包中， 所以它的价值就是前i-1个物品放入大小为j的背包的最大价值
	F(i-1, j - A[i]) + V[i]：表示把第i个物品放入背包中，价值增加V[i],但是需要腾出j - A[i]的大小放
	第i个商品
	初始化：第0行和第0列都为0，表示没有装物品时的价值都为0
	F(0,j) = F(i,0) = 0
	返回值：F(n,m)
	*/
	//======================================================================================
	// int backPackII(int m, vector<int> &A, vector<int> &V) {
	//     vector<vector<int>> dp(A.size()+1,vector<int>(m+1,0));       //多开一行一列，并且初始化为0，  
	//     //因为背包重量为0时，可载价值为0.   第0个物品时，价值也为0.

	//      注意边界控制，因为多开了一行一列，小心使用下标。
	//     for(int i=1;i<dp.size();i++)     
	//     {
	//         for(int j=1;j<dp[0].size();j++)
	//         {
	//             if(A[i-1]>j)         //超重放不下，F(i,j) = F(i-1,j)
	//             {
	//                 dp[i][j]=dp[i-1][j];
	//             } 
	//             else                 //F(i, j) = max{F(i-1,j), F(i-1, j - A[i]) + V[i]}
	//             {
	//                 int newval=dp[i-1][j-A[i-1]]+V[i-1];
	//                 dp[i][j]=max(dp[i-1][j],newval);
	//             } 
	//         } 
	//     }
	//     return dp[A.size()][m];
	// }

	//思路不变：因为每个状态只需要dp[i-1][0] ~ dp[i-1][j]的数据，
	//所以先遍历背包还是物品都一样，而且不需要出除此之外的状态.
	//所以可以用滚动数组来进行空间优化，从O(N²)优化到O(N)。
	int backPackII(int m, vector<int> &A, vector<int> &V) {
		vector<int> dp(m + 1, 0);

		for (int i = m; i - A[0] >= 0; i--)      //第一行进行初始化，倒序进行，正序会导致重复放入。
			dp[i] = max(dp[i], dp[i - A[0]] + V[0]);

		for (int i = 1; i<A.size(); i++)
		{
			for (int j = m; j>0; --j)        //同上述理由。
			{
				if (A[i] <= j)             //放不下无需赋值，因为dp本身就是上一行的maxval。
				{
					dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
				}
			}
		}
		return dp[m];
	}
};