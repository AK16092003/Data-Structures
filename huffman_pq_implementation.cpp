#include<bits/stdc++.h>
using namespace std;

struct node 
{
	int frq;
	struct node *left;
	struct node *right;	
	int id;
};

class comp
{
	public:
	bool operator()(struct node *a , struct node *b)
	{
		return a->frq > b->frq;
	}
};

struct node *merge(struct node *p1 , struct node *p2)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->frq = p1->frq + p2->frq;
	if(p1->frq > p2->frq)
		swap(p1 , p2);
	new_node->left = p1;
	new_node->right = p2;
	new_node->id = -1;
	return new_node;
}

void dfs(struct node *root , string s)
{
	if(root->left != NULL) dfs(root->left , s + "0");
	if(root->right != NULL) dfs(root->right , s + "1");
	if(root->id != -1)
	{
		cout << (char)((root->id) + 'a')  << " = "  << root->frq  << " encoding : " << s<< endl;
	}
}

int main()
{
	
	int n;
	cin >> n;
	int frq[n];
	
	priority_queue<struct node* , vector<struct node*> , comp> pq; 
	
	for(int i = 0 ; i < n ; i ++)
	{
		struct node* dummy = (struct node *) malloc(sizeof(struct node));
		cin >> dummy->frq;
		dummy->id = i;
		dummy->left=NULL;
		dummy->right=NULL;
		pq.push(dummy);
	}
	while(pq.size() > 1)
	{
		struct node *p1 = pq.top(); pq.pop();
		struct node *p2 = pq.top(); pq.pop();
		struct node *p3 = merge(p1 , p2);
		pq.push(p3);
	}
	struct node *head = pq.top();
	dfs(head , "");
	
	
	return 0;
}
