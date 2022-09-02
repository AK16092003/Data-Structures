#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
	
};

struct node *create(int n)
{
	struct node *p , *q , *head;
	
	q = (struct node *)malloc(sizeof(struct node));
	
	printf("Enter data %d :" , 1);
	scanf("%d" , &(q->data));
	
	q->next = NULL;	
	q->prev = NULL;
	head = q;
	
	for(int i = 1 ; i < n ; i ++)
	{
		p = (struct node *)malloc(sizeof(struct node));
		printf("Enter data %d :" , (i+1));
		scanf("%d" , &(p->data));
		p->next = NULL;
		p->prev = q;
		q->next = p;
		q = p;	
	}
	
	return head;
}


void insert(int data , int index , struct node *head)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	
	struct node *p = head;
	
	for(int i = 1 ; i < index ; i ++)
	{
		p = p->next;
	}
	
	new_node->prev = p;
	new_node->next = p->next;
	p->next = new_node;
	(new_node->next)->prev = new_node;
	
}

void print(struct node *head)
{
	struct node *p = head;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}

void print_reverse(struct node *head)
{
	struct node *p = head , *tail = NULL;
	
	while(p!=NULL)
	{
		tail = p;
		p = p->next;
	}
	
	p = tail;
	
	while(p!=NULL)
	{
		printf("%d " ,(p->data));
		p = p->prev;
	}
	
}
void main()
{
	int n;
	printf("Enter size of doublylinked list : ");
	scanf("%d" , &n);
	struct node *head = create(n);
	printf("\n\n");
	printf("1. for insert a node\n");
	printf("2. for printing the doubly linked list\n");
	printf("3. for printing the doubly linked list in reverse\n\n");
	
	while(1)
	{
		printf("\nEnter your choice : ");
		int choice;
		scanf("%d" , &choice);
		
		if(choice == 1)
		{
			int data , ind;
			printf("Enter data : ");
			scanf("%d" , &data);
			printf("Enter position : ");
			scanf("%d" , &ind);
			insert(data , ind , head);
		}
		else if(choice == 2)
		{
			print(head);
		}
		else if(choice == 3)
		{
			print_reverse(head);
		}
		else
		{
			printf("Invalid choice ! , Try Again !");	
		}
		printf("\n");	
	}
	
}