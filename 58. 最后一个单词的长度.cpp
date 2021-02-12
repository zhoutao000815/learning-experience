﻿//58. 最后一个单词的长度
//给你一个字符串 s，由若干单词组成，单词之间用空格隔开。返回字符串中最后一个单词的长度。如果不存在最后一个单词，请返回 0 。
//
//单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
//
//示例 1：
//输入：s = "Hello World"
//输出：5
//
//示例 2：
//输入：s = " "
//输出：0
//
//提示：
//
//1 <= s.length <= 104
//s 仅有英文字母和空格 ' ' 组成
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/length-of-last-word
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
int lengthOfLastWord(char * s){
	int leng = 0;
	while (*s != '\0')
	{
		while (*s != ' ')      //记录单词长度，
		{
			leng++;
			s++;
			if (*s == '\0') //如果是最后一个单词紧挨‘\0’，直接返回当前长度。
			{
				return leng;
			}
		}

		while (*s == ' ')  //用来跳过空格，要么遇到‘\0’，要么遇到非空格字符
		{
			s++;
			if (*s == '\0')  //跳过空格过程中已经跳完了，返回最后一个单词长度
			{
				return leng;
			}
		}
		leng = 0;          //遇到非空格字符了，清0重计。
	}
	return leng;
}