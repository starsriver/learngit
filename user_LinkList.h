#pragma once
#include<stdlib.h>
#include<stdio.h>
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
int ListLength(LinkList &L)//返回单链表长度
{
	LinkList p = L;
	int n = 0;
	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}
int ListInsert_L(LinkList &L,int i,ElemType e)//在单链表L的第i个元素前插入e
{
	LinkList p=L;
	int j=0;
	if (i <= ListLength(L))
	{
		while (j<i - 1)
		{
			p = p->next;
			j++;
		}
	}
	else
	{
		while (p->next != NULL)
			p = p->next;
	}
	LinkList s;
	s=(LinkList)malloc(sizeof(Node));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return 1;
}
int ListDelete_L(LinkList &L, int i)//删除单链表中位置i处的元素
{
	if (L->next == NULL || i>ListLength(L))
		return 0;
	LinkList p = L;
	int j = 0;
	while (j<i - 1)
	{
		p = p->next;
		j++;
	}
	LinkList q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}
int Printf_L(LinkList &L)//顺次打印整个单链表
{
	if(L->next==NULL)
		return 0;
	LinkList p=L->next;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
	return 1;
}
