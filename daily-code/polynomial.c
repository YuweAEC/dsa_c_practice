// write polynomial function on linked list 

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL;

void create(struct node **head)
{
    struct node *newnode, *temp;
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient and exponent: ");
        scanf("%d%d", &newnode->coeff, &newnode->exp);
        newnode->next = NULL;
        if (*head == NULL)
        {
            *head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void display(struct node *head)
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
}

