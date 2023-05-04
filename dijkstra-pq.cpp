#include<bits/stdc++.h>
#define inf 10000
using namespace std;

int main()
{
	int n;
	cout << "Enter number of nodes: ";
	cin >> n;
	
	int m;
	cout << "Enter number of edges : ";
	cin >> m;
	
	vector<pair<int , int >> adjlst[n+1];
	
	for(int i = 0 ; i < m ; i ++)
	{
		int a , b ,c;
		cout <<"Start node | End node | cost : ";
		cin >> a >> b >> c;
		adjlst[a].push_back({b , c});
	}
	
	int dist[n+1];
	int key[n+1];
	int visited[n+1];
	
	for(int i = 0 ; i <= n ; i ++)
	{
		dist[i] = inf;
		key[i] = 0;
		visited[i] = 0;
	}
	
	dist[1] = 0;
	priority_queue<pair<int , int>> pq;
	
	for(int i = 1 ; i <= n ; i ++)
	{
		pq.push({-dist[i] , i});
	}
	
	while(pq.size())
	{
		pair<int,int> top = pq.top();
		pq.pop();
		int u = top.second;
		visited[u] = 1;
		for(auto kk : adjlst[u])
		{
			int v = kk.first;
			int c = kk.second;
			
			if(visited[v] == 0 && dist[v] > dist[u] + c)
			{
				dist[v] = dist[u] + c;
				key[v] = u;
				pq.push({-dist[v] , v});
			}
		}
		
	}
	
	
	for(int i = 0 ; i <= n ; i ++)
	{
		cout << i << " : " << dist[i] << " - " << key[i] << endl;
	}
	return 0;
}
