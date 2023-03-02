#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout << "Enter N : ";
	cin >> n;
	
	int     p = 1;
	int level = 0;
	
	while(p < n)
	{
		level++;	
		p = p*2;
	}
	// calculate closest power of 2
	
	int arr[2*p - 1];
	for(int i = 0 ; i < 2*p -1 ; i ++)
		arr[i] = 0;
	
	// initialize the tree
	cout << "Enter array : ";
	for(int i = p-1 ; i < p - 1 + n ; i ++)
	{
		cin >> arr[i];
	}
	
	for(int i = p-2 ; i >= 0 ; i --)
	{
		int left = arr[2*i + 1];
		int right = arr[2*i + 2];
		arr[i] = max(left , right);
	}
	
	cout << "Tree : " << endl;
	cout << endl;
	
	int count = 2;
	
	for(int i = 0 ;i < 2*p - 1 ; i ++)
	{
		cout << arr[i] << " ";
		if(i == count - 2)
		{
			count*=2;
			cout << endl;
		}
	}
	
	
	int maxpos = 0;
	int second_max = 0;
	
	cout << endl;
	cout << "Maximum " << arr[0] << endl;
	cout << endl;
	
	for(int i = 0; i < level ; i ++)
	{
		int  left = arr[2*maxpos + 1];
		int right = arr[2*maxpos + 2];
	
		cout << "Level " << i << " - players :  " << left << " " << right << endl;
		
		if(left == arr[0])
		{
			second_max =max(second_max , right);
			maxpos = 2*maxpos + 1;
		}
		else
		{
			second_max = max(second_max , left);
			maxpos = 2*maxpos + 2;
		}
	}
	
	cout << "Second Maximum " << second_max << endl;
	
	return 0;
}