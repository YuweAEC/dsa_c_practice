#include<stdio.h>
#define MAX 5 //size of the queue

void add(int x);
void deletion(); 
int queue[MAX],front,rear;  //global declaration of queue

void add(int x) 
{
	if(rear==MAX-1) //check if queue is full 		
	{
		printf("THE QUEUE IS FULL");
		return;
	}
	if(front==-1) //check if queue is empty
		front=rear=0; 
	else  
		rear++;
	queue[rear]=x;
}
	
void deletion() 
{
	if(front==-1) //check if queue is empty
	{
		printf("Q is Empty, Can't delete");
		return;
	}
	printf("the deleted element is %d",queue[front]);  
	if(front==rear)   //	check if only one element is present in queue
		front=rear=-1; 
	else
		front++;
}

void main()	
{
	int ch,x;  //ch is choice
	front=rear=-1;  //initially queue is empty
	do
	{
		printf("\n1. Add\n2. Delete\n3. List\n4. Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element to be added: "); 		
					scanf("%d",&x);
					add(x); //call add function
					break;
			case 2: deletion();  //call delete function
					break;
			case 3: for(int i=front;i<=rear;i++)  	//display the queue
					{
						printf("%d\t",queue[i]); 
					}
			case 4: break;
			default: printf("Invalid choice");
		}
	}while(ch!=3); //end of do while loop and end of program (exit)
}
