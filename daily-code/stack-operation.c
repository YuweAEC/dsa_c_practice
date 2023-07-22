#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 4

void push();
int pop();
int stackArr[5], top=-1;


void main()
{
    int op, it, v;
    while (true) //Use an infinite loop to continuously read user input
    {
        printf("\n 1-PUSH \n 2-POP \n 3-Veiw-stack \n 4-EXIT \n Enter the option: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:     /* constant-expression */
            printf("\nEnter the item to push: ");
            scanf("%d", &it);
            push(it);   /* invoke or calling the push function */
            break;
        case 2:
            v=pop();   /* invoke or calling the pop function */
            if (v>0)
            {
                printf("\n%d is popped from the stack", v);
            }
            break;
        case 3:
            printf("\n Stack Contains:  ");
            for (int i = 0; i <= top; i++)
            {
                printf("\n%d", stackArr[i]);
            }
            break;
        case 4:
            exit(0);
        }
    }
}

void push(int x)    // push function defination
{
    if (top==max)
    {
        printf("\n overflow");
    }
    else
    {
        top=top+1;
        stackArr[top]=x;    //assigning item on the top of the stack
    }
}

int pop()     // pop function defination
{
    if (top<0)
    {
        printf("\n Underflow ");
    }
    else
    {
        int v=stackArr[top];     //assiging value to pop form the stack
        top=top-1;      //decrease top by 1
        return v;    
    }
}
