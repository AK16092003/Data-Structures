#include<stdio.h>
#include<conio.h>

#define MAXSZ 1000
// MIN HEAP 



int heap[MAXSZ];
int count = 0;

void swap(int u , int v)
{
	int temp = heap[u];
	heap[u] = heap[v];
	heap[v] = temp;
}

void insert(int x)
{
	heap[count] = x;
	int node = count;
	while(node != 0)
	{
		int parent = (node-1)/2;
		if(heap[parent] > heap[node])
		{
			swap(parent , node);
		}
		node = parent;
	}
	count++;
}

int delete_element()
{
	int top = heap[0];
	
	heap[0] = heap[--count];
	heap[count] = 1000;
	
	int node = 0;
	while(node < count)
	{
		int left = 2*node + 1;
		int right = 2*node + 2;
		
		if(heap[node] <= heap[left] && heap[node] <= heap[right]) break;
		
		if(heap[left] < heap[right])
		{	
			if(left >= count) break;
			
			swap(node , left);
			node = left;
		}
		else if(heap[left] >= heap[right])
		{
			if(right >= count) break;
			
			swap(node , right);
			node = right;
		}
	}
	return top;
}


int main()
{
	int n;
	printf("Enter size of array : ");
	scanf("%d" , &n);
	
	int arr[n];
	for(int i = 0 ; i < n ; i ++)
	{
		printf("Enter element : ");
		scanf("%d" , &arr[i]);
		insert(arr[i]);
	}
	
	printf("insert done\n");
	printf("Sorted array : ");
	
	for(int i = 0 ; i < n ; i ++)
	{
		printf("%d " , delete_element());
	}
	return 0;
}