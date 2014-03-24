/*******************************************************
题目描述：
将n*n的矩阵原地（即不开辟额外的辅助空间）逆时针旋转90度
Date:2014-03-18
********************************************************/
#define N 4
#include<stdio.h>

void swap(int *a,int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void rotate(int A[][N],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			swap(&A[i][j],&A[j][i]);
	for(i=0;i<n/2;i++)
		for(j=0;j<n;j++)
			swap(&A[i][j],&A[n-i-1][j]);
}

int main()
{
	int A[N][N] = 
	{
		{11,12,13,14},
		{15,16,17,18},
		{19,20,21,22},
		{23,24,25,26}
	};

	int i,j;
	printf("the orginal matrix:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}

	rotate(A,N);
	printf("the rotated matrix:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}

	return 0;
}