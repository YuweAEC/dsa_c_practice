#include <stdio.h>
#include<conio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Function to push a number onto the stack
void push(int num) 
{
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow! Cannot push %d.\n", num);
    } else {
        stack[++top] = num;
        printf("Pushed %d onto the stack.\n", num);
    }
}

// Main function
int main() 
{
    push(5);
    push(10);
    push(3);

    return 0;
}
