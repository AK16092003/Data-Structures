// adjacency matrix to adjacency list conversion

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
	printf("Adjacency Matrix to List Conversion : \n\n");
	printf("Enter number of nodes N = ");
	int n;
	scanf("%d" , &n);
	
	printf("Enter the matrix: \n");
	int adjmat[n][n];
	
	struct 	adjlstnode *adj_lst[n];

	for(int i = 0 ; i < n ; i ++)
	{
		adj_lst[i] = NULL;
		
		for(int j = 0 ; j < n ; j ++)
		{
			scanf("%d" , &adjmat[i][j]);
			if(adjmat[i][j] == 1)
			{
				// insert a new node
				adj_lst[i] = insert(j , adj_lst[i]);
			}
		}
		
	}
	printf("\n");
	for(int i = 0 ; i < n ; i ++)
	{
		printf("vertex %d :" , i+1);
		display(adj_lst[i]);
		printf("\n");
	}
	
	
		
	return 0;
}