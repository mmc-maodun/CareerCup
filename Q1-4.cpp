/****************************
题目描述：
判断两个字符串是否互为变位词
Date:2014-03-17
****************************/
#define MAX 26
#include<iostream>
#include<cstring>
using namespace std;

bool anagram(string s1,string s2)
{
	int len1 = s1.length();
	int len2 = s2.length();
	if(len1 != len2)
		return false;

	int i;
	int A[MAX];
	memset(A,0,sizeof(A));
	for(i=0;i<len1;i++)
	{
	
		int index = s1[i] - 'a';
		A[index]++;
	}
	for(i=0;i<len1;i++)
	{
		int index = s2[i] - 'a';
		A[index]--;
	}

	for(i=0;i<MAX;i++)
		if(A[i] > 0)
			return false;
	return true;
}

int main()
{
	string s1 = "abbfcad";
	string s2 = "facbdab";
	if(anagram(s1,s2))
		cout<<"s1 and s2 are anagrams"<<endl;
	else
		cout<<"s1 and s2 are not anagrams"<<endl;

	string s3 = "abbfcad";
	string s4 = "facbkab";
	if(anagram(s3,s4))
		cout<<"s3 and s4 are anagrams"<<endl;
	else
		cout<<"s3 and s4 are not anagrams"<<endl;

	return 0;
}
