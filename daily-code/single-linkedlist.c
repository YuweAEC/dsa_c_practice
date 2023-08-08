#include<stdio.h> // To use printf() and scanf() functions
#include<stdlib.h> // To use malloc() function 


// Define the node structure
typedef struct linkedListNode // Declaration of structure that defines list entries 
{
    int n; // Data element of the node (list entry) 
    struct linkedListNode* next; // Pointer to the next node (list entry)
} node;

void create(); // To create the list
void display(); // To display the list
void deletebyPosition(); // To delete a node from the list by position
void reverse(); // To reverse the list
void addAfter(); // To add a node after a given position
void addBefore(); // To add a node before a given position
int count(); // To count the number of nodes in the list
void delete(); // To delete a node from the list by value
node *head=NULL; // Declare a pointer of type node to point to the first node of the list

    
int main()
{   
    create(); // To create the list 
    count(); // To count the number of nodes in the list
    deletebyPosition(); // To delete a node from the list by position
    reverse(); // To reverse the list
    addAfter(); // To add a node after a given position
    addBefore(); // To add a node before a given position
    delete(); // To delete a node from the list by value
    display(); // To display the list
    return 0; // Return 0 to operating system
}

void create() // To create the list 
{
    int x; // Declare a variable to store the value to be stored in the list
    char a; // Declare a variable to store the choice of the user to continue or not
    node *newNode, *lastNode; // Declare two pointers of type node to point to the first and last nodes of the list
    do
    {
        printf("Enter the value: ");
        scanf("\n%d", &x); // x is the value to be stored in the list
        newNode=(node*)malloc(sizeof(node));
        newNode->n=x; // Store the value in the node
        newNode->next=NULL; // Make the next pointer of the new node as NULL
        if (head==NULL)
        {
            head=newNode; // Make the new node as the first node of the list
            lastNode=newNode; // Make the new node as the last node of the list
        }
        else
        {
            lastNode->next=newNode; // Link the new node to the last node of the list
            lastNode=newNode; // Make the new node as the last node of the list
        }
        printf("Do you want to continue? (y/n): ");
        a=getchar(); // To read the character entered by the user after the value is entered
    } while (a=='y' || a=='Y'); 
}

void delete()
{
    int x;
    node *lastNode, *temp;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Enter the value: ");
    scanf("%d", &x);
    if(head->n==x)
    {
        lastNode=head;
        head=head->next;
        free(lastNode);
        return;
    }
    temp=head;
    while(temp->next!=NULL)
    {
        if(temp->next->n==x)
        {
            lastNode=temp->next;
            temp->next=temp->next->next;
            free(lastNode);
            return;
        }
        temp=temp->next;
    }
    printf("Element not found\n");
}

int count()
{
    node* lastNode=head; // Declare a pointer of type node to point to the first node of the list 
    int c=0; // Declare a variable to store the number of nodes in the list 
    while(lastNode!=NULL) // Traverse the list till the last node is reached    
    { 
        c++; // Increment the value of c by 1 
        lastNode=lastNode->next; // Make lastNode point to the next noede of the list 
    }
    return c; // Return the value of c 
}

void display()
{
    node *lastNode; // Declare a pointer of type node to point to the first node of the list
    if(head==NULL) // Check if the list is empty 
    {
        printf("List is empty\n");
        return;
    }
    printf("The elements are: ");
    lastNode=head; // Make the lastNode pointer point to the first node of the list 
    while(lastNode!=NULL) // Traverse the list till the last node  is reached 
    {
        printf("%5d", lastNode->n); // Print the value of the node pointed to by lastNode 
        lastNode=lastNode->next; // Make lastNode point to the next node of the list 
    }
}

void deletebyPosition()
{
    int i, c;
    c=count();
    node *lastNode, *temp;
    if(p<1 || p>c)
    {
        printf("Invalid position\n");
        return;
    }
    if(p==1)
    {
        lastNode=head;
        head=head->next;
        free(lastNode);
    }
    else
    {
        lastNode=head;
        temp=lastNode->next;
    }
}

void reverse()
{
    node *lastNode, *prevNode, *nextNode;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(head->next==NULL)
    {
        return;
    }
    prevNode=NULL;
    lastNode=head;
    nextNode=head->next;
    while(nextNode!=NULL)
    {
        lastNode->next=prevNode;
        prevNode=lastNode;
        lastNode=nextNode;
        nextNode=nextNode->next;
    }
    lastNode->next=prevNode;
    head=lastNode;
}

void addAfter()
{
    int x, p, c=0;
    node *lastNode, *newNode;
    printf("Enter the value: ");
    scanf("%d", &x);
    printf("Enter the position: ");
    scanf("%d", &p);
    c=count();
    if(p<1 || p>c)
    {
        printf("Invalid position\n");
        return;
    }
    newNode=(node*)malloc(sizeof(node));
    newNode->n=x;
    newNode->next=NULL;
    if(p==1)
    {
        newNode->next=head;
        head=newNode;
    }
    else
    {
        lastNode=head;
        for(i=1; i<p; i++)
        {
            lastNode=lastNode->next;
        }
        newNode->next=lastNode->next;
        lastNode->next=newNode;
    }
}

void addBefore()
{
    int x, p, c=0;
    node *lastNode, *newNode, *temp;
    printf("Enter the value: ");
    scanf("%d", &x);
    printf("Enter the position: ");
    scanf("%d", &p);
    c=count();
    if(p<1 || p>c)
    {
        printf("Invalid position\n");
        return;
    }
    newNode=(node*)malloc(sizeof(node));
    newNode->n=x;
    newNode->next=NULL;
    if(p==1)
    {
        newNode->next=head;
        head=newNode;
    }
    else
    {
        lastNode=head;
        for(i=1; i<p; i++)
        {
            temp=lastNode;
            lastNode=lastNode->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}

void deletePosition()
{
    int p, c=0;
    node *lastNode, *temp;
    printf("Enter the position: ");
    scanf("%d", &p);
    c=count();
    if(p<1 || p>c)
    {
        printf("Invalid position\n");
        return;
    }
    if(p==1)
    {
        lastNode=head;
        head=head->next;
        free(lastNode);
    }
    else
    {
        lastNode=head;
        for(i=1; i<p; i++)
        {
            temp=lastNode;
            lastNode=lastNode->next;
        }
        temp->next=lastNode->next;
        free(lastNode);
    }
}


node *search(int x) // Function to search for a node with a given value 
{
    node *lastNode;
    if(head==NULL) // Check if the list is empty
    {
        printf("List is empty\n");
        return NULL;
    }
    lastNode=head;
    while(lastNode!=NULL)
    {
        if(lastNode->n==x)
        {
            return lastNode;
        }
        lastNode=lastNode->next; // Make lastNode point to the next node of the list
    }
    return NULL;
}

void addByPosition()
{
    int x, p, c=0;
    node *lastNode, *newNode;
    printf("Enter the value: ");
    scanf("%d", &x);
    printf("Enter the position: ");
    scanf("%d", &p);
    c=count();
    if(p<1 || p>c)
    {
        printf("Invalid position\n");
        return;
    }
    newNode=(node*)malloc(sizeof(node));
    newNode->n=x;
    newNode->next=NULL;
    if(p==1)
    {
        newNode->next=head;
        head=newNode;
    }
    else
    {
        lastNode=head;
        for(i=1; i<p-1; i++)
        {
            lastNode=lastNode->next;
        }
        newNode->next=lastNode->next;
        lastNode->next=newNode;
    }
}
