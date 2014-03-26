/****************************************************
题目描述：
实现一个栈的push、pop操作和min操作（返回栈中最小值），
要求push，pop和min函数的时间复杂度都为O(1)
Date:2014-03-26
*****************************************************/

/*
本程序采用数组模拟栈
*/
typedef int ElemType;
#define MAX 100  //栈的深度
#include<stdio.h>

/*
在栈顶索引指针为top时，向栈A中压入数据data
*/
bool push(int *A,int &top,ElemType data)
{
	if(top>=MAX-1 || top<-1)
		return false;

	A[++top] = data;
	return true;
}

/*
在栈顶索引指针为top时，出栈
*/
bool pop(int &top)
{
	if(top<0)
		return false;

	top--;
	return true;
}

/*
栈顶当前索引指针为top，Min数组最大深度也为MAX，
且Min的有效元素数与栈A中的元素个数相同，
它的对应位置用来保存栈A对应位置到栈底这一部分元素中的最小值
*/
void minAll(int *A,int *Min,int top)
{
	if(top>MAX-1)
		return ;
	Min[0] = A[0];
	int i;
	for(i=1;i<=top;i++)
	{
		if(Min[i-1] > A[i])
			Min[i] = A[i];
		else
			Min[i] = Min[i-1];
	}
}

/*
返回栈顶为top时栈中元素的最小值
*/
int min(int *Min,int top)
{
	return Min[top];
}

int main()
{
	int A[MAX];
	int top = -1;
	push(A,top,4);
	push(A,top,7);
	push(A,top,2);
	push(A,top,6);
	push(A,top,3);
	push(A,top,8);
	push(A,top,5);
	push(A,top,1);

	int Min[MAX];
	minAll(A,Min,7);
	int i;
	for(i=0;i<=top;i++)
		printf("%d ",Min[i]);
	printf("\n");
	/*
	int min7 = min(Min,7);
	printf("%d\n",min7);
	pop(top);
	int min6 = min(Min,6);
	printf("%d\n",min6);
	*/
	return 0;
}
