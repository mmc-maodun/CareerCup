#define M 5
#define MAX 3
typedef int ElemType;
typedef struct HashNode
{
	int *Arr;
}HashNode,*pHashTable;
int top = -1;	//全局变量，记录栈顶
int cur = 0;    //全局变量，记录当前所用的数组的序号

#include<stdio.h>
#include<stdlib.h>
pHashTable create_HashTable()
{
	//使用calloc直接将内部的每个Arr初始化为NULL
	pHashTable hashtable = (pHashTable)calloc(M,sizeof(HashNode));
	if(!hashtable)
	{
		printf("malloc failed");
		exit(-1);
	}
	return hashtable;
}

void push(pHashTable hashtable,ElemType data)
{
	if(cur==0 && top==-1)
	{
		//内部元素全部初始化为0
		hashtable[cur].Arr = (int *)calloc(MAX,sizeof(int));
		if(!hashtable[cur].Arr)
		{
			printf("malloc failed");
			exit(-1);
		}
	}
	if(cur>M-1)
		return;
	if(top<MAX-1)
		hashtable[cur].Arr[++top] = data;
	else if(top>MAX-1)
		return;
	else
	{
		//如果当前数组已经满了，则转到下一个数组进行push操作
		cur++;
		top = -1;
		hashtable[cur].Arr = (int *)calloc(MAX,sizeof(int));
		if(!hashtable[cur].Arr)
		{
			printf("malloc failed");
			exit(-1);
		}
		push(hashtable,data);
	}
}

void pop(pHashTable hashtable)
{
	if(cur>M-1 || cur<0)
		return;
	if(top>-1)
		hashtable[cur].Arr[top--] = 0;  //将pop的元素置为0，即还原到默认初值值
	else if(top<-1)
		return;
	else
	{
		//如果当前数组为空了，则释放掉给数组空间，转到上一个数组进行pop操作
		free(hashtable[cur].Arr);
		hashtable[cur].Arr = NULL;
		cur--;
		top = MAX-1;
		pop(hashtable);
	}
}

int main()
{
	pHashTable hashtable = create_HashTable();
	push(hashtable,1);
	push(hashtable,2);
	push(hashtable,3);
	push(hashtable,4);
	push(hashtable,5);
	push(hashtable,6);
	push(hashtable,7);	

	int i,j;
	printf("After pushed:\n");
	for(i=0;i<M;i++)
	{
		if(hashtable[i].Arr)
		{
			for(j=0;j<MAX;j++)
				printf("%d ",hashtable[i].Arr[j]);
			printf("\n");
		}
	}

	pop(hashtable);
	pop(hashtable);
	pop(hashtable);
	pop(hashtable);
	pop(hashtable);

	printf("After poped:\n");
	for(i=0;i<M;i++)
	{
		if(hashtable[i].Arr)
		{
			for(j=0;j<MAX;j++)
				printf("%d ",hashtable[i].Arr[j]);
			printf("\n");
		}
	}	
	return 0;
}