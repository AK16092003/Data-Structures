#include<stdio.h>
#include<conio.h>

int size = 100;
int queue[100];
int front = 0;
int rear  = 0;

void enqueue(int x)
{
	if(front == rear && queue[front]!=0)
	{
		printf("Overflow\n");
		return ;
	}
	queue[rear] = x;
	rear = (rear + 1)%size;
}

int dequeue()
{
	if(front == rear && queue[front]==0)
	{
		printf("Underflow\n");
		return 0;
	}
	int del = queue[front];
	queue[front] = 0;
	front = (front + 1)%size;
	return del;
}

void display()
{
	if(front < rear)
	{
		for(int i = front ; i < rear ; i ++)
		{
			printf("%d ",queue[i]);
		}
	}
	else
	{
		for(int i = front ; i < size ; i ++)
		{
			printf("%d ",queue[i]);
		}
		for(int i = 0 ; i < rear ; i ++)
		{
			printf("%d ",queue[i]);
		}
	}
}

int isempty()
{
	if(front == rear && queue[rear] == 0)
	{
		return 1;
	}
	return 0;
}

int main()
{
	
	printf("1) Enqueue a new element\n");
	printf("2) Dequeue a element\n");
	printf("3) Print all elements in queue\n");
	printf("4) Front and back values\n");
	printf("5) Check whether queue is empty\n");
	
	while(1)
	{
		int ch;
		printf("Enter your choice : ");
		scanf("%d" , &ch);
		
		if(ch == 1)
		{
			printf("Enter a element : ");
			int x;
			scanf("%d" , &x);
			enqueue(x);	
		}
		else if(ch == 2)
		{
			int element = dequeue();
			printf("Deleted element : %d" , element);
		}
		else if(ch == 3)
		{
			display();
		}
		else if(ch == 4)
		{
			printf("front : %d\nback : %d" , queue[front] , queue[(rear - 1)<0?(rear-1+size):(rear-1)]);	
		}	
		else if(ch == 5)
		{
			if(isempty())
			{
				printf("queue is empty");
			}
			else
			{
				printf("queue is not empty");
			}
		}
		else
		{
			printf("Invalid input");
		}
		printf("\n");
	}
	
	return 0;
}