/*******************************************************
题目描述：
如果以m*n矩阵中某个元素为0，则将它所在的行和列都置为0
Date:2014-03-18
********************************************************/
#include<stdio.h>
#include<string.h>

/*
由于我的编译器不支持C99，这里只能将数组row[m]和col[n]作为参数传入
*/
void zeroMatrix(int (*A)[4],int *row,int *col,int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(A[i][j] == 0)
			{
				row[i] = true;
				col[j] = true;
			}
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(row[i] || col[j])
				A[i][j] = 0;
}

int main()
{
	int A[3][4] = 
	{
		{1,4,6,9},
		{2,0,5,3},
		{3,6,3,0},
	};
	int row[3];
	int col[4];
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));

	int i,j;
	printf("the orginal matrix:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}

	zeroMatrix(A,row,col,3,4);
	printf("now the the matrix:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
	
	return 0;
}