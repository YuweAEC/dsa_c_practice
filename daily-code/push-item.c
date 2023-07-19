#include<stdio.h>
#include<stdlib.h>
#define ms 5

void push();
int s[5], t=-1;

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
    if (t==ms)
    {
        printf("\n overflow");
    }
    else
    {
        t=t+1;
        s[t]=x;    //assigning item on the top of the stack
    }
}
