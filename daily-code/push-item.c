#include<stdio.h>
#include<stdlib.h>
#define max 5

void push();
int stackArr[5], top=-1;

void display()    // defining the display function used in push and pop
{
    printf("\n Stack Contains \n");
    for(int i=t; i>=0; i--)
    printf("%d \n", sstackArr[i]);
}

void main()
{
    int op, it;
    while (100) //Use an infinite loop to continuously read user input
    {
        printf("\n 1-PUSH 2-EXIT \n Enter the option");
        scanf("%d", &op);
        switch (op)
        {
        case 1:     /* constant-expression */
            printf("Enter the item to push:");
            scanf("%d,", &it);
            push(it);   /* invoke or calling the push function */
            break;
        case 2:
            exit(0);
        }
    }
}

void push(int x)    // push function defination
{
    if (t==max)
    {
        printf("\n overflow");
    }
    else
    {
        top=top+1;
        stackArr[top]=x;    //assigning item on the top of the stack
    }
    display();
}
