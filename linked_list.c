#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node 
{
	int data;
	struct node *next;
};

struct node *create(int n)
{
	if(n == 0)
	{
		return NULL;
	}
	
	struct node *p , *q , *head;
	
	q = (struct node *)malloc(sizeof(struct node));
	printf("Enter data : ");
	int data;
	scanf("%d" , &data);
	q->data = data;
	q->next = NULL;
	head = q;
	
	for(int i = 1 ; i < n ; i ++)
	{
		p = (struct node *)malloc(sizeof(struct node));
		printf("Enter data : ");
		int data;
		scanf("%d" , &data);
		p->data = data;
		p->next = NULL;
		q->next = p;
		
		q = p;
	}
	
	return head;
	
}


void insert(int pos , int element , struct node *head)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->data = element;
	struct node *h = head;
	for(int i = 1 ; i < pos ; i ++)
	{
		head = head->next;
	}
	p->next = head->next;
	head->next = p;
	head = h;
}


void print(struct node *p)
{
	printf("DISPLAY LINKED LIST \n");
	while(p!=NULL)
	{
		printf("%d " , p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	// create a linked list
	int n;
	printf("Enter size : ");
	scanf("%d" , &n);
	
	struct node *head;
	head = create(n);
	
	// print the linked list
	
	print(head);
	printf("\n");
	
	int pos = 0 , element = 0;
	printf("Enter position to be inserted : "); scanf("%d" , &pos);
	printf("Enter element : ");                 scanf("%d" , &element);
	
	insert(pos , element , head);
	print(head);
	printf("\n");
	
	
	return 0;
}