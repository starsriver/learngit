#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100  //栈储存空间初始分配量
#define STACKINCREMENT 10    //栈储存空间分配增量
#define ElemType char         //栈元素类型
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stacksize;         //栈当前已分配的储存空间
}SqStack;

int InitStack(SqStack &S)    //构造一个空栈S
{
	S.base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!S.base)
		exit(-2);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return 1;
}

int DestroyStack(SqStack &S) //销毁栈S
{
	free(S.base);
	S.base=NULL;
	S.top=NULL;
	S.stacksize=0;
	return 1;
}

int ClearStack(SqStack &S)//清空栈S 
{
    S.top=S.base;
    return 1;
}

int StackLength(SqStack &S)//返回栈S的元素个数 
{
    return S.top-S.base;
}

int StackEmpty(SqStack &S)//判断S是否为空栈 
{
    if(S.base==S.top)
        return 1;
    else
        return 0;
}

int GetTop(SqStack &S,ElemType &e)//取栈S的栈顶元素 
{
    if(StackEmpty(S))
        return 0;
    e=*(S.top-1);
    return 1;
}

int Push(SqStack &S,ElemType e)//入栈 
{
    if(S.top-S.base>=S.stacksize)
    {
        S.base=(ElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(ElemType));
        if(!S.base)
            exit(-2);
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top=e;
    S.top++;
    return 1;
}

int Pop(SqStack &S,ElemType &e)//出栈 
{
    if(S.top==S.base)
        return 0;
    S.top--;
    e=*S.top;
    return 1;
}
int Pop(SqStack &S)//出栈 
{
    if(S.top==S.base)
        return 0;
    S.top--;
    return 1;
}

