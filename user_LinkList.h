#pragma once
#include<stdlib.h>
#define ElemType int       //单链表基础类型
typedef struct Node{
	ElemType data;
	struct Node *next;
}Node,*LinkList;
int InitList_L(LinkList &L)//初始化一个单链表
{
	L = (LinkList) malloc(sizeof(Node));
	if (!L)
		return -1;
	L->next = NULL;
	return 1;
}
int ListInsert_L(LinkList &L,int i,ElemType e)
{
	LinkList p=L;
	int j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
		return 0;
	s=(LinkList)malloc(sizeof(Node));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return 1;
}
void Printf_L(LinkList &L)
{
	if(L->next==NULL)
		return 0;
	LinkList p=L;
	while(p->next!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
    return;
}
