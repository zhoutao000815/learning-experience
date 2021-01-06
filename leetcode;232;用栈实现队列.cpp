//博客链接:https://blog.csdn.net/Zhou000815/article/details/112308690
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>
#pragma warning (disable:4996)
// 支持动态增长的栈
typedef int STDataType;
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
int  StackSize(Stack* ps);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
bool StackEmpty(Stack* ps);
// 销毁栈
void StackDestroy(Stack* ps);

// 初始化栈
Stack *StackInit(Stack* ps)
{
	ps = (Stack*)malloc(sizeof(Stack));
	if (ps)
	{
		ps->_a = (STDataType*)malloc(sizeof(STDataType)* 4);
		ps->_top = 0;                       //这里如果用0，代表第一个元素的位置，那就是数组下标法，先进行数据填入，再将数组下标++。显示栈顶数据，需要将[ps->_top -1]。
		ps->_capacity = 4;
	}
	return ps;
}
// 入栈
void StackPush(Stack* ps, STDataType data)
{
	if (ps->_top < ps->_capacity)
	{
		ps->_a[ps->_top] = data;//注意！数组下标！这里要先将数据放进去，再给top++，如果先++，就越界访问了。
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
				ps->_a[ps->_top] = data;//注意！数组下标！这里要先将数据放进去，再给top++，如果先++，就越界访问了。
				ps->_top++;
			}
		}

	}
}
// 出栈
void StackPop(Stack* ps)
{
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
// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	int size = ps->_top;
	return size;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
bool StackEmpty(Stack* ps)
{
	if (ps->_top)
	{
		return false;
	}
	else
	{
		return true;
	}
}
// 销毁栈
void StackDestroy(Stack* ps)
{
	int rel = StackEmpty(ps);
	free(ps->_a);
	ps->_a = NULL;
	free(ps);
	ps = NULL;
}
typedef struct {
	Stack* qPush;
	Stack* qPop;
} MyQueue;
/** Initialize your data structure here. */
int myQueuePeek(MyQueue* obj);

MyQueue* myQueueCreate() {
	MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
	q->qPush = StackInit(q->qPush);
	q->qPop = StackInit(q->qPop);
	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(obj->qPush, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	int peek = myQueuePeek(obj);
	StackPop(obj->qPop);
	return peek;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (!StackEmpty(obj->qPop))
	{
		return StackTop(obj->qPop);
	}
	while (!StackEmpty(obj->qPush))
	{
		StackPush(obj->qPop, StackTop(obj->qPush));
		StackPop(obj->qPush);
	}
	return StackTop(obj->qPop);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	if (StackEmpty(obj->qPush) && StackEmpty(obj->qPop))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(obj->qPush);
	StackDestroy(obj->qPop);
	free(obj);
}

/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/