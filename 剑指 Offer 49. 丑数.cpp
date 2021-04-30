//剑指 Offer 49. 丑数
//我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
//
//示例 :
//
//输入 : n = 10
//输出 : 12
// 解释 : 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
//  说明 :
//
//1 是丑数。
//n 不超过1690。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/chou-shu-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//暴力法：超时   
// class Solution {
// public:
//     int nthUglyNumber(int n) { 

//         int uglyNum=1;
//         int tmp=1;
//         while(true)
//         {                      
//             while(uglyNum%5==0)
//             {
//                 uglyNum/=5;
//             }
//             while(uglyNum%3==0)
//             {
//                 uglyNum/=3;
//             }
//             while(uglyNum%2==0)
//             {
//                 uglyNum>>=1;
//             }            
//             if(uglyNum!=1)
//             {
//                 tmp++;
//                 uglyNum=tmp;
//                 continue;
//             }
//             n--;
//             uglyNum=tmp;          
//             if(n==0)
//             {               
//                 break;
//             }
//             tmp++;
//             uglyNum=tmp;        
//         }
//         return uglyNum;
//     }
// };


//三指针法
class Solution {
public:
	int nthUglyNumber(int n) {
		//初始化，第一个丑数为1。
		int num2 = 0, num3 = 0, num5 = 0;
		vector<int> uglynumarr(1, 1);

		int ncount = n;//计数
		while (--ncount)//第一个已经写好了，所以采用前置--
		{
			int uglynum = min(min(uglynumarr[num2] * 2, uglynumarr[num3] * 3), uglynumarr[num5] * 5);
			uglynumarr.push_back(uglynum);
			if (uglynum == uglynumarr[num2] * 2)
			{
				num2++;
			}
			if (uglynum == uglynumarr[num3] * 3)
			{
				num3++;
			}
			if (uglynum == uglynumarr[num5] * 5)
			{
				num5++;
			}
		}
		return uglynumarr[n - 1];
	}
};