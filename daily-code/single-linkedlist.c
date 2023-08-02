#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


// Define the node structure
typedef struct node // Declaration of structure that defines list entries 
{
    int n;
    struct node* next; // Pointer to the next node (list entry)
} node;

void create()
{
    int x;
    char a;
    node *t, *h, *head=NULL;
    do
    {
        printf("Enter the value: ");
        scanf("\n%d", &x);
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
    display(head); // Call the display function to display the list elements 
}

int count()
{
    int c=0;
    node* head=NULL;
    while(head!=NULL)
    {
        c++;
        head=head->next;
    }
    return c;
}

void display()
{
    node *head;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("The elements are: ");
    while(head!=NULL)
    {
        printf("%5d", head->n);
        head=head->next;
    }
    printf("\n");
}

int main()
{
    create();
    count();
    return 0;
}