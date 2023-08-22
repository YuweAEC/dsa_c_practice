#include<stdio.h>
#include<conio.h>
#include<stdlib.h> // for malloc function 


/* create double linked list add function*/

void add();
void display();
void delete();

struct node // structure declaration 
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL; // global variable declaration 

int main() // main function 
{
    int choice;
    while(1) // infinite loop 
    {
        printf("\n1. Add");
        printf("\n2. Display");
        printf("\n3. Delete");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) // menu driven switch case 
        {
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                delete();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}

void add() // add function 
{
    struct node *temp, *p; // local variable declaration
    temp = (struct node *)malloc(sizeof(struct node)); // dynamic memory allocation 
    printf("\nEnter data: ");
    scanf("%d", &temp->data); // read data 
    temp->next = NULL;
    temp->prev = NULL;
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        p = start;
        while(p->next != NULL) // traverse till last node 
        {
            p = p->next; // move to next node 
        }
        p->next = temp;
        temp->prev = p;
    }
}

void display()
{ 
    struct node *p; // local variable declaration 
    if(start == NULL) // check list is empty or not 
    {
        printf("\nList is empty");
    }
    else
    {
        p = start; // assign start address to p 
        while(p != NULL)
        {
            printf("\n%d", p->data);
            p = p->next;
        }
    }
}

void delete()
{
    struct node *p; // local variable declaration
    int num;
    printf("\nEnter data to delete: ");
    scanf("%d", &num);
    if(start == NULL)
    {
        printf("\nList is empty");
    }
    else if(start->data == num) // check data is found or not 
    {
        p = start; // assign start address to p
        start = start->next; // link next node 
        start->prev = NULL; // link previous node 
        free(p); // free memory 
    }
    else
    {
        p = start;
        while(p->next != NULL)
        {
            if(p->next->data == num) // check data is found or not
            {
                break;
            }
            p = p->next; // move to next node
        }
        if(p->next == NULL)
        {
            printf("\n%d not found", num);
        }
        else
        {
            struct node *temp; // local variable declaration
            temp = p->next;  // assign next node address to temp 
            p->next = temp->next; // link next node 
            temp->next->prev = p; // link previous node 
            free(temp); // free memory 
        }
    }
} // end of delete function 

