#include"Stack.h"
// 初始化栈
Stack* StackInit()
{
	Stack* ps = (Stack*)malloc(sizeof(Stack));
	if (ps)
	{
		ps->_a = (STDataType*)malloc(sizeof(STDataType));
		ps->_top = 0;                       //这里如果用0，代表第一个元素的位置，那就是数组下标法，先进行数据填入，再将数组下标++。显示栈顶数据，需要将[ps->_top -1]。
		ps->_capacity = 1;					
	}
	return ps;
}
// 入栈
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_top < ps->_capacity)
	{	
		ps->_a[ps->_top] = data;//注意！数组下标！这里要先将数据放进去，再给top++，如果先++，就越界访问了。
		ps->_top++;
	}
	else
	{
		STDataType*newtop = (STDataType*)realloc(ps->_a, sizeof(STDataType)*ps->_capacity*2);
		{
			if (newtop)
			{
				ps->_a = newtop;
				ps->_capacity *= 2;
				ps->_a[ps->_top] = data;//注意！数组下标！这里要先将数据放进去，再给top++，如果先++，就越界访问了。
				ps->_top++;
			}
		}
		printf("当前容量已满！扩容中！\n");
		Sleep(2000);
		printf("扩容成功！\n");
	}
}
// 出栈
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		printf("空栈！\n");
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
	assert(ps);
	printf("StackTop:%c\n", ps->_a[ps->_top-1]);// 数组下标法:这里的减一是因为a[假设为5]的 a[5]是非法的，越界的，
	return ps->_a[ps->_top-1];
}
// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	int size = ps->_top;
	printf("%d\n", size);
	return size;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top)
	{
		printf("非空栈！\n");
	}
	else
	{
		printf("空栈！\n");
	}
	return !(ps->_top);
}
// 销毁栈
void StackDestroy(Stack* ps)
{
	int rel=StackEmpty(ps);
	if (rel)
	{
		printf("空栈！\n");
	}
	else
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_top = 0;
		printf("销毁成功！\n");
	}
	free(ps);
	ps = NULL;
}