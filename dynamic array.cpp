// dynamic array

#include<bits/stdc++.h>
using namespace std;
int n = 0;
int sz = 1;
int * arr;

void insert(int element)
{
	if(n < sz)
	{
		// insert
		arr[n] = element;
		n++;
	}
	else
	{
		// double size
		int *arr1 = (int *) malloc(2*sz*sizeof(int));
		sz *= 2;
		for(int i = 0 ; i < n ; i ++)
		{
			arr1[i] = arr[i];
		}
		arr = arr1;
		insert(element);
	}
}

void print()
{
	for(int i = 0 ; i < n ; i ++)
	{
		cout <<arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	arr = (int *)malloc(sizeof(int));
	int x = 0;
	while(true)
	{
		cin >> x;
		insert(x);
		print();
		cout << "Array size: " << sz << " , N = " << n << endl;
	}
	
	return 0;
}
