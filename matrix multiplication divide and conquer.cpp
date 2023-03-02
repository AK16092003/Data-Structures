// matrix multiplication

#include<bits/stdc++.h>
using namespace std;

int ** allocate(int n)
{
	int  ** a = (int **) malloc(n * sizeof(int *));
	for(int i = 0 ; i < n ; i ++)
	{
		a[i] = (int *) malloc(n*sizeof(int));
	}
	return a;
}
int ** add(int **a , int **b , int n)
{
	int  ** ans = allocate(n);
	for(int i= 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < n  ; j ++)
		{
			ans[i][j] = a[i][j] + b[i][j];
		}
	}
	return ans;
}
int ** sub(int **a , int **b , int n)
{
	int  ** ans = allocate(n);
	for(int i= 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < n  ; j ++)
		{
			ans[i][j] = a[i][j] - b[i][j];
		}
	}
	return ans;
}

void input_mat(int **mat , int n)
{
	cout << "Input Matrix" << endl;
	for(int i = 0 ; i <  n ; i ++)
	{
		for(int j = 0 ; j < n ;  j++)
		{
			cin >> mat[i][j];
		}	
	}
}

void print_mat(int ** mat , int n)
{
	cout << "Matrix" << endl;
	for(int i = 0 ; i <  n ; i ++)
	{
		for(int j = 0 ; j < n ;  j++)
		{
			cout << mat[i][j] << " ";
		}	
		cout << endl;
	}
}

int ** multiply(int ** a , int ** b , int n)
{
	int ** ans = allocate(n);
	if(n == 1)
	{
		ans[0][0] = a[0][0] * b[0][0];
		return ans;
	}
	
	int ** a11 = allocate(n/2);
	int ** a12 = allocate(n/2);
	int ** a21 = allocate(n/2);
	int ** a22 = allocate(n/2);
	int ** b11 = allocate(n/2);
	int ** b12 = allocate(n/2);
	int ** b21 = allocate(n/2);
	int ** b22 = allocate(n/2);
	
	int ** c11 = allocate(n/2);
	int ** c12 = allocate(n/2);
	int ** c21 = allocate(n/2);
	int ** c22 = allocate(n/2);
	
	// divide matrix into 4 pieces
	
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n ;  j ++)
		{
			if(i < n/2 && j < n/2)
			{
				a11[i][j] = a[i][j];
			}
			if(i < n/2 && j >= n/2)
			{
				a12[i][j-n/2] = a[i][j];
			}
			if(i >= n/2 && j < n/2)
			{
				a21[i-n/2][j] = a[i][j];
			}
			if(i >= n/2 && j >= n/2)
			{
				a22[i-n/2][j-n/2] = a[i][j];
			}
			
		}
	}
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n ;  j ++)
		{
			if(i < n/2 && j < n/2)
			{
				b11[i][j] = b[i][j];
			}
			if(i < n/2 && j >= n/2)
			{
				b12[i][j-n/2] = b[i][j];
			}
			if(i >= n/2 && j < n/2)
			{
				b21[i-n/2][j] = b[i][j];
			}
			if(i >= n/2 && j >= n/2)
			{
				b22[i-n/2][j-n/2] = b[i][j];
			}
			
		}
	}
	
	c11 = add(multiply(a11 , b11 , n/2) , multiply(a12 , b21 , n/2)  , n/2);
	c12 = add(multiply(a11 , b12 , n/2) , multiply(a12 , b22 , n/2)  , n/2);
	c21 = add(multiply(a21 , b11 , n/2) , multiply(a22 , b21 , n/2)  , n/2);
	c22 = add(multiply(a21 , b12 , n/2) , multiply(a22 , b22 , n/2)  , n/2);
	
	for(int i = 0 ; i < n ; i ++)
	{	
		for(int j = 0 ; j < n ;  j ++)
		{
			if(i < n/2 && j < n/2)
			{
				ans[i][j] = c11[i][j];
			}
			if(i < n/2 && j >= n/2)
			{
				ans[i][j] = c12[i][j-n/2];
			}
			if(i >= n/2 && j < n/2)
			{
				ans[i][j] = c21[i-n/2][j];
			}
			if(i >= n/2 && j >= n/2)
			{
				ans[i][j] = c22[i-n/2][j-n/2];
			}
			
		}
	}
	
	free(a11);
	free(a12);
	free(a21);
	free(a22);
	free(b11);
	free(b12);
	free(b21);
	free(b22);
	free(c11);
	free(c12);
	free(c21);
	free(c22);
	
	return ans;
	
}

int main()
{
	
	int n;
	cout << "Enter size : ";
	cin >> n;
		
	cout << "Matrix 1" << endl;
	
	int ** mat1 = allocate(n);
	int ** mat2 = allocate(n);
	int ** mat3 = allocate(n);
	
	input_mat(mat1 , n);
	input_mat(mat2 , n);
	
	mat3 = multiply(mat1 , mat2 , n);
	print_mat(mat3 , n);
			
	free(mat1);
	free(mat2);
	free(mat3);
	
	return 0;
	
}