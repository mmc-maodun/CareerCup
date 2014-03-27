/****************************************************
题目描述：
用一个数组实现三个栈
Date:2014-03-27
*****************************************************/
typedef int ElemType;
#define MAX 100  //三个栈的总深度
#include<stdio.h>

typedef struct node
{
	ElemType data;
	int next;	//指向该栈的下一个元素,如果没有下一个元素，则设next为-1
}node;


/*
在该栈顶的索引指针为top时，向栈A中压入数据data
count用来记录最上面的元素所在栈的栈顶位置
*/
bool push(node *A,int &count,int &top,ElemType data)
{
	if(count>=MAX-1 || count<-1 || top>count || top<-1)
		return false;

	count++;
	A[count].data = data;
	A[count].next = top;
	top = count; 
	return true;
}

/*
在该栈顶索引指针为top时，出栈
count用来记录最上面的元素所在栈的栈顶位置
*/
bool pop(node *A,int &count,int &top)
{
	if(top<0 || top>count)
		return false;
	if(top == count)
		count--;
	A[top].data = -10;  //这里为了便于观察pop后的情况，将出栈后的位置的元素设定为-10
	top = A[top].next;
	return true;
}


int main()
{
	int top1 = -1;
	int top2 = -1;
	int top3 = -1;
	int count = -1;
	node A[MAX];
	push(A,count,top1,1);
	push(A,count,top2,2);
	push(A,count,top3,3);
	push(A,count,top1,4);
	push(A,count,top3,5);
	push(A,count,top3,6);
	push(A,count,top2,7);
	push(A,count,top1,8);
	int i;
	printf("After pushed:\n");
	for(i=0;i<8;i++)
		printf("A[%d].data = %d,A[%d].next = %d\n",i,A[i].data,i,A[i].next);

	pop(A,count,top3);
	pop(A,count,top2);
	pop(A,count,top1);
	printf("After popd:\n");
	for(i=0;i<8;i++)
		printf("A[%d].data = %d,A[%d].next = %d\n",i,A[i].data,i,A[i].next);
	return 0;
}
