// write polynomial function on linked list 

#include <stdio.h>
#include <stdlib.h>

struct node  // Structure of a node in a linked list 
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *head1 = NULL; // Global pointers to the heads of the two polynomials 
struct node *head2 = NULL; 
struct node *head3 = NULL;

void create(struct node **head)  // Function to create a polynomial 
{
    struct node *newnode, *temp;
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node)); // Create a new node 
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

void display(struct node *head) // Function to display a polynomial 
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->exp);  // Display the coefficient and exponent of each term 
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
}

void sumofPolynomials(struct node *head1, struct node *head2, struct node **head3) // Function to add two polynomials 
{
    struct node *temp1, *temp2, *temp3, *newnode;
    temp1 = head1;
    temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node)); // Create a new node 
        newnode->next = NULL;
        if (*head3 == NULL)
        {
            *head3 = newnode;
            temp3 = newnode;
        }
        else
        {
            temp3->next = newnode;
            temp3 = newnode;
        }
        if (temp1->exp == temp2->exp)
        {
            temp3->coeff = temp1->coeff + temp2->coeff; // Add the coefficients of the terms with the same exponent 
            temp3->exp = temp1->exp;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp)
        {
            temp3->coeff = temp1->coeff;
            temp3->exp = temp1->exp;
            temp1 = temp1->next;
        }
        else
        {
            temp3->coeff = temp2->coeff;
            temp3->exp = temp2->exp;
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node)); // Create a new node 
        newnode->next = NULL;
        temp3->next = newnode;
        temp3 = newnode;
        temp3->coeff = temp1->coeff;
        temp3->exp = temp1->exp;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        temp3->next = newnode;
        temp3 = newnode;
        temp3->coeff = temp2->coeff;
        temp3->exp = temp2->exp;
        temp2 = temp2->next;
    }
}

int main() // Main function 
{
    printf("Enter the first polynomial:\n");
    create(&head1);
    printf("Enter the second polynomial:\n");
    create(&head2);
    printf("The first polynomial is: ");
    display(head1);
    printf("\nThe second polynomial is: ");
    display(head2);
    sumofPolynomials(head1, head2, &head3);
    printf("\nThe sum of the two polynomials is: ");
    display(head3);
    return 0; // End of main function 
}
