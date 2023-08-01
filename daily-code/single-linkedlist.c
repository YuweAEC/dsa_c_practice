#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


// Define the node structure
typedef struct Node // Declaration of structure that defines list entries 
{
    int n;
    struct Node* next; // Pointer to the next node (list entry)
} node;

void create()
{
    int x;
    char a;
    node *t, *h, *head=NULL;
    do
    {
        printf("Enter the value: ");
        scanf("%d", &x);
        t=(node*)malloc(sizeof(node));
        t->n=x;
        t->next=NULL;
        if (head==NULL)
        {
            head=t;
            h=t;
        }
        else
        {
            h->next=t;
            h=t;
        }
        printf("Do you want to continue? (y/n): ");
        getchar();
        a=getchar();
    } while (a=='y' || a=='Y');
    display(head);
}
