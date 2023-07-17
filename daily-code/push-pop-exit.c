#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#define ms 4

void push();
int pop();
int s[5], t=-1;

void display()    // defining the display function used in push and pop
{
    printf("\n Stack Contains \n");
    for(int i=t; i>=0; i--)
    printf("%d \n", s[i]);
}

void main()
{
    int op, it, v;
    printf("\n 1-PUSH 2-POP 3-EXIT \n Enter the option");
    scanf("%d", &op);
    switch (op)
    {
    case 1:     /* constant-expression */
        printf("Enter the item to push:");
        scanf("%d,", &it);
        push(it);   /* invoke or calling the push function */
        break;
    case 2:
        v=pop();   /* invoke or calling the pop function */
        if (v>0)
        {
            printf(" %d is pop from the stack", v);
        }
        break;
    case 3:
        exit(0);
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
    display();
}

int pop()     // pop function defination
{
    if (t<0)
    {
        printf("\n Underflow");
    }
    else
    {
        int v=s[t];     //assiging value to pop form the stack
        t=t-1;      //decrease top by 1
        display();
        return v;    
    }
}

