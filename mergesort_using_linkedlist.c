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


struct node * combine(struct node *head1 , struct node *head2)
{
	struct node *r , *s , *h;
	h = (struct node *) malloc(sizeof(struct node));
	s = h;
	while(head1!=NULL || head2!=NULL)
	{
		if(head1 == NULL)
		{
			s->next = head2;
			break;
		}
		else if(head2 == NULL)
		{
			s->next = head1;
			break;
		}
		else
		{
			int d1 = head1->data;
			int d2 = head2->data;
			
			if(d1 < d2)
			{
				r = head1;
				head1 = head1 -> next;
				s -> next = r;
				r->next = NULL;
				s = r;
			}
			else
			{
				r = head2;
				head2 = head2 -> next;
				s -> next = r;
				r->next = NULL;
				s = r;
			}
		}
	}
	
	return h->next;
}

int main()
{
	int k;
	printf("Enter number of linked list : "); scanf("%d" , &k);
	struct node * array[k];
	
	for(int i = 0 ; i < k ; i ++){
		printf("Linked list %d : \n" , (i+1));
		int n ;
		printf("Enter size : ");
		scanf("%d" , &n);
		array[i] = create(n);
	}
	
	for(int i = 0 ; i < k ; i ++)
	{
		printf("display : %d " , (i+1));
		display(array[i]);
	}
	while(k > 1)
	{
	
		if (k%2 == 0)
		{
			k = k/2;
			for(int i = 0 ; i < k ; i ++)
			{
				array[i] = combine(array[2*i] , array[2*i+1]);
				printf("combine %d %d  " , 2*i , 2*i+1);
				display(array[i]);
			}
		}
		else
		{
			k = k/2 + 1;
			int i = 0;
			for(i = 0 ; i < k-1 ; i ++)
			{
				array[i] = combine(array[2*i] , array[2*i+1]);
				printf("combine %d %d  " , 2*i , 2*i+1);
				display(array[i]);
			}
			array[i] = array[2*i];
			printf("combine %d " , 2*i);
			display(array[i]);
		}
	}
	
	return 0;
}
