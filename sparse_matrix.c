#include<stdio.h>
#include<conio.h>

int main()
{
	int n=0 , m=0;
	printf("Enter number of rows : "); scanf("%d" , &n);
	printf("Enter number of cols : "); scanf("%d" , &m);
	
	int Sp_mat[n][m];
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m ; j ++) 
		{
			Sp_mat[i][j] = 0;
		}
	}
	
	
	int e = 0;
	printf("Enter number of elements : "); scanf("%d" , &e);
	
	int array_2d[e][3];
	
	for(int i = 0 ; i < e ; i ++)
	{
		int r , c , x;
		printf("Row : "); scanf("%d" , &r);
		printf("Col : "); scanf("%d" , &c);
		printf("Val : "); scanf("%d" , &x);
		
		array_2d[i][0] = r;
		array_2d[i][1] = c;
		array_2d[i][2] = x;
		
		Sp_mat[r][c] = x;
	}
	
	printf("\n");
	printf("2D ARRAY\n");
	printf("Row\tCol\tVal\n");
	for(int i = 0 ; i < e ; i ++)
	{
		printf("%d\t%d\t%d\n" , array_2d[i][0] ,  array_2d[i][1] ,  array_2d[i][2]);
	}
	
	printf("\n");
	
	printf("SPARSE MATRIX \n");
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m; j ++)
		{
			printf("%d\t" , Sp_mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Memory for 2d array : %d\n" , sizeof(array_2d));
	printf("Memory for sparse matrix : %d\n" , sizeof(Sp_mat));
	
	return 0;
}