#include"Stack.h"
// ��ʼ��ջ
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
		printf("�Ѿ���ʼ����\n");
		return ps;
	}
}
// ��ջ
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_top < ps->_capacity)
	{	
		ps->_a[ps->_top] = data;
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
				ps->_a[ps->_top] = data;
				ps->_top++;
			}
		}
		printf("��ǰ���������������У�\n");
		Sleep(2000);
		printf("���ݳɹ���\n");
	}
}
// ��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		printf("��ջ��\n");
		return;
	}
	else
	{
		ps->_top--;
	}
}
// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	printf("StackTop:%c\n", ps->_a[ps->_top-1]);
	return ps->_a[ps->_top-1];
}
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	int size = ps->_top;
	printf("%d\n", size);
	return size;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top)
	{
		printf("�ǿ�ջ��\n");
	}
	else
	{
		printf("��ջ��\n");
	}
	return !(ps->_top);
}
// ����ջ
void StackDestroy(Stack* ps)
{
	int rel=StackEmpty(ps);
	if (rel)
	{
		printf("��ջ��\n");
	}
	else
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_top = 0;
		printf("���ٳɹ���\n");
	}
	free(ps);
	ps = NULL;
}