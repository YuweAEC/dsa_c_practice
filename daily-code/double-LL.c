#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* start = NULL;

void add();
void deleteNode();

int main() 
{
    int ch;
    while (1) {
        printf("\n1. Add\n2. Delete\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                add();
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}

void add() 
{
    struct node* temp, * p;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (start == NULL) {
        start = temp;
    }
    else {
        p = start;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
}
