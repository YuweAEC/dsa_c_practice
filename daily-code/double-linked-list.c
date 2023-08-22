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

