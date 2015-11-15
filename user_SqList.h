#pragma once
#include<stdlib.h>
#define LIST_INIT_SIZE 100 //线性表储存空间初始分配量
#define LISTINCREMENT 10   //线性表储存空间分配增量
#define ElemType int       //线性表基础类型

typedef struct {     //线性表结构体
	ElemType *elem; //储存空间基地址
	int length;     //当前长度
	int listsize;   //当前分分配的储存容量
}SqList;

int InitList_Sq(SqList &L)//构造一个空的线性表L
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!L.elem) 
		exit(-2);//空间分配失败
	L.length = 0;//空表长度为0
	L.listsize = LIST_INIT_SIZE;//初始储存容量
	return 1;
}

int DestroyList_Sq(SqList &L)//销毁线性表L
{
	free(L.elem);//释放L
	L.elem = NULL;//指针置零
	return 1;
}

int ClearList_Sq(SqList &L)//清空线性表表L
{
	if (L.elem == NULL)//表L不存在
		return 0;
	L.length = 0;//线性表长度归零
	return 1;
}

int ListEmpty_Sq(SqList L)//判断表是否为空表
{
	if (L.elem == NULL)//表L不存在
		return 0;
	if (L.length)//表是否空
		return 0;//表非空，返回flase
	else
		return 1;//表空，返回true
}