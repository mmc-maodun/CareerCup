/**************************************************
题目描述：
用单链表表示一个正整数，每个结点代表其中的一位数字，
逆序排列，个位位于表头，最高位位于表尾，
将两个数相加并返回结果，结果也由链表表示。比如：
输入：(3 -> 1 -> 5)+(5 -> 9 -> 2)
输出：8 -> 0 -> 8
Date:2014-03-25
***************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE,*PNODE;

PNODE create_list();       
void traverse_list(PNODE);
bool is_empty(PNODE);     
int length_list(PNODE); 
void clear_list(PNODE);
PNODE addList(PNODE,PNODE);
void AddShortToLong(PNODE,PNODE);

int main()
{
	printf("Create the first list:\n");
	PNODE pHead1 = create_list();
	printf("List 1:\n");
	traverse_list(pHead1);

	fflush(stdin);	//刷新输入缓冲区
	printf("Create the second list:\n");
	PNODE pHead2 = create_list();
	printf("List 2:\n");
	traverse_list(pHead2);

	PNODE pHead = addList(pHead1,pHead2);
	printf("After added,the new List:\n");
	traverse_list(pHead);

	return 0;
}

/*
  创建一个链表,并返回头指针
*/
PNODE create_list()
{
	int val;
	PNODE pHead =(PNODE)malloc(sizeof(NODE));
	PNODE pCurrent = pHead;
	pCurrent->pNext = NULL;
	if(NULL == pHead)
	{
		printf("pHead malloc failed!");
		exit(-1);
	}
	printf("Input first data(q to quit):");
	while(scanf("%d",&val)==1)
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL == pNew)
		{
			printf("pNew malloc failed!");
			exit(-1);
		}
		pNew->data = val;
		pCurrent->pNext = pNew;
		pNew->pNext = NULL;
		pCurrent = pNew;
		printf("Input next data(q to quit):");
	}

	return pHead;	
}

/*
遍历链表
*/
void traverse_list(PNODE pHead)
{
	PNODE pCurrent = pHead->pNext;
	printf("now dataes in the list are:\n");
	while(pCurrent != NULL)
	{	
		printf("%d ",pCurrent->data);
		pCurrent = pCurrent->pNext;
	}
	printf("\n");
	return ;
}

/*
判断链表是否为空
*/
bool is_empty(PNODE pNode)
{
	if(NULL == pNode->pNext)
		return true;
	else 
		return false;
}

/*
求链表长度，即节点总数（不计入头节点）
*/
int length_list(PNODE pNode)
{
	int count = 0;
	PNODE pCurrent = pNode->pNext;
	while(pCurrent != NULL)
	{
		count++;
		pCurrent = pCurrent->pNext;		
	}

	return count;
}


/*
清空链表，即使链表只剩下头节点（头节点中没有数据）
*/
void clear_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	PNODE r = NULL;
	while(p != NULL)
	{
	   r = p->pNext;
	   free(p);
	   p = r;
	}
	pHead->pNext = NULL;
	return ;
}

/*
两个链表相加
*/
PNODE addList(PNODE pHead1,PNODE pHead2)
{
	if(!pHead1)
		return pHead2;
	if(!pHead2)
		return pHead1;
	
	int len1 = length_list(pHead1);
	int len2 = length_list(pHead2);
	if(len1 >= len2)
	{
		AddShortToLong(pHead1,pHead2);
		return pHead1;
	}
	else 
	{
		AddShortToLong(pHead2,pHead1);
		return pHead2;
	}
}
/*
第一个链表的长度大于或等于第二个链表的长度，
将第二个链表加到第一个链表上
*/
void AddShortToLong(PNODE pHeadLong,PNODE pHeadShort)
{
	PNODE p1 = pHeadLong->pNext;
	PNODE p2 = pHeadShort->pNext;

	while(p1 && p2)
		{
			p1->data = p1->data + p2->data;
			if(p1->data >= 10)
			{
				p1->data -= 10;
				if(p1->pNext)
				{
					p1->pNext->data++;
					if(p1->pNext->data >= 10)  //两链表长度不同，最后一位又有进位
					{
						p1->pNext->data -= 10;
						PNODE pNew = (PNODE)malloc(sizeof(NODE));
						if(!pNew)
						{
							printf("malloc failed\n");
							exit(-1);
						}
						pNew->pNext = NULL;
						pNew->data = 1;
						p1->pNext->pNext = pNew;
					}
				}
				else	//两链表长度相同，且组后一位有进位
				{
					PNODE pNew = (PNODE)malloc(sizeof(NODE));
					if(!pNew)
					{
						printf("malloc failed\n");
						exit(-1);
					}
					pNew->pNext = NULL;
					pNew->data = 1;
					p1->pNext = pNew;
				}
			}
			p1 = p1->pNext;
			p2 = p2->pNext;
		}
}