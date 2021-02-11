//9. 回文数
//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//
//回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。
//
//
//
//示例 1：
//
//输入：x = 121
//输出：true
//示例 2：
//
//输入：x = -121
//输出：false
//解释：从左向右读, 为 - 121 。 从右向左读, 为 121 - 。因此它不是一个回文数。
//示例 3：
//
//输入：x = 10
//输出：false
//解释：从右向左读, 为 01 。因此它不是一个回文数。
//示例 4：
//
//输入：x = -101
//输出：false
//
//
//进阶：你能不将整数转为字符串来解决这个问题吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/palindrome-number
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
bool isPalindrome(int x){
	if (x<0 || (x != 0 && x % 10 == 0))  //负数和最后一位为0 的直接返回假
	{
		return false;
	}
	if (x >= 0 && x<10)  //0-9直接返回真
	{
		return true;
	}
	int xcopy = x;
	int xcopy2 = x;
	int xlong = 0;
	while (xcopy != 0)
	{
		xlong++;
		xcopy /= 10;
	}
	int halflong = xlong / 2 + xlong % 2;

	//方法一：弄成字符串，然后逆置一半，在对比。
	//-----------------------------------
	/*int* arr=(int *)malloc(sizeof(int)*xlong);
	int i=-1;   //记录数组下标最大
	while(xcopy2!=0)
	{
	arr[++i]=xcopy2%10;
	xcopy2/=10;
	}
	printf("%d",i);
	int j=0;
	while(halflong--)
	{
	if(arr[i--]!=arr[j++])   //偶数位次则刚好，奇数位次则最后一一个指向中位数也能解决。
	{
	return false;
	}
	}
	return true;*/
	//-----------------------------------

	//方法二：取最高位的除数和最低位的余数对比，对比后消除
	//-----------------------------------
	int max = 1;
	while (--xlong)  //先--，位次由10的零次方开始算的，
	{
		max *= 10;
	}
	while (halflong--)
	{
		int a = xcopy2 / max;          //即使奇数个位次，中位数除100
		if (a != xcopy2 % 10)         //和最后一位取10的余数一样相同
		{
			return false;
		}
		xcopy2 = xcopy2 - (a*max);  //消除最高位
		xcopy2 /= 10;             //消除最低位  
		max /= 100;               //消除两位，自然高位也也少两位。
	}
	return true;

	//-----------------------------------

	//方法三，（官方题解）直接取一半回文数字比较。
	// 特殊情况：
	// 如上所述，当 x < 0 时，x 不是回文数。
	// 同样地，如果数字的最后一位是 0，为了使该数字为回文，
	// 则其第一位数字也应该是 0
	// 只有 0 满足这一属性
	/*if (x < 0 || (x % 10 == 0 && x != 0)) {
	return false;
	}

	int revertedNumber = 0;
	while (x > revertedNumber) {
	revertedNumber = revertedNumber * 10 + x % 10;
	x /= 10;
	}

	// 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
	// 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
	// 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
	return x == revertedNumber || x == revertedNumber / 10;
	*/
}