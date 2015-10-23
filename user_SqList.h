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
void InitList_Sq(SqList &L)//构造一个空的线性表L
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!L.elem) 
		exit(-2);//空间分配失败
	L.length = 0;//空表长度为0
	L.listsize = LIST_INIT_SIZE;//初始储存容量
}
void DestroyList_Sq(SqList &L)//销毁线性表L
{
	free(L.elem);//释放L
	L.elem = NULL;//指针置零
}
void ClearList_Sq(SqList &L)
{

}
