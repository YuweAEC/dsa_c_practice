#include<stdio.h>
#define MAX 5

int a[MAX],f,r;

void add(int x)
{
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