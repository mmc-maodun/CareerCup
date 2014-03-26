/*********************************
题目描述：
求一个有环的单链表中环开始处的节点
Date:2014-03-26
**********************************/
typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node,*pNode;

#include<stdio.h>
#include<stdlib.h>

/*
定义一个速度为2的快指针，一个速度为1的慢指针，
如果链表中有环，则返回两个指针相遇的节点，
如果没有链表中没有环，则返回NULL。
*/
pNode WetherCircle(pNode pHead)
{
	if(!pHead)
		return NULL;
	pNode p1 = pHead;
	pNode p2 = pHead;
	//直到二者相遇，退出循环
	while((p1 && p2 && p1!=p2) || (p1==p2 && p1==pHead && p2==pHead))
	{
		p1 = p1->next;
		p2 = p2->next->next;
	}
	if(p1 == p2)
		return p1;
	else
		return NULL;
}

/*
计算环中的节点个数
*/
int CircleLen(pNode pHead)
{
	pNode p = WetherCircle(pHead);
	if(!p)
		return 0;
	int count = 1;
	//固定一个指针，另一个指针在环中移动
	pNode p1 = p->next;
	while(p1 != p)
	{
		count++;
		p1 = p1->next;
	}
	return count;
}

/*
求环开始的节点
*/
pNode CircleBegin(pNode pHead)
{
	int len  = CircleLen(pHead);
	if(len < 1)
		return NULL;
	pNode p1 = pHead;
	pNode p2 = pHead;
	int i;
	//第一个指针先移动len个节点
	for(i=0;i<len;i++)
		p1 = p1->next;
	//而后一起移动
	while(p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

/*
建立如下所示的带环的单链表
1->2->3->4->5->6->7->4
即环的入口节点为date域为4的节点
*/
pNode create_CircleList()
{
	pNode pHead = (pNode)malloc(sizeof(Node));
	if(!pHead)
	{
		printf("malloc faild!\n");
		exit(-1);
	}
	pHead->data = 1;

	pNode r = pHead;
	int i;
	for(i=0;i<6;i++)
	{
		pNode pNew = (pNode)malloc(sizeof(Node));
		if(!pNew)
		{
			printf("malloc faild!\n");
			exit(-1);
		}
		pNew->data = i + 2;
		r->next = pNew;
		r = pNew;
	}
	//将最后一节点的next指向第四个节点，形成环
	r->next = pHead->next->next->next;
	return pHead;
}

int main()
{
	pNode pHead = create_CircleList();
	pNode p = CircleBegin(pHead);
	printf("The date in the beginNode of the Circle is:%d\n",p->data);
	return 0;
}
