#include<stdio.h>
#include<conio.h>
// program to perform operations on polish notation




typedef struct node
{
    int data;
    struct node *next;
} node;

int main()
{
    int ch;
    while (1)
    {
        printf("\n1.Create\n2.Display\n3.Delete\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createLindedList();
            break;
        case 2:
            display();
            break;
        case 3:
            deleteElement();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}

void createLindedList()
{
    node *h, *p;
    int x;
    printf("Enter the data for the node");
    scanf("%d", &x);
    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    if (h == NULL)
    {
        h = p;
        return;
    }
    while (h->next != NULL)
        h = h->next;
    h->next = p;
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
    node *h, *p;
    int x;
    if (h == NULL)
    {
        printf("List is empty");
        return;
    }
    printf("Enter the element to be deleted");
    scanf("%d", &x);
    if (h->data == x)
    {
        p = h;
        h = h->next;
        free(p);
        return;
    }
    while (h->next != NULL)
    {
        if (h->next->data == x)
        {
            p = h->next;
            h->next = p->next;
            free(p);
            return;
        }
        h = h->next;
    }
    printf("Element not found");
}