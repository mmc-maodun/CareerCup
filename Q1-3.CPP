/***********************************************
题目描述：
移除字符串中重复的字符，如abcadc移除后变为abcd，
可以额外定义一两个变量，但不允许额外开辟一个数组,
并为该算法写测试用例
Date:2014-03-16
************************************************/
#define MAX 26
#include<stdio.h>
#include<string.h>

void remove(char *str)
{
	int len = strlen(str);
	if(len < 2)
		return ;
	int i,j;
	int p = 0;	//p的初值与i相等，均为0
	for(i=0;i<len;i++)
	{
		//如果该字符不为'\0'，则与下面的字符比较
		if(str[i])
		{
			//如果当前字符不为'\0'时，p一直与i相等，
			//如果当前字符为'\0'，则p会小于i，从而用后面的字符来填充前面'\0'字符的位置
			str[p++] = str[i];
			//每个字符与其后面的字符比较，
			//如果出现重复字符，则将后面的重复字符用'\0'代替
			for(j=i+1;j<len;j++)
				if(str[i] == str[j])
					str[j] = '\0';
		}
	}
	str[p] = '\0';
}

/*
开辟长为26的bool数组的方法
*/
void remove1(char *str)
{
	int len = strlen(str);
	if(len < 2)
		return ;
	int i;
	int p = 0;
	bool A[MAX];
	memset(A,0,sizeof(A));
	for(i=0;i<len;i++)
	{
		int index = str[i] - 'a';
		if(!A[index])
		{
			str[p++] = str[i];
			A[index] = true;
		}
	}
	str[p] = '\0';
}

int main()
{
	char str1[] = "abcdfbdk";	//随机字符串
	char str2[] = "abababab";	//重复字符交替出现
	char str3[] = "aaaabbbb";	//重复字符连续出现
	char str4[] = "aaaaaaaa";   //全是重复字符
	char str5[] = "abcdefgh";   //没有重复字符
	char str6[] = "";			//空字符串

	remove1(str1);
	remove1(str2);
	remove1(str3);
	remove1(str4);
	remove1(str5);
	remove1(str6);

	puts(str1);
	puts(str2);
	puts(str3);
	puts(str4);
	puts(str5);
	puts(str6);

	return 0;
}