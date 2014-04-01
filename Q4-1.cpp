/**********************************************
题目描述：
判断一棵二叉树是否平衡，这里平衡的意思是：
该树种任意两个叶子节点到根节点的距离之差不大于1
Date:2014-04-01
***********************************************/
#include<stdio.h>
#include<stdlib.h>
#define MAX 20  //保存叶子节点深度的数组的最大值
int count = 0;   //全局变量，保存叶子节点的个数
int Dep[MAX];   //保存叶子节点深度的数组
typedef struct BTNode
{
	char data;
	struct BTNode *pLchild;
	struct BTNode *pRchild;
}BTNode, *BTree;

BTree create_tree();
void getDepth(BTree,int);
bool weatherBalance(BTree);

int main()
{
	BTree pTree = create_tree();
	getDepth(pTree,0);
	if(weatherBalance(pTree))
		printf("Balanced\n");
	else
		printf("Not Balanced\n");
	
	return 0;
}

BTree create_tree()
{
	BTree pA = (BTree)malloc(sizeof(BTNode));
	BTree pB = (BTree)malloc(sizeof(BTNode));
	BTree pD = (BTree)malloc(sizeof(BTNode));
	BTree pE = (BTree)malloc(sizeof(BTNode));
	BTree pC = (BTree)malloc(sizeof(BTNode));
	BTree pF = (BTree)malloc(sizeof(BTNode));


	pA->data = 'A';
	pB->data = 'B';
	pD->data = 'D';
	pE->data = 'E';
	pC->data = 'C';
	pF->data = 'F';
	
	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pD;
	pB->pRchild = pE;
	pD->pLchild = pF;
	pD->pRchild = NULL;
	pE->pLchild = pE->pRchild = NULL;
	pC->pLchild = pC->pRchild = NULL;
	pF->pLchild = pF->pRchild = NULL;	
	
	return pA;
}


/*
中序递归遍历求叶子节点的深度
*/
void getDepth(BTree pTree,int depth)
{
	if(pTree)
	{
		if(pTree->pLchild)
			getDepth(pTree->pLchild,depth+1);

		if(!pTree->pLchild && !pTree->pRchild)
			Dep[count++] = depth;

		if(pTree->pRchild)
			getDepth(pTree->pRchild,depth+1);	
	}
}

/*
根据数组保存的各叶子节点的深度值，判断该
*/
bool weatherBalance(BTree pTree)
{
	if(!pTree)
		return true;
	int max = Dep[0];
	int min = Dep[0];
	int i;
	for(i=0;i<count;i++)
	{
		if(max<Dep[i])
			max = Dep[i];
		if(min>Dep[i])
			min = Dep[i];
	}
	if(max-min>1)
		return false;
	else
		return true;
}