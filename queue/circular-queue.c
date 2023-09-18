#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void add(int x);
void deletion();
void display();

int f = -1, r = -1; // Initialize front and rear indices
int a[MAX]; // Queue array

int main() {
    int ch, x;
    while (1) {
        printf("\n1. Add");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the element to be added: ");
                scanf("%d", &x);
                add(x);
                break;
            case 2:
                deletion();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}

void add(int x) {
    if ((r == MAX - 1 && f == 0) || (r + 1 == f)) {
        printf("THE QUEUE IS FULL");
        return;
    }

    if (f == -1)
        f = r = 0;
    else if (r == MAX - 1)
        r = 0;
    else
        r++;

    a[r] = x;
}

void deletion() {
    if (f == -1) {
        printf("Queue is Empty, Can't delete");
        return;
    }

    printf("The deleted element is %d", a[f]);

    if (f == r)
        f = r = -1;
    else if (f == MAX - 1)
        f = 0;
    else
        f++;
}

void display() {
    if (f == -1) {
        printf("Queue is Empty, Can't display");
        return;
    }

    int i = f;
    do {
        printf("%d ", a[i]);
        if (i == r && r != MAX - 1)
            break;
        if (i == MAX - 1)
            i = 0;
        else
            i++;
    } while (i != (r + 1) % MAX);
}
