#include<stdio.h>
#include<conio.h>
#include<stdlib.h> // for malloc function 


/* create double linked list add function*/

void add();
void display();
void delete();
void addBefore();
void addAfter();
void count();
void deletebyPosition();
void reverse();\

struct node // structure declaration 
{
    int data;
    struct node *next;
    struct node *prev;
};          

struct node *start = NULL; // global variable declaration 

int main()
{
    int ch;
    while(1) // infinite loop 
    {
        printf("\n1.Add\n2.Display\n3.Delete\n4.Add Before\n5.Add After\n6.Count\n7.Delete by position\n8.Reverse\n9.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                add(); // invoke add function 
                break;
            case 2:
                display(); // invoke display function 
                break;
            case 3:
                delete(); // invoke delete function 
                break;
            case 4:
                addBefore(); // invoke addBefore function 
                break;
            case 5:
                addAfter(); // invoke addAfter function 
                break;
            case 6:
                count(); // invoke count function 
                break;
            case 7:
                deletebyPosition(); // invoke deletebyPosition function 
                break;
            case 8:
                reverse(); // invoke reverse function 
                break;
            case 9:
                exit(0); // exit from the program 
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

void addBefore()
{
    struct node *temp, *p; // local variable declaration
    int num;
    temp = (struct node *)malloc(sizeof(struct node)); // dynamic memory allocation 
    printf("\nEnter data: ");
    scanf("%d", &temp->data); // read data 
    temp->next = NULL;
    temp->prev = NULL;
    printf("\nEnter data before which node to insert: ");
    scanf("%d", &num);
    if(start == NULL)
    {
        printf("\nList is empty");
    }
    else if(start->data == num) // check data is found or not 
    {
        temp->next = start; // link next node 
        start->prev = temp; // link previous node 
        start = temp;
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
            temp->next = p->next; // link next node 
            temp->prev = p; // link previous node 
            p->next->prev = temp; // link previous node 
            p->next = temp; // link next node 
        }
    }
} // end of addBefore function

void addAfter()
{
    struct node *temp, *p; // local variable declaration
    int num;
    temp = (struct node *)malloc(sizeof(struct node)); // dynamic memory allocation 
    printf("\nEnter data: ");
    scanf("%d", &temp->data); // read data 
    temp->next = NULL;
    temp->prev = NULL;
    printf("\nEnter data after which node to insert: ");
    scanf("%d", &num);
    if(start == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        p = start;
        while(p != NULL)
        {
            if(p->data == num) // check data is found or not 
            {
                break;
            }
            p = p->next; // move to next node 
        }
        if(p == NULL)
        {
            printf("\n%d not found", num);
        }
        else
        {
            temp->next = p->next; // link next node 
            temp->prev = p; // link previous node 
            if(p->next != NULL)
            {
                p->next->prev = temp; // link previous node 
            }
            p->next = temp; // link next node 
        }
    }
}

int count() // to count total number of nodes
{
    struct node *p; // local variable declaration
    int c = 0;
    if(start == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        p = start;
        while(p != NULL)
        {
            c++;
            p = p->next;
        }
        printf("\nTotal nodes: %d", c);
    }
}

void deletebyPosition() // to delete node by position
{
    int i, c;
    c=count();
    struct node *lastNode, *temp; // local variable declaration
    if(p<1 || p>c)
    {
        printf("Invali  d position\n");
        return;
    }
    if(p==1)
    {
        lastNode=start;
        start=start->next;
        free(lastNode);
    }
    else
    {
        lastNode=start;
        temp=lastNode->next;
    }
}

void reverse() // to reverse the list 
{
    struct node *lastNode, *prevNode, *nextNode; // local variable declaration
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(start->next==NULL)
    {
        return;
    }
    prevNode=NULL;
    lastNode=start;
    nextNode=start->next;
    while(nextNode!=NULL)
    {
        lastNode->next=prevNode;
        prevNode=lastNode;
        lastNode=nextNode;
        nextNode=nextNode->next;
    }
    lastNode->next=prevNode;
    start=lastNode;
}

