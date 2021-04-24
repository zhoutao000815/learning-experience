//剑指 Offer 63. 股票的最大利润
//假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
//
//
//
//示例 1:
//
//输入 : [7, 1, 5, 3, 6, 4]
//输出 : 5
// 解释 : 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6 - 1 = 5 。
//	  注意利润不能是 7 - 1 = 6, 因为卖出价格需要大于买入价格。
//	  示例 2 :
//
//  输入 : [7, 6, 4, 3, 1]
//   输出 : 0
//	解释 : 在这种情况下, 没有交易完成, 所以最大利润为 0。
//
//
//		 限制：
//
//		 0 <= 数组长度 <= 10 ^ 5
//
//		 来源：力扣（LeetCode）
//	 链接：https ://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof
//	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//方法一:暴力法
		//用时间线后面的值，减去时间线前面的值，比较减后的结果，得出最大利润。/超时/
		// int size=prices.size();
		// int maxPro=0;
		// for(int i=0;i<size;i++)
		// {
		//     for(int j=i+1;j<size;j++)
		//     {
		//         maxPro=max(maxPro,prices[j]-prices[i]);
		//     }
		// }
		// return maxPro;

		//方法二:一次遍历
		//假设第一天为最低点，往后遍历的时候，遇到更低的就更新最低点，同时用当天收入减去最低点就是当天利润。
		//同时更新最低点和最大利润。
		// int maxpro=0,minprice=INT_MAX;
		// for(int i=0;i<prices.size();i++)
		// {
		//     minprice=min(minprice,prices[i]);
		//     maxpro=max(maxpro,prices[i]-minprice);
		// }
		// return maxpro;

		//方法三:滑动窗口
		//双指针：由于需要确定先后位置，差值最大能为多少，所以一定要全部遍历一遍才行，滑动窗口很适合。
		//当prices【left】<=prices【right】，与之前的利润比较取较大值，right++；
		//当prices【left】>prices【right】,right就是新的最低点，此点之后，可能会出现更大的利润，但是也有可能不出现。
		//不过没有关系，之前的最大利润已经保存了，我们仅仅需要测试之后的利润即可，left=right，right++；直到遍历结束。
		if (prices.size() == 0 || prices.size() == 1)
		{
			return 0;
		}
		int left = 0, right = 1, size = prices.size();
		int maxPro = 0;
		while (right<size)
		{
			if (prices[left] <= prices[right])
			{
				maxPro = max(maxPro, prices[right] - prices[left]);  //比较保存利润。
				right++;                                        //
			}
			else
			{
				//prices[left]>prices[right]
				//因为这里确定是比之前最低点更低的，之前的最大利润也保存在maxpro里，也不需要中间的数据了，直接调整指向。
				left = right;
				right++;
			}
		}
		return maxPro;
		//方法四：动态规划
	}
};