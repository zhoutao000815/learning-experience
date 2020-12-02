#ifndef _CONTACT_H_
#define _CONTACT_H_
//实现一个通讯录；
//通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
//提供方法：
//添加联系人信息
//删除指定联系人信息
//查找指定联系人信息
//修改指定联系人信息
//显示所有联系人信息
//清空所有联系人
//以名字排序所有联系人
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
