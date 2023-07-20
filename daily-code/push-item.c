#include<stdio.h>
#include<stdlib.h>
<<<<<<< HEAD
#define max 5

void push();
int stackArr[5], top=-1;

void display()    // defining the display function used in push and pop
{
    printf("\n List of the items in Stack \n");
    for(int i=top; i>=0; i--)
    printf("%d \n", stackArr[i]);
}

void main()
{
    int op, it;
    while (100) //Use an infinite loop to continuously read user input
    {
        printf("\n 1-PUSH 2-EXIT \n Enter the option \n\t");
=======
#define ms 5

void push();

void main()
{
    int op, it, v;
    while (100) //Use an infinite loop to continuously read user input
    {
        printf("\n 1-PUSH 2-POP 3-EXIT \n Enter the option");
>>>>>>> 4d282bf (feat: add push to push an item to stack)
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
<<<<<<< HEAD
    if (top==max)
=======
    if (t==ms)
>>>>>>> 4d282bf (feat: add push to push an item to stack)
    {
        printf("\n overflow");
    }
    else
    {
<<<<<<< HEAD
        top=top+1;
        stackArr[top]=x;    //assigning item on the top of the stack
    }
    display();
=======
        t=t+1;
        s[t]=x;    //assigning item on the top of the stack
    }
>>>>>>> 4d282bf (feat: add push to push an item to stack)
}
