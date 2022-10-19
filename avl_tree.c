#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	int height;
	struct node *left;
	struct node *right;
};

int max(int a , int b)
{
	return a>b?a:b;
}
int height(struct node *root)
{
	if(root == NULL) return 0;
	return root->height;
}

int balance_factor(struct node *root)
{
	return height(root->left) - height(root->right);
}

struct node *new_node(int data)
{
	struct node *root = (struct node *)malloc(sizeof(struct node));
	root->data = data;
	root->height = 1;
	root->left = NULL;
	root->right = NULL;
	return root;
}

struct node *right_rotate(struct node *root)
{
	struct node *t3 , *y , *z;
	z = root;
	y = root->left;
	t3 = y->right;
	
	y->right = z;
	z->left = t3;
	
	z->height = 1 + max(height(z->left) , height(z->right));
	y->height = 1 + max(height(y->left) , height(y->right));
	
	return y;
}

struct node *left_rotate(struct node *root)
{
	struct node *t3 , *y , *z;
	z = root;
	y = z->right;
	t3 = y->left;
	
	y->left = z;
	z->right = t3;
	
	z->height = 1 + max(height(z->left) , height(z->right));
	y->height = 1 + max(height(y->left) , height(y->right));
	
	return y;
}

struct node * insert(struct node *root , int data)
{
	if(root == NULL) return new_node(data);
	else if(root->data < data) root->right = insert(root->right , data);
	else if(root->data > data) root->left = insert(root->left , data);
	
	root->height =  1 + max(height(root->left) , height(root->right));
	printf("node : %d , height = %d \n" , root->data , root->height);
	int bf = balance_factor(root);
	
	if(-1<=bf && bf <= 1)
	{
		// the node is balanced !
		printf("insert data : %d , cur_node = %d , bf = %d \n" , data , root->data , bf);
	}
	else
	{
		// unbalanced node
		printf("unbalanced\n");
		printf("insert data : %d , cur_node = %d , bf = %d \n" , data , root->data , bf);
		if(bf > 1)
		{
			// right rotation
			if(root->left->data > data)
			{
				// only right rotation
				root = right_rotate(root);
			}
			else
			{
				// double rotation
				root->left = left_rotate(root->left);
				root = right_rotate(root);
				
			}
		}
		else
		{
			// left rotation
			if(root->right->data < data)
			{
				// only left rotation
				root = left_rotate(root);
			}
			else
			{
				// double rotation
				root->right = right_rotate(root->left);
				root = left_rotate(root);
				
			}
		}
	}
	
	return root;
}

struct node * delete(struct node *root , int data)
{
	if(root == NULL) return root;
	else if(root->data < data) root->right = delete(root->right , data);
	else if(root->data > data) root->left = delete(root->left , data);
	else {
		return NULL;
	}
	
	root->height =  1 + max(height(root->left) , height(root->right));
	printf("node : %d , height = %d \n" , root->data , root->height);
	int bf = balance_factor(root);
	
	if(-1<=bf && bf <= 1)
	{
		// the node is balanced !
		printf("delete data : %d , cur_node = %d , bf = %d \n" , data , root->data , bf);
	}
	while(bf>=2 || bf<=-2)
	{
		// unbalanced node
		printf("unbalanced\n");
		printf("delete data : %d , cur_node = %d , bf = %d \n" , data , root->data , bf);
		if(bf > 1)
		{
			// right rotation
			if(root->left->data > data)
			{
				// only right rotation
				root = right_rotate(root);
			}
			else
			{
				// double rotation
				root->left = left_rotate(root->left);
				root = right_rotate(root);
				
			}
		}
		else
		{
			// left rotation
			if(root->right->data < data)
			{
				// only left rotation
				root = left_rotate(root);
			}
			else
			{
				// double rotation
				root->right = right_rotate(root->left);
				root = left_rotate(root);
				
			}
		}
		bf = balance_factor(root);
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
	root  = insert(root , 5);
	root  = insert(root , 6);
	root  = insert(root , 7);
	root  = insert(root , 8);
	root  = insert(root , 9);
	root  = insert(root , 10);
	root  = insert(root , 11);
	root  = insert(root , 12);
	root  = insert(root , 13);
	root  = insert(root , 14);
	
	printf("\npreorder: ");
	preorder(root);
	printf("\ninorder: ");
	inorder(root);
	root  = delete(root , 13);
	
	printf("\npreorder: ");
	preorder(root);
	printf("\ninorder: ");
	inorder(root);
	
	return 0;
}