#include"QList.h"
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
		printf("空队列！\n");
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
		temp = NULL;
	}

}
// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	if (q->_front == NULL)
	{
		printf("空队列！\n");
		return 0;
	}
	else
	{
		printf("Front:%d\n", q->_front->_data);
		return q->_front->_data;
	}

}
// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
	if (q->_tail == NULL)
	{
		printf("空队列！\n");
		return 0;
	}
	else
	{
		printf("Tail:%d\n", q->_tail->_data);
		return q->_tail->_data;
	}

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
	printf("%d\n", len);
	return len;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q)
{
	if (q->_front == NULL)
	{
		printf("空队列！\n");
		return 1;
	}
	else
	{
		printf("非空队列！\n");
		return 0;
	}
}
// 销毁队列
void QueueDestroy(Queue* q)
{
	int rel=QueueEmpty(q);
	if (rel)
	{
		printf("无需销毁！\n");
	}
	else
	{
		while (q->_front)
		{
			QNode *temp = q->_front->_pNext;
			free(q->_front);
			q->_front = temp;
		}
		printf("销毁成功！\n");
	}
}