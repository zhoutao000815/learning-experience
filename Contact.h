#ifndef _CONTACT_H_
#define _CONTACT_H_
//ʵ��һ��ͨѶ¼��
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ�������������Ա����䡢�绰��סַ
//�ṩ������
//�����ϵ����Ϣ
//ɾ��ָ����ϵ����Ϣ
//����ָ����ϵ����Ϣ
//�޸�ָ����ϵ����Ϣ
//��ʾ������ϵ����Ϣ
//���������ϵ��
//����������������ϵ��
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#pragma warning (disable:4996)

void menu();
void Add();
void Del();
void Search();
void Revise();
void Show();
void Clear();
void Qsort();
struct Person_s
{
	char name[20];
	char sex[10];
	int age[1];
	char tel[20];
	char adress[20];
};

	




//typedef struct person
//{
//	int volume;
//	int size;
//	struct Contact person_s[0];
//
//};




#endif
