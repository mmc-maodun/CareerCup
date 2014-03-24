/****************************************************************************************
题目描述：
已知一个字符串，将其第k个位之前（从0开始计）的字符旋转至该字符串的尾部，求旋转后的字符串。
比如，对于字符串“abcdef”，将其第2个位置前的字符旋转至尾部，得到“cdefab”。
Date:2014-03-19
*****************************************************************************************/

#include<stdio.h>
#include<string.h>

/*
将字符串str的start和end位置之间的字符反转
*/
void reverseString(char *str,int start,int end)
{
	while(start < end)
	{
		str[start] = str[start] + str[end];
		str[end] = str[start] - str[end];
		str[start] = str[start] - str[end];
		start++;
		end--;
	}
}

/*
进行三次反转
*/
void rotate(char *str,int k)
{
	int len = strlen(str);
	if(k <= 0 || len <= k)
		return ;
	reverseString(str,0,k-1);
	reverseString(str,k,len-1);
	reverseString(str,0,len-1);
}

int main()
{
	char str1[] = "abcdef";
	char str2[] = "abcdefghket";
	rotate(str1,1);
	rotate(str2,4);
	puts(str1);
	puts(str2);
	return 0;
}
