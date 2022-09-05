#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node *head = NULL;


struct node
{
	int data;
	struct node *next , *prev;
};


void create(int n){
	
	struct node *p,*q;
	head = (struct node * )malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d" , &(head->data));
	head->prev = NULL;
	head->next = NULL;
	p = head;
	
	for(int i = 0 ; i < n-1 ; i ++)
	{
		q = (struct node *)malloc(sizeof(struct node));
		printf("Enter data : ");
		scanf("%d" , &(q->data));
		q->prev = p;
		q->next = NULL;
		p->next = q;
		p = q;
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

void insert_begin(int x)
{
	struct node *p =(struct node *) malloc(sizeof(struct node));
	p->data = x;
	p->next = head;
	p->prev = NULL;
	head->prev = p;
	head = p;
}

void insert_middle(int x , int ind)
{
	struct node *p;
	struct node *q =(struct node *) malloc(sizeof(struct node));
	p = head;
	q->data = x;
	for(int i = 1; i < ind ; i ++)
	{
		p = p->next;
	}
	q->prev = p;
	q->next = p->next;
	p->next = q;
}

void insert_end(int x)
{
	struct node *p;
	struct node *q =(struct node *) malloc(sizeof(struct node));
	p = head;
	q->data = x;
	while((p->next)!=NULL)
	{
		p = p->next;
	}
	q->prev = p;
	q->next = NULL;
	p->next = q;
}


void delete_begin()
{
	struct node *p = head;
	head = head->next;
	head->prev = NULL;
	free(p);
}

void delete_middle(int ind)
{
	struct node *p;
	
	p = head;
	
	for(int i = 1; i <= ind ; i ++)
	{
		p = p->next;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	
}

void delete_end()
{
	struct node *p;
	p = head;
	
	while((p->next)!=NULL)
	{
		p = p->next;
	}
	(p->prev)->next = NULL;
	free(p);
}




int main()
{
	int n;
	printf("Enter size :");
	scanf("%d" , &n);
	create(n);
	printf("\n");
	printf("1) Insert a node on beginning\n");
	printf("2) Insert a node on middle\n");
	printf("3) Insert a node on end\n");
	
	printf("4) Delete a node on beginning\n");
	printf("5) Delete a node on middle\n");
	printf("6) Delete a node on end\n");
	printf("7) Display all elements\n\n");
	
	while(1)
	{
		int choice = 0;
		printf("Enter your choice : ");
		scanf("%d" , &choice);
		
		if(choice == 1)
		{
			int x;
			printf("Enter element : ");
			scanf("%d" , &x);
			insert_begin(x);
				
		}
		else if(choice ==2)
		{
			int x , ind;
			printf("Enter element : ");
			scanf("%d" , &x);
			printf("Enter index : ");
			scanf("%d" , &ind);
			
			insert_middle(x , ind);
			
		}
		else if(choice == 3)
		{
			int x;
			printf("Enter element : ");
			scanf("%d" , &x);
			insert_end(x);
		}
		else if(choice == 4)
		{
			delete_begin();
				
		}
		else if(choice == 5)
		{
			int ind;
			printf("Enter index : ");
			scanf("%d" , &ind);
			delete_middle(ind);
			
		}
		else if(choice == 6)
		{
			delete_end();
		}
		else if(choice == 7)
		{
			display();
		}
		else
		{
			printf("Invalid input!\n\n");
		}
		printf("\n");
		
	}
	
	return 0;
}