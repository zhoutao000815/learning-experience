//leetcode：
/*20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入 : "()"
输出 : true
	 示例 2 :

 输入 : "()[]{}"
  输出 : true
	   示例 3 :

   输入 : "(]"
	输出 : false
		 示例 4 :

	 输入 : "([)]"
	  输出 : false
		   示例 5 :

	   输入 : "{[]}"
		输出 : true		*/	

	//	来源：力扣（LeetCode）
	//链接：https ://leetcode-cn.com/problems/valid-parentheses
	//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//==============================================================================
//
/*
解题思路：
在栈中存放左括号，遇到右括号，则出栈顶元素，判断栈顶元素是否和当前括号匹配，
如果不匹配，则说明不匹配，返回false。遍历完所有字符，如果栈为空，则表示完全匹配。
如果字符还没遍历完，栈已经空了，说明右括号数量大于左括号，不匹配，返回false；
如果遍历完字符以后，栈不为空，说明左括号数量大于右括号，不匹配，返回false；
*/
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>
#pragma warning (disable:4996)
// 支持动态增长的栈
typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // 栈顶 数组下标，使用数组最后一个元素时，应该减一。    //也可以用对应的指示法。
	int _capacity; // 容量
}Stack;
// 初始化栈
Stack* StackInit(Stack* ps);
// 入栈
void StackPush(Stack* ps, STDataType data);
// 出栈
void StackPop(Stack* ps);
// 获取栈顶元素
STDataType StackTop(Stack* ps);
// 获取栈中有效元素个数
int StackSize(Stack* ps);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps);
// 销毁栈
void StackDestroy(Stack* ps);

// 初始化栈
Stack *StackInit(Stack* ps)
{
	if (ps == NULL)
	{
		Stack*ps = (Stack*)malloc(sizeof(Stack));
		if (ps)
		{
			ps->_a = (STDataType*)malloc(sizeof(STDataType));
			ps->_top = 0;
			ps->_capacity = 1;
		}
		return ps;
	}
	else
	{
		return ps;
	}
}
// 入栈
void StackPush(Stack* ps, STDataType data)
{
	if (ps->_top < ps->_capacity)
	{
		ps->_a[ps->_top] = data;
		ps->_top++;
	}
	else
	{
		STDataType*newtop = (STDataType*)realloc(ps->_a, sizeof(STDataType)*ps->_capacity * 2);
		{
			if (newtop)
			{
				ps->_a = newtop;
				ps->_capacity *= 2;
				ps->_a[ps->_top] = data;
				ps->_top++;
			}
		}
	}
}
// 出栈
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return;
	}
	else
	{
		ps->_top--;
	}
}
// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	return ps->_a[ps->_top - 1];
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top)
	{

	}
	else
	{

	}
	return !(ps->_top);
}
// 销毁栈
void StackDestroy(Stack* ps)
{
	int rel = StackEmpty(ps);
	if (rel)
	{

	}
	else
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_top = 0;
		ps->_capacity = 0;
	}
	free(ps);
	ps = NULL;
}
//判断是否匹配的接口
bool isValid(char * s){
	Stack*ps = NULL;
	ps = StackInit(ps);
	bool rel = true;
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(ps, *s);
			s++;
		}
		else
		{
			int Empty = StackEmpty(ps);
			if (Empty)
			{
				rel = false;
				break;
			}
			char TOP = StackTop(ps);
			if (*s == ']' && TOP != '[')
			{
				rel = false;
				break;
			}
			if (*s == ')' && TOP != '(')
			{
				rel = false;
				break;
			}
			if (*s == '}' && TOP != '{')
			{
				rel = false;
				break;
			}
			StackPop(ps);
			s++;
		}
	}
	int EMPTY = StackEmpty(ps);
	if (!EMPTY)
	{
		rel = false;
	}
	StackDestroy(ps);
	return rel;
}