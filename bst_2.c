#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

void insert(int data)
{
	struct  node *inter_node;
	inter_node = (struct node *) malloc(sizeof(struct node));
	inter_node->data  = data;
	inter_node->left  = NULL;
	inter_node->right  = NULL;
	
	
	if(root == NULL)
	{
		root = inter_node;
		return ;
	}
	struct node *cur_node = root;
	
	while(1)
	{
		if(cur_node->data < inter_node->data)
		{
			if(cur_node->right == NULL)
			{
				cur_node->right = inter_node;
				break;
			}
			else
			{
				cur_node = cur_node->right;
			}
		}
		else
		{
			if(cur_node->left == NULL)
			{
				cur_node->left = inter_node;
				break;
			}
			else
			{
				cur_node = cur_node->left;
			}
		}
		
	}
	
}



int size(struct node *root)
{
	if(root == NULL) return 0;
	return 1+ size(root->left)+size(root->right);
}

void isempty(struct node *root)
{
	if(root == NULL) printf("Tree is empty\n");
	else printf("Tree is not empty\n");
}

int width(struct node *root , int lev)
{
	if (root == NULL) return 0;
	if (lev == 0) return 1;
	return width(root->left , lev-1) + width(root->right , lev-1);
}


int main()
{
	
	printf("Create a BST : \n");
	
	
	printf("Operations : \n");
	printf("1) Insert a node\n");
	printf("2) Is empty\n");
	printf("3) Size\n");
	printf("4) Width\n");
	
	while(1)
	{
		int ch;
		printf("Enter choice : ");
		scanf("%d" , &ch);
		
		if (ch == 1)
		{
			printf("Enter data : ");
			int data;
			scanf("%d" , &data);
			insert(data);
		}
		else if (ch == 2)
		{
			isempty(root);	
		}
		else if(ch == 3)
		{
			int n = size(root);
			printf("Size of tree : %d\n" , n);
		}
		else if(ch == 4)
		{
			int w;
			printf("Enter level : ");
			scanf("%d" , &w);	
			printf("Width = %d" , width(root , w));
		}
		else
		{
			printf("Invalid Input !");
			break;
		}	
		printf("\n");
	}
	return 0;
}