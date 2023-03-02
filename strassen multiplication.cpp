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
			ans[i][j] = 0;
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
	
	int ** A = allocate(n/2);
	int ** B = allocate(n/2);
	int ** C = allocate(n/2);
	int ** D = allocate(n/2);
	int ** E = allocate(n/2);
	int ** F = allocate(n/2);
	int ** G = allocate(n/2);
	int ** H = allocate(n/2);
	
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
				A[i][j] = a[i][j];
			}
			if(i < n/2 && j >= n/2)
			{
				B[i][j-n/2] = a[i][j];
			}
			if(i >= n/2 && j < n/2)
			{
				C[i-n/2][j] = a[i][j];
			}
			if(i >= n/2 && j >= n/2)
			{
				D[i-n/2][j-n/2] = a[i][j];
			}
			
		}
	}
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n ;  j ++)
		{
			if(i < n/2 && j < n/2)
			{
				E[i][j] = b[i][j];
			}
			if(i < n/2 && j >= n/2)
			{
				F[i][j-n/2] = b[i][j];
			}
			if(i >= n/2 && j < n/2)
			{
				G[i-n/2][j] = b[i][j];
			}
			if(i >= n/2 && j >= n/2)
			{
				H[i-n/2][j-n/2] = b[i][j];
			}
			
		}
	}
	
	
	int ** p1 = allocate(n/2);
	int ** p2 = allocate(n/2);
	int ** p3 = allocate(n/2);
	int ** p4 = allocate(n/2);
	int ** p5 = allocate(n/2);
	int ** p6 = allocate(n/2);
	int ** p7 = allocate(n/2);
	
	p1 = multiply(A , sub(F , H , n/2) , n/2);
	p2 = multiply(add(A , B , n/2 ) , H , n/2);
	p3 = multiply( add(C , D , n/2) , E , n/2);
	p4 = multiply(D , sub(G , E , n/2) , n/2);
	p5 = multiply(add(A , D , n/2) , add(E , H , n/2) , n/2);
	p6 = multiply(sub(B , D , n/2) , add(G , H , n/2) , n/2);
	p7 = multiply(sub(A , C , n/2) , add(E , F , n/2) , n/2);
	 
	
	 
	c11 = add(add(p5 , p4 , n/2) , sub(p6 , p2 , n/2) , n/2);
	c12 = add(p1 , p2 , n/2);
	c21 = add(p3 , p4 , n/2);
	c22 = add(sub(p1 , p3 , n/2) , sub(p5 , p7 , n/2) , n/2);
	
	
	for(int i = 0 ; i < n ; i ++)
	{	
		for(int j = 0 ; j < n ;  j ++)
		{
			ans[i][j] = 0;
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
	
	free(A);
	free(B);
	free(C);
	free(D);
	free(E);
	free(F);
	free(G);
	free(H);
	
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	
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