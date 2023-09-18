// program to element circular queue
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5

void add(int x);
void deletion();
void display();

int main()
{
    int ch, x;
    while(1)
    {
        printf("\n1. Add");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the element to be added: ");
                scanf("%d", &x);
                add(x);
                break;
            case 2:
                deletion();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}

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

void display()
{
    int r, f , a[MAX];
    if(f==-1)
    {
        printf("Q is EMpty, Can't delete");
        return ;
    }
    
    for(int i=f; i<=r; i++)
        printf("%d", a[i]);
}

