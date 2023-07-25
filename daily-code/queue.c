#include<stdio.h>
#define MAX 5 

void add(int x);
void deletion(); 
int a[MAX],front,rare; 

void add(int x) 
{
	if(rare==MAX-1) 		
	{
		printf("THE QUEUE IS FULL");
		return;
	}
	if(front==-1)
		front=rare=0; 
	else  
		rare++;
	a[rare]=x;
}
	
void deletion() 
{
	if(front==-1)
	{
		printf("Q is Empty, Can't delete");
		return;
	}
	printf("the deleted element is %d",a[front]); 
	if(front==rare)
		front=rare=-1; 
	else
		front++;
}

void main()	
{
	int ch,x;
	front=rare=-1; 
	do
	{
		printf("\n1. Add\n2. Delete\n3. List\n4. Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element to be added: "); 		
					scanf("%d",&x);
					add(x); 
					break;
			case 2: deletion(); 
					break;
			case 3: for(int i=front;i<=rare;i++)  	
					{
						printf("%d\t",a[i]); 
					}
			case 4: break;
			default: printf("Invalid choice")
		}
	}while(ch!=3); 
}
