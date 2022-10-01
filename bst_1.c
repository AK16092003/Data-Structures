#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};


struct node *create(int n)
{
	struct node *root , *inter_node;
	root = (struct node *) malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d" , &(root->data));
	root->left = NULL;
	root->right = NULL;
	
	for(int i = 1 ; i < n ; i ++)
	{
		inter_node = (struct node *) malloc(sizeof(struct node));
		printf("Enter data : ");
		scanf("%d" , &(inter_node->data));
	
		inter_node->left  = NULL;
		inter_node->right  = NULL;
	
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
	
	return root;
}


void search(int data , struct node *root)
{
	int flag = 0;
	while(root!=NULL)
	{
		if(data < root->data)
		{
			root = root->left;
		}
		else if(data > root->data)
		{
			root = root->right;
		}
		else
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1)
	{
		printf("Data found !\n");	
	}
	else
	{
		printf("Data not found! \n");
	}
}

void inorder(struct node *root)
{
	if(root == NULL) return ;
	
	inorder(root->left);
	printf("%d " , root->data);
	inorder(root->right);
}

void preorder(struct node *root)
{
	if(root == NULL) return ;
	
	printf("%d " , root->data);
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	
	printf("Create a BST : \n");
	int n;
	printf("Enter size : "); scanf("%d" , &n);
	
	struct node *root = create(n);
	
	printf("Operations : \n");
	printf("1) Search\n");
	printf("2) Inorder  traversal\n");
	printf("3) Preorder traversal\n");
	
	while(1)
	{
		int ch;
		printf("Enter choice : ");
		scanf("%d" , &ch);
		
		if (ch == 1)
		{
			int e;
			printf("Enter search data : ");
			scanf("%d" , &e);
			search(e , root);	
		}
		else if(ch == 2)
		{
			inorder(root);
		}
		else if(ch == 3)
		{
			preorder(root);		
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