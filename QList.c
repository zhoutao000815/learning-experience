#include"QList.h"
// ��ʼ������
void QueueInit(Queue* q)
{
	q->_front = NULL;
	q->_tail = NULL;
}
// ��β�����
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
// ��ͷ������
void QueuePop(Queue* q)
{
	if (q->_front == NULL)
	{
		printf("�ն��У�\n");
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
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	if (q->_front == NULL)
	{
		printf("�ն��У�\n");
		return 0;
	}
	else
	{
		printf("Front:%d\n", q->_front->_data);
		return q->_front->_data;
	}

}
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	if (q->_tail == NULL)
	{
		printf("�ն��У�\n");
		return 0;
	}
	else
	{
		printf("Tail:%d\n", q->_tail->_data);
		return q->_tail->_data;
	}

}
// ��ȡ��������ЧԪ�ظ���
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q)
{
	if (q->_front == NULL)
	{
		printf("�ն��У�\n");
		return 1;
	}
	else
	{
		printf("�ǿն��У�\n");
		return 0;
	}
}
// ���ٶ���
void QueueDestroy(Queue* q)
{
	int rel=QueueEmpty(q);
	if (rel)
	{
		printf("�������٣�\n");
	}
	else
	{
		while (q->_front)
		{
			QNode *temp = q->_front->_pNext;
			free(q->_front);
			q->_front = temp;
		}
		printf("���ٳɹ���\n");
	}
}