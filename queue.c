#include<stdio.h>
#include<conio.h>

int main()
{
	int n;
	printf("Enter the number n : ");
	scanf("%d", &n);
	int queue[n];
	int front , rear;
	front = 0;
	rear = -1;
	printf("Operations \n");
	printf("1. enqueue\n2. dequeue\n3. print queue\n");
	
	while(1)
	{
		
		printf("Enter your choice : ");
		int choice = 0;
		scanf("%d" , &choice);
		
		if(choice == 1)
		{
			int x;
			printf("Enter element : ");
			scanf("%d" , &x);
			rear++;
			rear = rear%n;
			queue[rear] = x;
		}
		else if(choice == 2){
			front++;
			front = front%n;
		}
		else{
			if(rear < front)
			{
				for(int i = front ; i <= rear+n ; i ++)
				{
					printf("%d ",queue[i%n]);
				}
			}
			for(int i = front ; i <= rear ; i ++ )
			{
				printf("%d ",queue[i%n]);
			}
		}
		
		printf("\n");
		printf("front = %d rear = %d \n",front,rear);
	}
	return 0;
}