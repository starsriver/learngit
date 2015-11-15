#include<stdlib.h>
#include<stdio.h>
int StrLength(char s[])//求串长 
{
	int i;
	for(i=0;;i++)
	{
		if(s[i]=='\0')
			break;
	}
	return i;
}

void StrAssign(char s1[],char s2[])//串赋值 
{
	int i;
	if(StrLength(s1)<StrLength(s2))
	{
		char *p = s1;
		if(!(p=(char*)malloc((StrLength(s2)+1)*sizeof(char))))
			exit(0);
		p = NULL;
	}
	for(i=0;i<=StrLength(s2);i++)
		s1[i]=s2[i];
	return;
} 

void StrConcat(char s1[],char s2[],char s[])//连接操作1 
{
	int i,j;
	if(StrLength(s)<(StrLength(s1)+StrLength(s2)))
	{
		char *p = s;
		if(!(p=(char*)malloc((StrLength(s1)+StrLength(s2)+1)*sizeof(char))))
			exit(0);
		p = NULL;
	}
	for(i=0;i<StrLength(s1);i++)
	{
		s[i]=s1[i];
	}
	for(j=0;j<=StrLength(s2);i++,j++)
	{
		s[i]=s2[j];
	}
	return;
}
void StrConcat(char s1[],char s2[])//连接操作2 
{
	char temp[StrLength(s1)+1];
	int i,j;
	for(i=0;i<=StrLength(s1);i++)
		temp[i]=s1[i];
	if(StrLength(s1)<StrLength(s2))
	{
		char *p = s1;
		if(!(p=(char*)malloc((StrLength(temp)+StrLength(s2)+1)*sizeof(char))))
			exit(0);
		p = NULL;
	}
	for(i=0;i<StrLength(temp);i++)
		s1[i]=temp[i];
	for(j=0;j<StrLength(s2);i++,j++)
		s1[i]=s2[j];
	return;
}
void SubStr(char s[],int i,int len,char r[])//求子串 
{
	int j; 
	if(StrLength(s)==0||i<1||i>StrLength(s)||len<0||len>(StrLength(s)-i+1))
		return;
	if(StrLength(r)<len)
	{
		char *p = r;
		if(!(p=(char*)malloc((len+1)*sizeof(char))))
			exit(0);
		p = NULL;
	}
	i--;
	for(j=0;j<len;j++,i++)
		r[j]=s[i];
	r[j] = '\0';
	return;
} 
int StrCmp(char s1[],char s2[])//串比较 
{
	int i;
	if(StrLength(s1)<StrLength(s2))
		return -1;
	else if(StrLength(s1)>StrLength(s2))
		return 1;
	else
	{
		for(i=0;i<StrLength(s1);i++)
		{
			if(s1[i]!=s2[i])
				break;
		}
		if(i==StrLength(s1))
			return 0;
		else 
			return -11111;
	}
}
int StrIndex(char s[],char t[])//子串定位 
{
	if(StrLength(s)<1||StrLength(t)<1)
		return 0;
	int n=StrLength(t);
	int i;
	char temp[]=" ";
	for(i=1;i<=StrLength(s);i++)
	{
		SubStr(s,i,n,temp);
		if(StrCmp(t,temp)==0)
			return i;
	}
	return -1;
} 
void StrInsert(char s[],int i,char t[])//串插入 
{
	if(StrLength(s)<1||i>StrLength(s)||StrLength(t)<1)
		return;
	char temp[StrLength(s)+1];
	int j;
	for(j=0;j<=StrLength(s);j++)
		temp[j]=s[j];
	char *p = s;
	if(!(p=(char*)malloc((StrLength(temp)+StrLength(t)+1)*sizeof(char))))
		exit(0);
	p = NULL;
	char temp1[i]=" ";
	char temp2[StrLength(temp)-i+1]=" ";
	SubStr(temp,1,i,temp1);
	SubStr(temp,i+1,StrLength(temp)-i,temp2);
	//	printf("--%s--",temp2);
	StrConcat(temp1,t,s);
	StrConcat(s,temp2);
	s[j-1+StrLength(t)]='\0';
	return;
} 

void StrDelete(char s[],int i,int len)//串删除 
{
	if(i<1||i>StrLength(s)||len<0||len>StrLength(s)-i+1||StrLength(s)<1)
		return;
	char temp1[]=" ";
	char temp2[]=" ";
	SubStr(s,1,i-1,temp1);
	SubStr(s,i+len,StrLength(s)+1-i-len,temp2);
	StrConcat(temp1,temp2,s);
	return;
} 
void StrRep(char s[],char t[],char r[])//串替换 
{
	if(StrLength(s)<1||StrLength(t)<1||StrLength(r)<1)
		return;
	int n;
	while(StrIndex(s,t)!=-1)
	{
		n=StrIndex(s,t);
		StrDelete(s,n,StrLength(t));
		StrInsert(s,n-1,r);
	}
	return;
}
