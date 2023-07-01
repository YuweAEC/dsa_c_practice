// WAP to Implement Stack
#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int arr[MAX], top; // MAX is size of Stack, top is Index Number

// 1. Push function
void push()
{
    if (top == MAX - 1)
    {
        printf("The Stack is Full, No more elements can be pushed");
    }
    else
    {
        int x; // x is elememt to be pushed
        printf("Enter the Element to be Pushed: ");
        scanf("%d", &x);
        top++;
        arr[top] = x;
        printf("Element Successfully Pushed");
    }
}

// 2. Pop function
void pop()
{
    if (top == -1)
    {
        printf("No, Elements in Stack to pop");
    }
    else
    {
        printf("Popped Element is: %d", arr[top]);
        top--;
    }
}

// 3. view function
void view()
{
    int i;
    if (top == -1)
    {
        printf("There are no elements in Stack");
    }

    else
    {
        for (i = 0; i <= top; i++)
        {
            printf("%d\n", arr[i]);
        }
    }
}

// 4. exit function
void Exit()
{
    exit(0);
}

// menu
void menu()
{
    printf("\n\n1. PUSH a Value\n");
    printf("2. POP a Value\n");
    printf("3. View an Element of Stack\n");
    printf("4. Exit\n");
    printf("Enter your Choice: ");
}

// main starts here
int main()
{
    top = -1;

    while (1)
    {
        int choice;
        menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            view();
            break;

        case 4:
            Exit();
            break;

        default:
            printf("Input is Invalid");
        }
    }
}

