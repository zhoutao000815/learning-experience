//679. 24 点游戏
//你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *， / ， + ， - ，(，) 的运算得到 24。
//
//示例 1:
//
//输入 : [4, 1, 8, 7]
//输出 : True
// 解释 : (8 - 4) * (7 - 1) = 24
//
// 示例 2 :
//
//  输入 : [1, 2, 1, 2]
//   输出 : False
//
//	注意 :
//
//	 除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2 / 3) = 12 。
//		 每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 - 1 - 1 - 1 - 1 是不允许的。
//		 你不能将数字连接在一起。例如，输入为[1, 2, 1, 2] 时，不能写成 12 + 12 。
//
//		 来源：力扣（LeetCode）
//	 链接：https ://leetcode-cn.com/problems/24-game
//	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// //回溯枚举：列举每一种可能性判断。
// //错误解法：从0开始，在card[4]里挑一个数字，进行加减乘除后保留结果，然后把这个数字删掉。
// //用得到的结果再从card[3]里挑一个数字，再进行加减乘除后保留结果，然后再把这个数字删掉。
// //如此下去后，当数字用完，判断得到的结果result==24？
// //显然错误，[9,1,1,2]    (9-1)*(1+2)  。那该怎么办呢？
// class Solution {
// public:
//     bool is_24point(list<double> l,int total,double result)
//     {
//         if(l.empty())
//             return result==total;

//         for(int i=0;i<l.size();i++)
//         {
//             list<double> l_next(l);
//             auto it=l_next.begin();
//             for(int j=0;j<i;j++)
//                 ++it;  
//             double num=*it;   
//             l_next.erase(it);                //去除第一个数字。    
//             if(is_24point(l_next,total,result+num) ||
//                 is_24point(l_next,total,result-num) ||
//                 is_24point(l_next,total,num-result) ||  
//                 is_24point(l_next,total,result*num) ||
//                 is_24point(l_next,total,result/num) || 
//                 is_24point(l_next,total,num/result))
//                 return true;
//         }
//         return false;
//     }

//     bool judgePoint24(vector<int>& cards) {
//         list<double> l;
//         for(auto &e:cards)
//             l.push_back(e);
//         return is_24point(l,24,0);
//     }
// };

// 游戏第一步，肯定是挑出两个数，然后算出一个数，替代这两个数。

// 然后，在三个数中玩 24 点，再挑出两个数，算出一个数，替代它们俩。

// 然后，在两个数中玩 24 点……

// 这就有了递归的思路。每次递归都会挑出两个数，我们尝试挑出不同的两数组合：

// 挑 1、2，基于它，继续递归。
// 挑 1、3，基于它，继续递归。
// 挑 ……
// 即通过 for 循环，枚举所有的两数组合（需要两层 for 循环），展开出不同选择所对应的递归分支。

// 作者：xiao_ben_zhu
// 链接：https://leetcode-cn.com/problems/24-game/solution/ying-gai-shi-man-hao-li-jie-de-si-lu-liao-by-xiao_/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
	bool judgePoint24(vector<int>& nums) {
		vector<double> digits;
		for (int num : nums) {
			digits.push_back((double)num);
		}
		return backTracking(digits);
	}

	bool backTracking(vector<double> digits) {
		int n = digits.size();
		if (n == 1) {
			return abs(digits[0] - 24) < 0.001;
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				vector<double> newDigits;
				for (int k = 0; k < n; k++) {
					if (k == i || k == j) continue;
					newDigits.push_back(digits[k]);
				}
				// 标识变量isValid初始为 false，默认会执行||后面的递归。
				// 一旦某个递归返回真，isValid就变为真，由于||的短路特性，后面的递归不会执行
				bool valid = false;
				// 加法
				newDigits.push_back(digits[i] + digits[j]);
				valid = valid || backTracking(newDigits);
				newDigits.pop_back();
				// 减法
				newDigits.push_back(digits[i] - digits[j]);
				valid = valid || backTracking(newDigits);
				newDigits.pop_back();
				newDigits.push_back(digits[j] - digits[i]);
				valid = valid || backTracking(newDigits);
				newDigits.pop_back();
				// 乘法
				newDigits.push_back(digits[i] * digits[j]);
				valid = valid || backTracking(newDigits);
				newDigits.pop_back();
				// 除法
				if (digits[j] != 0) {
					newDigits.push_back(digits[i] / digits[j]);
					valid = valid || backTracking(newDigits);
					newDigits.pop_back();
				}
				if (digits[i] != 0) {
					newDigits.push_back(digits[j] / digits[i]);
					valid = valid || backTracking(newDigits);
					newDigits.pop_back();
				}
				if (valid) return true;
			}
		}
		return false;
	}
};