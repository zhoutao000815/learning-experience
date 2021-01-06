//博客链接：https://blog.csdn.net/Zhou000815/article/details/112300652
//225. 用队列实现栈
//使用队列实现栈的下列操作：

//push(x) --元素 x 入栈
//pop() --移除栈顶元素
//top() --获取栈顶元素
//empty() --返回栈是否为空
//注意 :
//
//你只能使用队列的基本操作-- 也就是 push to back, peek / pop from front, size, 和 is empty 这些操作是合法的。
//你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列, 只要是标准的队列操作即可。
//你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/implement-stack-using-queues
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>
#pragma warning (disable:4996)
typedef int QDataType;
// 链式结构：表示队列
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;
// 队列的结构
typedef struct Queue
{
	QNode* _front;
	QNode* _tail;
}Queue;
// 初始化队列
void QueueInit(Queue* q);
// 队尾入队列
void QueuePush(Queue* q, QDataType data);
// 队头出队列
void QueuePop(Queue* q);
// 获取队列头部元素
QDataType QueueFront(Queue* q);
// 获取队列队尾元素
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q);
// 销毁队列
void QueueDestroy(Queue* q);

typedef int QDataType;
// 链式结构：表示队列
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;
// 队列的结构
typedef struct Queue
{
	QNode* _front;
	QNode* _tail;
}Queue;
// 初始化队列
void QueueInit(Queue* q)
{
	q->_front = NULL;
	q->_tail = NULL;
}
// 队尾入队列
void QueuePush(Queue* q, QDataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (node)
	{
		node->_data = data;
		node->_pNext = NULL;
	}
	if (q->_tail == NULL)
	{
		q->_front = q->_tail = node;
	}
	else
	{
		q->_tail->_pNext = node;
		q->_tail = node;
	}
}
// 队头出队列
void QueuePop(Queue* q)
{
	if (q->_front == NULL)
	{
		return;
	}
	else
	{
		QNode* temp = q->_front->_pNext;
		free(q->_front);
		q->_front = temp;
		if (temp == NULL)
		{
			q->_tail = NULL;
		}
	}

}
// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	return q->_front->_data;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q)
{
	if (q->_front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
	return q->_tail->_data;
}
// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
	int len = 0;
	QNode* head = q->_front;
	while (head)
	{
		head = head->_pNext;
		len++;
	}
	return len;
}
// 销毁队列
void QueueDestroy(Queue* q)
{
	int rel = QueueEmpty(q);
	if (rel)
	{

	}
	else
	{
		while (q->_front)
		{
			QNode *temp = q->_front->_pNext;
			free(q->_front);
			q->_front = temp;
		}
	}
}
typedef struct {
	Queue List1;
	Queue List2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack*st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&(st->List1));
	QueueInit(&(st->List2));
	return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->List1))
	{
		QueuePush(&obj->List1, x);
	}
	else
	{
		QueuePush(&obj->List2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue* Empty = &obj->List1;
	Queue* NonEmpty = &obj->List2;
	if (!QueueEmpty(&obj->List1))
	{
		Empty = &obj->List2;
		NonEmpty = &obj->List1;
	}
	int Top = 0;
	while (QueueSize(NonEmpty)>1)
	{
		Top = QueueFront(NonEmpty);
		QueuePush(Empty, Top);
		QueuePop(NonEmpty);
	}
	Top = QueueFront(NonEmpty);
	QueuePop(NonEmpty);
	return Top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->List1))
	{
		return QueueBack(&obj->List1);
	}
	else
	{
		return QueueBack(&obj->List2);
	}
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	if (QueueEmpty(&obj->List1) && QueueEmpty(&obj->List2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->List1);
	QueueDestroy(&obj->List2);
	free(obj);
}

/**
* Your MyStack struct will be instantiated and called as such:
* MyStack* obj = myStackCreate();
* myStackPush(obj, x);

* int param_2 = myStackPop(obj);

* int param_3 = myStackTop(obj);

* bool param_4 = myStackEmpty(obj);

* myStackFree(obj);
*/