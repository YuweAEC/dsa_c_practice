#include<stdio.h>
#include<conio.h>

/* create double linked list add function*/

void add();
void display();
void delete();

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;

int main()
{
    int choice;
    while(1)
    {
        printf("\n1. Add");
        printf("\n2. Display");
        printf("\n3. Delete");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
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

void add()
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        p = start;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
}
