// randomised quicksort
#include<bits/stdc++.h>
using namespace std;
int arr[1000];

void quicksort(int l , int r)
{
	if(l >= r) return;
	
	int i = l , j = r;
	int ind = l + rand()%(r - l + 1);
	swap(arr[ind] , arr[l]);
	int piv = arr[l];
	
	while(i < j)
	{
		while(i < r && arr[i] <= piv) i++;
		while(j > l && arr[j] >  piv) j--;
		if(i < j) swap(arr[i] , arr[j]);
		else	  swap(arr[j] , arr[l]);
	}
	
	quicksort(j+1 , r);
	quicksort(l , j-1);
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> arr[i];
	}
	
	quicksort(0 , n-1);
	for(int i = 0 ;i  < n ; i ++)
	{
		cout << arr[i] << " "; 
	}
	cout << endl;
	
	return 0;
}
