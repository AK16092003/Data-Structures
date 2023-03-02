#include<iostream>
using namespace std;

#define MAXSZ 1000

struct node
{
	char alpha;
	int val;
	struct node *left , *right;
};


// implement min heap

struct node * heap[MAXSZ];
int count = 0;

void insert(struct node *x)
{
	heap[count] = x;
	int node = count;
	while(node != 0)
	{
		int parent = (node-1)/2;
		if(heap[parent]->val > heap[node]->val)
		{
			swap(heap[parent] , heap[node]);
		}
		node = parent;
	}
	count++;
}

struct node * delete_element()
{
	struct node * top = heap[0];
	
	heap[0] = heap[--count];
	
	int node = 0;
	while(node < count)
	{
		int left = 2*node + 1;
		int right = 2*node + 2;
		
		if(right < count)
		{
			if(heap[node]->val <= heap[left]->val && heap[node]->val <= heap[right]->val) 
				break;
			if(heap[left]->val < heap[right]->val)
			{	
				swap(heap[node] , heap[left]);
				node = left;
			}
			else if(heap[left]->val >= heap[right]->val)
			{
				swap(heap[node] , heap[right]);
				node = right;
			}
		}
		else if(left < count)
		{
			if(heap[node]->val <= heap[left]->val) 
				break;
			swap(heap[node] , heap[left]);
			node = left;	
		}
		else{
			break;
		}
		
	}
	return top;
}


struct node *merge(struct node *p , struct node *q)
{
	struct node *tmp = (struct node *) malloc(sizeof(struct node));
	tmp->left = p;
	tmp->right = q;
	tmp->val = tmp->left->val + tmp->right->val;
	return tmp;
}


void dfs(struct node *tmp , string s)
{
	if(tmp->left == NULL && tmp->right == NULL)
	{
		cout << tmp->alpha <<" " << s << endl;
		return;
	}
	dfs(tmp->left , s + '0');
	dfs(tmp->right , s + '1');
}

int main()
{
	int values[] = {70,50,80,30,15,10};
	char charac[] = {'a' , 'b' , 'c' , 'd' , 'e' , 'f'};
	
	for(int i = 0 ; i < 6 ; i ++)
	{
		struct node *tmp = (struct node *) malloc(sizeof(struct node));
		tmp->val = values[i];
		tmp->alpha = charac[i];
		tmp->left = NULL;
		tmp->right = NULL; 
		
		insert(tmp);
	}
	
	for(int i = 0; i < 5 ; i ++)
	{
		struct node *p = delete_element();
		struct node *q = delete_element();
		struct node *r = merge(p , q);
		insert(r);
	}
	
	dfs(heap[0] , "");
 	return 0;
}
