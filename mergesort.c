#include<stdio.h>
#include<stdlib.h>
#define MAXSZ 1000

int arr[MAXSZ];
int n;


void printarr()
{
	printf("Array : ");
	for(int i = 0 ; i < n ; i ++)
	{
		printf("%d " , arr[i]);
	}
	printf("\n");
}

void mergesort(int l , int r)
{
	if(r - l == 1) return ;
	
	int m = (l + r)/2;
	mergesort(l,m);
	mergesort(m,r);
	
	int n1 = m - l;
	int n2 = r - m;
	int temp_arr[r];
	int i = l , j = m , k = l;
	
	while(k < r)
	{
		if((j!=r) && ((i == m) ||(arr[i] >= arr[j])))
		{
			temp_arr[k] = arr[j];
			j++;
			k++;
		}
		else
		{
			temp_arr[k] = arr[i];
			i++;
			k++;
		}
	}
	
	for(int i = l ; i < r ; i ++) arr[i] = temp_arr[i];
	
	printf("%d-%d : " , l , r);
	printarr();
}


int main()
{

	printf("Enter the size : ");
	scanf("%d" , &n);
	printf("Enter elements : ");
	for(int i = 0 ; i <  n ; i ++){
		scanf("%d" , &arr[i]);
	}	
	
	mergesort(0 , n);
	printarr();
	return 0;
}