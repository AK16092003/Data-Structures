//BFS TRAVERSAL

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

int queue[1000];
int rear = 0 , front = 0;
int sz = 1000;
void enqueue(int data)
{
	queue[rear] = data;
	rear++;
	rear = rear%sz;
}
int dequeue()
{
	int data = queue[front];
	front++;
	front = front%sz;
	return data;
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
	
	// start at vertex 1
	
	printf("BFS : \n");
	enqueue(0);
	
	while(front != rear)
	{
		int u = dequeue();
		struct adjlstnode *cur = adj_lst[u];
		visited[u] = 1;
	
		printf("%d " , u+1);
	
		while(cur!=NULL)
		{
			if(visited[cur->data] == 0)
				enqueue(cur->data);
			cur = cur->next;
		}

	}
				
	return 0;
}
