#include<stdio.h>
#include<conio.h>

int main()
{
	printf("STACK USING ARRAY \n");
	int n;
	printf("Enter size of stack : ");
	scanf("%d" , &n);
	
	int top = 0;
	int stack[n];
	
	printf("\n");
	printf("Operations in stack : \n\n");
	printf("1 . PUSH\n");	
	printf("2 . POP \n");
	printf("3 . PRINT STACK \n\n");
	
	while(1)
	{
			
		int choice = 0;
		printf("Enter choice : "); scanf("%d" , &choice);
		
		if(choice == 1)
		{
			// push
			if(top == n)
			{
				printf("OVERFLOW !");
			}
			else{
				int element;
				printf("Enter element : "); scanf("%d" , &element);
				stack[top] = element;
				top ++;
			}
		}
		else if(choice == 2)
		{
			// pop
			if(top == 0)
			{
				printf("UNDERFLOW !\n");
			}
			else
			{				
				int element = stack[top - 1];
				stack[top]= 0;
				top -- ;
				printf("deleted element : %d  \n" , element);
			}
		}
		else if(choice == 3)
		{
			// view all elements
			printf("\n");
			for(int i = top-1 ; i >= 0 ; i --)
			{
				printf("%d " , stack[i]);
			}
			
		}
		else{
			printf("invalid choice , please try again \n");
			break;
		}
		printf("\n\n");
	}
	
	return 0;
}