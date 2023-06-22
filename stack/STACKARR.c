#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int a[MAX],top;//Global Variable

void push(int x)
{
	if(top==MAX-1)
	{
		printf("Stack is Full. Can't Push\n");
	}
	else
	{
		top++;
		a[top]=x;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("The Stack is Empty. Can't pop");
	}
	else
	{
		printf("The popped element is %d",a[top]);
		top--;
	}
}
void show()
{
	int i;
	if(top==-1)
	{
		printf("Empty Stack. Nothing to display");
	}
	else
	{
		printf("The elements of the Stack are ");
		for(i=0;i<=top;i++)
			printf("%d ",a[i]);
	}
}
void menu()
{
	printf("\n");
	printf("\t\t\t PROGRAM ON Stack\n");
	printf("\t\t\t   1. PUSH\n");
	printf("\t\t\t   2. POP\n");
	printf("\t\t\t   3. DISPLAY\n");
	printf("\t\t\t   4. EXIT\n");
	printf("Enter your choice ");
}
int main()
{
	int ch,m;
	top=-1;
	for(;;)//Infinite Loop
	{
		menu();
		scanf("%d",&ch);//Accept choice
		switch(ch)
		{
			case 1:
				printf("\nEnter the number to push ");
				scanf("%d",&m);//"m" will be pushed
				push(m);
				break;
			case 2:
				pop();
				break;
			case 3:
				show();
				break;
			case 4:
				exit(0);//Exit from the program
			default:
				printf("\nInvalid choice \n");
				break;
		}//End of switch
	}//End of while loop
	return 0;
}

