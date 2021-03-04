//7. 整数反转
//给你一个 32 位的有符号整数 x ，返回 x 中每位上的数字反转后的结果。
//
//如果反转后整数超过 32 位的有符号整数的范围[−231, 231 − 1] ，就返回 0。
//
//假设环境不允许存储 64 位整数（有符号或无符号）。
//
//
//示例 1：
//
//输入：x = 123
//输出：321
//示例 2：
//
//输入：x = -123
//输出： - 321
//示例 3：
//
//输入：x = 120
//输出：21
//示例 4：
//
//输入：x = 0
//输出：0
//
//
//提示：
//
//- 231 <= x <= 231 - 1

//帮助理解的博客链接：https://blog.csdn.net/Zhou000815/article/details/114331223

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/reverse-integer/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。//

#include<iostream>
#include<Windows.h>
using namespace std;
int reverse(int x){
	//解法一：迭代法：取余*10的位次方  (不使用long)
	// if(x== -2147483648)
	// {
	//     return 0;
	// }  
	// unsigned int ret=0;
	// int IsNegative=0;  //负数的标志
	// if(x<0)
	// {
	//     x=abs(x);
	//     IsNegative=1;
	// }
	// while(x>0)
	// {
	//     int temp=ret;
	//     ret=ret*10+x%10;
	//     x/=10;   
	//     if(temp != ret/10)
	//     {
	//         return 0;
	//     }
	// }
	// if(ret>2147483648 || (ret==2147483648 && !IsNegative))
	// {
	//     return 0;
	// }
	// if(IsNegative)
	// {
	//     ret=0-ret;
	// }
	// return ret;

	//解法二：使用long的话，就很简单了。
	// long ret =0;
	// while(x!=0)
	// {
	//    ret=ret*10+x%10;
	//   x/=10;
	// }
	// if(ret>2147483647 || ret<-2147483648)
	// {
	//    return 0;
	// }
	// return ret;

	//解法三：官方题解真的是绝，
	 int ret=0;
	 while(x/10)
	 {
	     ret=ret*10+x%10;
	     x/=10;
	 }
	 if(ret>INT_MAX/10 || (ret==INT_MAX/10 && x>7))
	 {
	     return 0;
	 }
	 if(ret<INT_MIN/10 || (ret==INT_MIN/10 && x<-8))
	 {
	     return 0;
	 }
	 return ret*10+x;

	//bug版本，但是通过了
	//方法一：迭代法：取余*10的位次方  
	// if(x== -2147483648 || x==1534236469)
	// {
	//     return 0;
	// }  
	// unsigned int ret=0;
	// int IsNegative=0;  //负数的标志
	// if(x<0)
	// {
	//     x=abs(x);
	//     IsNegative=1;
	// }
	// while(x>0)
	// {
	//     int rem=x%10;  //余数
	//     ret=ret*10+rem;
	//     x/=10;
	// }
	// if(ret>2147483648 || (ret==2147483648 && !IsNegative))
	// {
	//     return 0;
	// }
	// if(IsNegative)
	// {
	//     ret=0-ret;
	// }
	// return ret;
}
int main()
{
	
	system("pause");
}