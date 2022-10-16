// adjacency list to adjacency matrix conversion

#include<stdio.h>
#include<stdlib.h>


struct adjlstnode
{
	int data;
	struct adjlstnode *next;
};

struct adjlstnode * insert(int data , struct adjlstnode *head)
{
	struct adjlstnode *new_node = (struct adjlstnode *)malloc(sizeof(struct adjlstnode));
	new_node->data = data;
	new_node->next = head;
	head = new_node;
	return head;
}

void display(struct adjlstnode *head)
{
	while(head!=NULL)
	{
		printf("%d " , ((head->data) + 1));
		head = head->next;
	}
}


int main()
{
	printf("Adjacency List to Matrix Conversion : \n\n");
	printf("Enter number of nodes N = ");
	int n;
	scanf("%d" , &n);
	
	int adjmat[n][n];
	for(int i = 0 ; i < n ; i ++) for(int j = 0 ; j < n ; j ++) adjmat[i][j] = 0;
	
	for(int i = 0 ; i < n ; i ++)
	{
		int k = 0;
		printf("Enter total size of Adjlst[%d]  " , i+1);
		scanf("%d" , &k);
		printf("Enter the adjacent vertices of %d :  " , i+1);
		for(int j = 0 ; j < k ; j ++)
		{
			int x;
			scanf("%d" , &x);
			adjmat[i][x-1] = 1;	
		}
	}
	printf("\n");
	printf("Adjacency Matrix : \n\n");
	
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < n ; j ++)
		{
			printf("%d " , adjmat[i][j]);
		}
		printf("\n");
	}
	
	
		
	return 0;
}