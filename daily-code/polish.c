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
    }
    while (a == 'y');
}

void display()
{
    node *h;
    if (h == NULL)
    {
        printf("List is empty");
        return;
    }
    printf("The Elements in the list are:");
    while (h != NULL)
    {
        printf("%5d", h->data);
        h = h->next;
    }
}

void deleteElement()
{
    node *p, *k;
    p=search(x);
    if (p == NULL)
    {
        printf("Not found Element can't be deleted");
        return;
    }
    if(head==p)
        head=head->next;
    else
    {
        k=head;
        while(k->next !=p)
            k=k->next;
        k->next=p->next;
    }
    free(p);
}
