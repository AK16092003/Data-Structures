// DFS

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

int visited[1000];
struct 	adjlstnode *adj_lst[1000];

void dfs(int u)
{
	visited[u] = 1;
	printf("%d " , u+1);
	struct adjlstnode *cur = adj_lst[u];
	while(cur!=NULL)
	{
		if(visited[cur->data] == 0)
			dfs(cur->data);
		cur = cur->next;
	}
}

int main()
{
	printf("Enter number of nodes N = ");
	int n;
	scanf("%d" , &n);
	for(int i = 0 ; i < n ; i ++) visited[i] = 0;
	 	
	printf("Enter the matrix: \n");
	int adjmat[n][n];
	

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
		//printf("vertex %d :" , i+1);
		if(visited[i] == 0)
		{
			dfs(i);
			printf("\n");
		}
	}
	
	return 0;
}
