#include<stdio.h.>
#include<conio.h>

int main()
{
	int n;
	printf("ARRAY\n");
	
	printf("Enter size of array : ");
	scanf("%d" , &n);
	
	int array[n];
	
		printf("Operations : \n\n");
		printf("1 . insert a new element at index\n");
		printf("2 . delete a index\n");
		printf("3 . update a index\n");
		printf("4 . search for a element\n");
		printf("5 . sort the array\n");
		printf("6 . print the array\n");
		printf("7 . initialize all index to element x \n\n");
		
	while(true)
	{
	
		int choice = 0;
		printf("Enter a choice : ");
		scanf("%d" , &choice);
		
		if(choice == 1)
		{
			int element , index;
			printf("Enter a element : "); scanf("%d" , &element);
			printf("Enter a index   : "); scanf("%d" , &index);
			
			
			for(int i = n-1 ; i > index ; i --)
			{
				array[i] = array[i-1];
			}
			array[index] = element;
		}
		else if(choice == 2)
		{
			int index;
			printf("Enter a index   : "); scanf("%d" , &index);
			
			for(int i = index + 1 ; i < n-1 ; i ++)
			{
				array[i-1] = array[i];
			}
			array[n-1] = 0;
		}
		else if(choice == 3)
		{
			int element , index;
			printf("Enter a element : "); scanf("%d" , &element);
			printf("Enter a index   : "); scanf("%d" , &index);
			array[index] = element;
		}
		else if(choice == 4)
		{
			int element;
			int flag = 0;
			printf("Enter a element : "); scanf("%d" , &element);
			for(int i = 0 ;  i < n ; i ++)
			{
				if(array[i] == element)
				{
					flag = 1;
					printf("Element found at index = %d\n" , i);
				}
			}
			if(flag == 0)
			{
				printf("Element is not found !\n");
			}
			
		}
		else if(choice == 5)
		{
			// bubble sort
			
			for(int i = 0 ; i < n ; i ++)
			{
				for(int j = 0 ; j < n - i - 1 ; j ++)
				{
					if(array[j] > array[j+1]){
						int temp = array[j];
						array[j] = array[j+1];
						array[j+1] = temp;
					}
				}
			}
		}
		else if(choice == 6)
		{
			for(int i = 0 ; i < n ; i ++)
			{
				printf("%d ", array[i]);
			}
		}
		else
		{
			int x = 0;
			printf("Enter a element x: ");
			scanf("%d" , &x);
			for(int i = 0 ; i < n ; i ++) array[i] = x;
			
		}
		printf("\n\n");
	}
	return 0;
}