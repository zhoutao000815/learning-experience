//443. 压缩字符串
//给定一组字符，使用原地算法将其压缩。
//
//压缩后的长度必须始终小于或等于原数组长度。
//
//数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
//
//在完成原地修改输入数组后，返回数组的新长度。
//
//
//
//进阶：
//你能否仅使用O(1) 空间解决问题？
//
//
//
//示例 1：
//
//输入：
//["a", "a", "b", "b", "c", "c", "c"]
//
//输出：
//返回 6 ，输入数组的前 6 个字符应该是：["a", "2", "b", "2", "c", "3"]
//
//说明：
//"aa" 被 "a2" 替代。"bb" 被 "b2" 替代。"ccc" 被 "c3" 替代。
//示例 2：
//
//输入：
//["a"]
//
//输出：
//返回 1 ，输入数组的前 1 个字符应该是：["a"]
//
//解释：
//没有任何字符串被替代。
//示例 3：
//
//输入：
//["a", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b"]
//
//输出：
//返回 4 ，输入数组的前4个字符应该是：["a", "b", "1", "2"]。
//
//解释：
//由于字符 "a" 不重复，所以不会被压缩。"bbbbbbbbbbbb" 被 “b12” 替代。
//注意每个数字在数组中都有它自己的位置。
//
//
//提示：
//
//所有字符都有一个ASCII值在[35, 126]区间内。
//1 <= len(chars) <= 1000。

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/string-compression/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。//

#include<stdio.h>
#include<Windows.h>
#pragma warning (disable:4996)
int compress(char* chars, int charsSize){
	//我们在原字符数组上操作，空间复杂度O（1）,时间复杂度（N）。
	int cur = 0, prev = 0;  //  前后指针
	int curleng = 0;     //当前指向字符的重复长度
	int retleng = 0;     //返回数组的长度
	while (cur<charsSize)
	{
		while (*(chars + prev) == *(chars + cur)) //让前后指针指向的字符不同，且记录当前字符cur的重复次数
		{
			curleng++;
			cur++;
			if (cur == charsSize)   //越界退出
				break;
		}
		if (curleng >= 100)       //重复次数大于等于100
		{
			prev++;
			retleng++;
			chars[prev] = '0' + curleng / 100;  //取最高位
			curleng %= 100;
		}
		if (curleng >= 10)       ////重复次数大于等于10
		{
			prev++;
			retleng++;
			chars[prev] = '0' + curleng / 10;
			curleng %= 10;
			if (curleng == 1 || curleng == 0) //两种特殊情况，
			{
				prev++;
				retleng++;
				chars[prev] = '0' + curleng;
			}
		}
		if (curleng>1)            //当长度为2-9时才有记录，因为这个特性，导致10 和 11的特殊情况存在
		{
			prev++;
			retleng++;
			chars[prev] = '0' + curleng;
		}
		prev++;                //下一个返回位置
		retleng++;             //返回长度++ 
		curleng = 0;             //更新当前字符长度
		if (cur == charsSize)     //如果下一个字符越界，直接退出即可，无需再计。
		{
			break;
		}
		*(chars + prev) = *(chars + cur);  //更新下一个字符。
	}
	return retleng;
}