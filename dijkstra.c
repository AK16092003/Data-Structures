#include<stdio.h>

int main()
{
	// dijkstra
	
	int n , m;
	printf("Enter number of nodes : ");
	scanf("%d" , &n);
	
	printf("Enter number of edges : ");
	scanf("%d" , &m);
	
	int adj_mat[n][n];
	
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < n ; j ++)
		{
			adj_mat[i][j] = -1;
		}
		adj_mat[i][i] = 0;
	}
	for(int i = 0 ; i < m ; i ++)
	{
		int x , y , z;
		printf("Start node | End node | Weight    ");
		scanf("%d%d%d" , &x , &y , &z);
		adj_mat[x][y] = z;
		adj_mat[y][x] = z;
	}
	
	int distance[n];
	int visited[n];
	
	for(int i = 0 ; i < n ; i ++)
	{
		distance[i] = 1000;
		visited[i] = 0;
	}
	
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j< n ; j ++)
		{
			printf("%d   " , adj_mat[i][j]);
		}
		printf("\n");
	}
	
	int start = 0;
	distance[start] = 0;
	
	while(start >=0)
	{
		int new_dist = 1000 , new_start = -1;
		
		for(int i = 0 ; i < n; i ++)
		{
			if(adj_mat[start][i]>0 && visited[i] == 0)
			{
				if(distance[i] > distance[start] + adj_mat[start][i])
				{
					distance[i] = distance[start] + adj_mat[start][i];
				}
			}
		}
		
		printf("\n");
		visited[start] = 1;
		
		for(int i = 0 ; i  < n ; i ++)
		{
			if(new_dist > distance[i] && visited[i] == 0)
			{
				new_dist = distance[i];
				new_start = i;
			}
			printf("%d " , distance[i]);
		}
		start = new_start;
		printf("\n");
	}
	
	return 0;
}