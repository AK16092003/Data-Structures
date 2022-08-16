// postfix expression

#include<stdio.h>
#include<conio.h>
#define max_sz 100

int stack[max_sz];
int top = 0;

void push(int x)
{
	if(top == max_sz) return;
	stack[top] = x;
	top ++;
}

int pop()
{
	if(top == 0) return -1;
	top--;
	return stack[top];
}


int length(char *a)
{
	int i = 0;
	while(*(a + i) != '\0') i++;
	return i;
}

void print_stack()
{
	for(int i = 0 ; i < top ; i ++) printf("%d " , stack[i]);
	printf("\n");
}

int main()
{
	char a[100];
	printf("Enter expression : ");
	scanf("%s" , a);
	int n = length(a);
	printf("length = %d \n" , n);
	
	for(int i = 0 ; i < n ; i ++)
	{
		if('0' <= a[i]  && a[i] <= '9')
		{
			push(a[i] - '0');	
		} 
		else
		{
			int new_element = 0;
			int right= pop();
			int left = pop();
			if(a[i] == '+') new_element = left + right;
			if(a[i] == '-') new_element = left - right;
			if(a[i] == '*') new_element = left * right;
			if(a[i] == '/') new_element = left / right;
			push(new_element);
		}
		printf("index = %d , stack status : " , i);
		print_stack();
	}
	printf("\n");
	printf("FINAL ANSWER  = %d " , pop());
	printf("\n");
	
	return 0;
}