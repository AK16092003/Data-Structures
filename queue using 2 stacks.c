#include<stdio.h>
#include<conio.h>

int sp1 = 0;
int sp2 = 0;
int size = 10;
int stack1[10];
int stack2[10];

void stack1_push(int x)
{
	if(sp1 == size)
	{
		printf("Overflow stack 1\n");
	}
	else
	{
		stack1[sp1] = x;
		sp1++;
	}
}


void stack2_push(int x)
{
	if(sp2 == size)
	{
		printf("Overflow stack 2\n");
	}
	else
	{
		stack2[sp2] = x;
		sp2++;
	}
}

int stack1_pop()
{
	if(sp1 == 0)
	{
		printf("Underflow stack 1\n");
	}
	else
	{
		return stack1[--sp1];
	}
}


int stack2_pop()
{
	if(sp2 == 0)
	{
		printf("Underflow stack 2\n");
	}
	else
	{
		return stack2[--sp2];
	}
}


void enqueue(int x)
{
	stack1_push(x);
}

int dequeue()
{
	while(sp1 != 0)
	{
		int x = stack1_pop();
		stack2_push(x);
	}
	
	int del_element = stack2_pop();
	
	while(sp2 != 0)
	{
		int x = stack2_pop();
		stack1_push(x);
	}
	
	return del_element;
}

int main()
{
	printf("Operations:\n");
	printf("1) enqueue\n");
	printf("2) dequeue\n");
	printf("3) display\n");
	printf("\n");
	
	while(1)
	{
		int choice;
		printf("Enter your choice : ");
		scanf("%d" , &choice);
		
		if(choice == 1)
		{
			int x;
			printf("Enter a new element : ");
			scanf("%d" , &x);
			enqueue(x);
		}
		else if(choice == 2)
		{
			int del = dequeue();
			printf("Deleted element : %d \n", del);
		}
		else if(choice == 3)
		{
			for(int i = 0 ; i < sp1 ; i ++)
			{
				printf("%d " , stack1[i]);
			}
		}
		else
		{
			printf("Invalid choice\n");
		}
		printf("\n\n");
	}
	
	return 0;
}