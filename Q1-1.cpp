/**********************************************************
题目描述：
判断一个字符串中是否没有重复的字符，只能使用基本的数据结构
Date：2014-03-15
**********************************************************/
#define MAX 26
#include<iostream>
#include<cstring>
using namespace std;

/*
判断是否有重复字符
*/
bool unqString(string s)
{
	unsigned int i;
	unsigned int len = s.length();
	unsigned int arr[MAX];
	memset(arr,0,sizeof(arr));
	//依次对字符对应的数组位置上的值进行判断
	//0表示还没有出现该字符,1表示出现了该字符
	//如果已经为1了，再次出现该字符，则说明出现了重复
	for(i=0;i<len;i++)
	{
		unsigned int index = s[i] - 'a';
		if(arr[index] == 0)
			arr[index] = 1;
		else
			return false;
	}
	return true;
}

/*
采用位操作的方法判断是否有重复字符
*/
bool unqString2(string s)
{
	unsigned int i;
	unsigned int len = s.length();
	unsigned int arr[8];
	memset(arr,0,sizeof(arr));
	for(i=0;i<len;i++)
	{
		int index = (int)s[i]/32;
		int shift = (int)s[i]%32;
		if(arr[index]&(1<<shift))
			return false;
		else
			arr[index] |= (1<<shift);
	}
	return true;
}

int main()
{
	string s1 = "abcdef";
	string s2 = "advcgbdfrvst";
	if(unqString(s1))
		cout<<"s1->yes"<<endl;	
	else
		cout<<"s1->no"<<endl;
	if(unqString(s2))
		cout<<"s2->yes"<<endl;	
	else
		cout<<"s2->no"<<endl;
	return 0;
}
