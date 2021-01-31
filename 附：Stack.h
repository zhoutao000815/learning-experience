#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>
#pragma warning (disable:4996)
// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // ջ�� �����±꣬ʹ���������һ��Ԫ��ʱ��Ӧ�ü�һ��    //Ҳ�����ö�Ӧ��ָʾ����
	int _capacity; // ����
}Stack;
// ��ʼ��ջ
Stack* StackInit();
// ��ջ
void StackPush(Stack* ps, STDataType data);
// ��ջ
void StackPop(Stack* ps);
// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps);
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps);
// ����ջ
void StackDestroy(Stack* ps);