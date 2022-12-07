#include<stdio.h>
#include<stdlib.h>
#define ARRSIZE 100

// HASH TABLE
// linked list implementation


struct node 
{
	int data;
	struct node *next;
};

struct node *hash_table[ARRSIZE];



int hash_function(int key)
{
	// implement a hash function from integer -> integer
	// minimize collision
	
	int f = ((key/1007 + key)*(9089/key));
	return f%ARRSIZE;
}

void insert(int key)
{
	int hashval = hash_function(key);
	
	struct node *newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data = key;
	newnode->next = NULL;	
	
	struct node *head = hash_table[hashval];
	
	if(head != NULL)
	{
		newnode->next = head;
	}

	hash_table[hashval] = newnode;

}

void search(int key)
{
	int index = hash_function(key);
	struct node *head = hash_table[index];
	
	int flag = 0;
	while(head!=NULL)
	{
		if(head -> data == key)
		{
			printf("Search found !\n");
			flag = 1;
		}
		head = head->next;
	}
	
	if(flag == 0)
	{
		printf("Key not found !\n");
	}
}


void main()
{
	insert(101);
	insert(102);
	insert(103);
	insert(104);
	
	search(101);
	search(102);
	search(103);
	search(104);
	search(105);	
		
}