// optimal bst
#include<bits/stdc++.h>
#define inf 1000
using namespace std;


double p[1000] , q[1000];
double c[1000][1000] , w[1000][1000];
int r[1000][1000];

struct node{
	int data;
	struct node *left , *right;
};

struct node * construct(int i , int j)
{
	if(i == j)
	{
		return NULL;
	}
	
	int root  = r[i][j];
	struct node *new0 = (struct node *) malloc(sizeof(struct node));
	
	new0->left = construct(i , root-1);
	new0->right = construct(root , j);
	new0->data = root;
	
	return new0;
}

void preorder(struct node *root)
{
	if(root == NULL) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node *root)
{
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

int main()
{
	int n;
	cin >> n;
	
	p[0] = 0;
	for(int i = 1 ; i <= n ; i ++) cin >> p[i];
	for(int j = 0 ; j <= n ; j ++) cin >> q[j];
	
	for(int i = 0 ; i <= n ; i ++) for(int j = 0 ; j <= n ; j ++) c[i][j] = inf;
	
	for(int i = 0 ; i <= n ; i ++)
	{
		w[i][i] = q[i];
		r[i][i] = 0;
		c[i][i] = 0;
	}
	
	for(int len = 1 ; len <= n ; len ++)
	{
		for(int i = 0; i <= n ; i ++)
		{
			int j = i + len;
			if(j > n) break;
			w[i][j] = w[i][j-1] + p[j] + q[j];
			
			for(int k = i+1 ; k <= j ; k ++)
			{
				double val = c[i][k-1] + c[k][j] + w[i][j];
				if(val < c[i][j])
				{
					c[i][j] = val;
					r[i][j] = k;
				}
			}
		}
	}
	
	
	cout << "Cost : " << endl;
	for(int len = 1 ; len <= n ; len ++)
	{
		for(int i = 0; i <= n ; i ++)
		{
			int j = i + len;
			if(j > n) break;
			cout << c[i][j] << " ";
		}		
		cout << endl;
	}
	
	cout << endl;
	cout << "Weight : " << endl;
	for(int len = 1 ; len <= n ; len ++)
	{
		for(int i = 0; i <= n ; i ++)
		{
			int j = i + len;
			if(j > n) break;
			cout << w[i][j] << " ";
		}		
		cout << endl;
	}
	
	cout << endl;
	cout << "Root : " << endl;
	for(int len = 1 ; len <= n ; len ++)
	{
		for(int i = 0; i <= n ; i ++)
		{
			int j = i + len;
			if(j > n) break;
			cout << r[i][j] << " ";
		}		
		cout << endl;
	}
	cout << endl;
	
	struct node *head = construct(0,n);
	cout << "Preorder: ";
	preorder(head);
	cout << endl;
	cout << "Postorder: ";
	postorder(head);
	cout << endl;
	cout << "Inorder :" << endl;
	
	queue<struct node *> bfs_queue;
	bfs_queue.push(head);
	int lev = 0;
	while(bfs_queue.size())
	{
		int n = bfs_queue.size();
		cout << lev << ": ";
		for(int i = 0 ; i < n ;  i++)
		{
			struct node * cur =  bfs_queue.front();
			bfs_queue.pop();
			
			cout << cur->data << " ";
			if(cur->left != NULL)  bfs_queue.push(cur->left);
			if(cur->right != NULL) bfs_queue.push(cur->right);
		}
		cout << endl;
		lev++;
	}
	
	return 0;
}
