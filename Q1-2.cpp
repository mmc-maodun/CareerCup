/****************************************************************
题目描述：
编写代码，实现翻转一个C风格的字符串的功能。
C风格的意思是"abcd"需要用5个字符来表示，最后一个字符为空字符'\0'。
Date:2014-03-15
*****************************************************************/
#include<stdio.h>
/*
交换两字符
*/
void swap(char *a,char *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

/*
反转字符串
*/
void reverse(char *str)
{
	if(!str)
		return;
	char *pLeft = str;
	char *pRight = str;
	while(*pRight != '\0')
		pRight++;
	pRight--;
	while(pLeft < pRight)
		swap(pLeft++,pRight--);
}

int main()
{
	//注意这里不能定义为 char *str = "thanks"，
	//这样定义的是字符串常量，不可修改。
	char str[] = "thanks";
	reverse(str);
	puts(str);
	return 0;
}
