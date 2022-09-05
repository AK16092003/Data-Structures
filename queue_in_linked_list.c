// stack using linked list 
#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
} *head;


void insert_end(int x)
{
	struct node *p =(struct node *) malloc(sizeof(struct node));
	p->data = x;
	p->next= NULL;
	struct node *q = head;
	if(head == NULL)
	{
		//first node
		head = p;	
	}
	else
	{

		while( (q -> next)!=NULL)
		{
			q = q->next;
		}
		q-> next  = p;
	}
}

int delete_begin()
{
	if(head == NULL)
	{
		printf("Linked list is empty\n");
		return -1;
	}
	else
	{
		struct node *p = head;
		head = head->next;
		int data = p->data;
		free(p);
		return data;
	}
}

void display()
{
	struct node *p = head;
	while(p!=NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}


int main()
{
	
	printf("1) ENQUEUE\n");
	printf("2) DEQUEUE\n");
	printf("3) DISPLAY QUEUE\n\n");
	
	while(1)
	{
		int ch = 0;
		printf("Enter your choice : ");
		scanf("%d" , &ch);
		
		if(ch == 1)
		{
			int x;
			printf("Enter data : ");
			scanf("%d" , &x);
			insert_end(x);
		}
		else if(ch == 2)
		{
			int x = delete_begin();
			printf("deleted element : %d\n" , x);
		}
		else if(ch == 3)
		{
			display();
		}
		else
		{
			printf("Invalid choice , try again!\n");
		}
		printf("\n");
	}

	return 0;
}