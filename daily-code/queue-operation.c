#include<stdio.h>
#define MAX 5 //size of the queue

void add(int storeElement);
void delete(); 
int queue[MAX],front,rear;  //global declaration of queue

void add(int storeElement) 
{
	if(rear==MAX-1) //check if queue is full 		
	{
		printf("THE QUEUE IS FULL");
		return;
	}
	if(front==-1) //check if queue is empty
		front=rear=0; //if empty then make front and rear as 0
	else 
		rear++; //if not empty then increment rear
	queue[rear]=storeElement;
}
	
void delete() 
{
	if(front==-1) //check if queue is empty
	{
		printf("Q is Empty, Can't delete");
		return;
	}
	printf("the deleted element is %d",queue[front]);  
	if(front==rear)   //	check if only one element is present in queue
		front=rear=-1; 	//if yes then make front and rear as -1
	else
		front++; //if no then increment front
}

void main()	
{
	int choice,storeElement;  //choice is choice
	front=rear=-1;  //initially queue is empty
	do
	{
		printf("\n1. Add\n2. Delete\n3. List\n4. Exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the element you want to add:  "); 		
					scanf("%d",&storeElement); //read the element to be added
					add(storeElement); //call add function
					break;
			case 2: delete();  //call delete function
					break;
			case 3: for(int i=front;i<=rear;i++)  	//display the queue
					{
						printf("%d\t",queue[i]); 
					}
			case 4: break;
			default: printf("Invalid choice");
		}
	}while(choice!=3); //end of do while loop and end of program (exit)
}
