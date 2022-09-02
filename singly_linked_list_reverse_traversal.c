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

void traverse_reverse(struct node *p)
{
	printf("DISPLAY LINKED LIST  - REVERSE\n");
	struct node *head = p , *temp = NULL;
	
	while(temp != head)
	{
		while((p->next)!=temp)
		{
			p = p->next;
		}
		printf("%d " , p->data);
		temp = p;
		p = head;
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

	traverse_reverse(head);
	printf("\n");
	
	
	return 0;
}