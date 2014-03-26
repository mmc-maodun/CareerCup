/*********************************
��Ŀ������
��һ���л��ĵ������л���ʼ���Ľڵ�
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
����һ���ٶ�Ϊ2�Ŀ�ָ�룬һ���ٶ�Ϊ1����ָ�룬
����������л����򷵻�����ָ�������Ľڵ㣬
���û��������û�л����򷵻�NULL��
*/
pNode WetherCircle(pNode pHead)
{
	if(!pHead)
		return NULL;
	pNode p1 = pHead;
	pNode p2 = pHead;
	//ֱ�������������˳�ѭ��
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
���㻷�еĽڵ����
*/
int CircleLen(pNode pHead)
{
	pNode p = WetherCircle(pHead);
	if(!p)
		return 0;
	int count = 1;
	//�̶�һ��ָ�룬��һ��ָ���ڻ����ƶ�
	pNode p1 = p->next;
	while(p1 != p)
	{
		count++;
		p1 = p1->next;
	}
	return count;
}

/*
�󻷿�ʼ�Ľڵ�
*/
pNode CircleBegin(pNode pHead)
{
	int len  = CircleLen(pHead);
	if(len < 1)
		return NULL;
	pNode p1 = pHead;
	pNode p2 = pHead;
	int i;
	//��һ��ָ�����ƶ�len���ڵ�
	for(i=0;i<len;i++)
		p1 = p1->next;
	//����һ���ƶ�
	while(p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

/*
����������ʾ�Ĵ����ĵ�����
1->2->3->4->5->6->7->4
��������ڽڵ�Ϊdate��Ϊ4�Ľڵ�
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
	//�����һ�ڵ��nextָ����ĸ��ڵ㣬�γɻ�
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