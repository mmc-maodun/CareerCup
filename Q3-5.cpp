/*********************************************************
题目描述：
将栈按照升序排列，升序排列的意思是元素从栈底到栈顶依次增大
Date:2014-03-29
**********************************************************/

/**************************************************************************************************************
以下为操作栈的算法，该栈为动态栈。
在该栈中，pTop指向的节点中存放该栈的栈顶数据
pBottom指向的节点的上一个节点存放该栈的栈底数据，pBottom指向的节点中不存放有效数据，
这样做的目的是为了在进行入栈和出栈时方便对栈的操作，而用考虑特殊情况
**************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE,*PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;

PSTACK create_stack();
void push_stack(PSTACK,int);
void traverse_stack(PSTACK);
bool pop_stack(PSTACK,int *);
bool is_empty(PSTACK);
void clear_stack(PSTACK);
PSTACK sort_stack(PSTACK);

int main()
{	

	//创建一个空的栈，pS指针指向该栈
	PSTACK pS = create_stack();
	push_stack(pS,4);
	push_stack(pS,3);
	push_stack(pS,7);
	push_stack(pS,1);
	push_stack(pS,5);
	push_stack(pS,9);
	push_stack(pS,2);
	push_stack(pS,6);

	printf("Befote Sorted:\n");
	traverse_stack(pS);
	PSTACK pS1 = sort_stack(pS);
	printf("After Sorted:\n");
	traverse_stack(pS1);
	return 0;
}

/*
创建一个空栈,并返回指向该栈的指针
*/
PSTACK create_stack()
{
	PSTACK pS = (PSTACK)malloc(sizeof(STACK));
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if(NULL==pS || NULL==pS->pTop)
	{
	   printf("malloc failed");
	   exit(-1);
	}	
	else
	{
	   pS->pBottom = pS->pTop;
	   pS->pBottom->pNext = NULL;
	}
	
	return pS;
}

/*
判断该栈是否为空
*/
bool is_empty(PSTACK pS)
{
	if(pS->pTop == pS->pBottom)
	   return true;
    else
	   return false;
}

/*
向pS指针指向的栈中压入数据val
*/
void push_stack(PSTACK pS,int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL==pNew)
	{
	   printf("malloc failed");
	   exit(-1);
	}	
	else
	{
	   pNew->data = val;
	   pNew->pNext = pS->pTop;
	   pS->pTop = pNew;
	}	
	return ;
}

/*
从栈中推出数据，并将推出的数据保存在pData指针所指向的位置
*/
bool pop_stack(PSTACK pS,int *pData)
{
	if(is_empty(pS))
	   return false;
	else
	{
	   PNODE p = pS->pTop;
	   *pData = p->data;
	   pS->pTop = p->pNext;
	   free(p);
	   p = NULL;
	   return true;
	}
}

/*
遍历栈，并自栈顶向栈底输出栈中的数据
*/
void traverse_stack(PSTACK pS)
{
	PNODE pCurrent = pS->pTop; 
	while(pCurrent != pS->pBottom)
       {
	   printf("%d ",pCurrent->data);
	   pCurrent = pCurrent->pNext;
	}
	printf("\n");
	return ;
}

/*
清空栈，即将其还原为空栈
*/
void clear_stack(PSTACK pS)
{
	if(is_empty(pS))
	   return ;
	else
	{
	   PNODE p = pS->pTop;
	   PNODE r = NULL;
	   while(p != pS->pBottom)
	   {
			r = p->pNext;
			free(p);
			p = r;
	   }
	   pS->pTop = pS->pBottom;
   	}
}

/*
对栈进行模拟插入排序操作
*/
PSTACK sort_stack(PSTACK pS)
{
	PSTACK pS1 = create_stack();

	while(!is_empty(pS))
	{
		int pop_pSData;
		pop_stack(pS,&pop_pSData);
		while(!is_empty(pS1) && pop_pSData<pS1->pTop->data)
		{
			int pop_pS1Data;
			pop_stack(pS1,&pop_pS1Data);
			push_stack(pS,pop_pS1Data);
		}
		push_stack(pS1,pop_pSData);
	}
	return pS1;
}
