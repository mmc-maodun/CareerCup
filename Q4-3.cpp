#include<stdio.h>
#include<stdlib.h>
typedef struct BTNode
{
	int data;
	struct BTNode *pLchild;
	struct BTNode *pRchild;
}BTNode, *BTree;

/*
根据给定的递增数组递归创建高度最小的二叉树，
因为要修改指向根节点的指针的指向，因此要传入pTree的指针，即BTNode的二级指针
*/
void createBTree(BTree *ppTree,int *A,int start,int end)
{
	if(start <= end)
	{
		int mid = (start + end)/2;
		*ppTree = (BTree)malloc(sizeof(BTNode));
		if(*ppTree == NULL)
		{
			printf("malloc faild");
			exit(EXIT_FAILURE);
		}
		(*ppTree)->data = A[mid];
		(*ppTree)->pLchild = NULL;
		(*ppTree)->pRchild = NULL;
		createBTree(&(*ppTree)->pLchild,A,start,mid-1);
		createBTree(&(*ppTree)->pRchild,A,mid+1,end);
	}
}

/*
返回两个整数的最大值
*/
int max(int a,int b)
{
	return a>b?a:b;
}

/*
求二叉树的深度
*/
int height(BTree pTree)
{
	if(pTree == NULL)
		return 0;
	else
		return max(height(pTree->pLchild),height(pTree->pRchild)) + 1;
}

/*
中序遍历的递归实现
*/
void in_traverse(BTree pTree)
{
	if(pTree)
	{
		if(pTree->pLchild)
			in_traverse(pTree->pLchild);
		printf("%d ",pTree->data);
		if(pTree->pRchild)
			in_traverse(pTree->pRchild);	
	}
}

int main()
{
	int A[] = {0,1,2,3,4,5,6,7};
	int len = 8;
	BTree pTree;
	createBTree(&pTree,A,0,len-1);
	printf("the height of this tree is %d\n",height(pTree));
	printf("中序遍历后的结果为：\n");
	in_traverse(pTree);
	printf("\n");
	return 0;
}