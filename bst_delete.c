#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node * new_node(int data)
{
	struct node * r = (struct node *)malloc(sizeof(struct node));
	r->data = data;
	r->left = NULL;
	r->right =NULL;
	return r;
}



struct node*insert(struct node *root , int data)
{
	if (root == NULL)
	{
		return new_node(data);
	}
	else if(root->data < data)
	{
		root->right = insert(root->right , data);
	}
	else
	{
		root->left = insert(root->left , data);
	}
	return root;
}

struct node *delete(struct node *root , int data)
{
	if(root == NULL)
	{
		printf("data not found \n\n");
	}
	else
	{
		if(root->data < data)
		{
			root->right = delete(root->right , data);	
		}
		else if(root -> data >data)
		{
			root->left = delete(root->left , data);
		}
		else
		{
			// node found
			if(root->right != NULL)
			{
				if(root->right->left == NULL)
				{
					root->right->left = root->left;
					struct node *c = root->right;
					free(root);
					return c;
				}
				else
				{
				
					struct node *c = root->right , *d = NULL;
					int temp = -1;
					
					while(c->left!=NULL)
					{
						if(c->left->left == NULL)
						{
							d = c;
						}
						c = c->left;
						temp = c->data;
					}
					
					root->data = temp;
					free(c);
					d->left = NULL;
				}	
			}
			else if(root->left!=NULL)
			{
				if(root->left->right == NULL)
				{
					root->left->right = root->right;
					struct node *c = root->left;
					free(root);
					return c;
				}
				else
				{
				
					struct node *c = root->left , *d = NULL;
					int temp = -1;
					
					while(c->right!=NULL)
					{
						if(c->right->right == NULL)
						{
							d = c;
						}
						c = c->right;
						temp = c->data;
					}
					
					root->data = temp;
					free(c);
					d->right = NULL;
				}	
			}
			else
			{
					free(root);
					return NULL;
				
			}
		}
		
	}
	return root;
}


void preorder(struct node *root)
{
	if(root == NULL)return ;
	printf("%d " , root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct node *root)
{
	if(root == NULL)return ;
	inorder(root->left);
	printf("%d " , root->data);
	inorder(root->right);
	
}



int main()
{
	struct node *root = NULL;
	root = insert(root , 5);
	root = insert(root , 6);
	root = insert(root , 7);
	root = insert(root , 8);
	root = insert(root , 9);
	root = insert(root , 10);
	root = insert(root , 4);
	root = insert(root , 3);
	root = insert(root , 2);
	root = insert(root , 1);
	root = insert(root , 0);
	
	printf("inorder : ");
	inorder(root);
	printf("\npreorder : ");
	preorder(root);
	printf("\n");
	
	root = delete(root , 0);
	root = delete(root , 1);
	root = delete(root , 2);
	root = delete(root , 3);
	root = delete(root , 4);
	root = delete(root , 5);
	
	printf("inorder : ");
	inorder(root);
	printf("\npreorder : ");
	preorder(root);
	printf("\n");
	
	return 0;
}

