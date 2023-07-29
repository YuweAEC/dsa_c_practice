#include<stdio.h>
#include<conio.h>

void createLindedList()
{
    int x ;
    char a;
    node *t, *h;
    do
    {
        printf("Enter the element to be inserted:");
        scanf("%d", &x);
        t = (node *x)malloc(sizeof(node));
        t->data = x;
        t->next = NULL;
        if (h == NULL)
        {
            head=t;
            h = t;
        }
        else
        {
            h->next = t;
            h = t;
        }
        printf("Do you want to insert more elements(y/n):");
        a=getchar();
    } while (a == 'y'|| a=='Y');
}
