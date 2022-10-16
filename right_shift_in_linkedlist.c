#include<stdio.h>


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


void display(struct node *p)
{
	while(p!=NULL)
	{
		printf("%d " , p->data);
		p = p->next;
	}
	printf("\n");
}

struct node *right_shift(struct node *head , int k , int n)
{
	struct node *p , *q , *h;
	p = head;
	if(k == 0) return head;
	for(int i = 0 ; i < n-k-1 ; i ++)
	{
		p = p->next;
	}
	q = p->next;
	p->next = NULL;
	h = q;
	while((q->next)!=NULL)
	{
		q = q->next;
	}
	q->next = head;
	return h;
}
int main()
{
	int n ;
	printf("Enter size : ");
	scanf("%d" , &n);
	struct node *head = create(n);
	
	while(1)
	{
		printf("Enter number of right shifts : ");
		int k;
		scanf("%d" , &k);
		head = right_shift(head , k%n , n);
		display(head);
		printf("\n");
	}
	
	
	return 0;
}
