// program to element circular queue
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5

void add(int x);
void deletion();
void display();

void add(int x)
{
    int r, f , a[MAX];
    if(r==MAX-1)
    {
        printf("THE QUEUE IS FULL");
        return ;
    }

    if(f==-1)
        f=r=0;
    
    else
        r++;
    a[r]=x;
}

void deletion()
{
    int r, f , a[MAX];
    if(f==-1)
    {
        printf("Q is EMpty, Can't delete");
        return ;
    }
    
    printf("the deleted element is %d", a[f]);
    
    if(f==r)
        f=f=-1;
    
    else
        f++;
}

