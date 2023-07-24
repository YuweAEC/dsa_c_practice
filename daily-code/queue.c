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
