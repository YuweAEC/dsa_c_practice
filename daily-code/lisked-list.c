#include <stdio.h>
#include <stdlib.h> // Include for malloc

struct Node // Declaration of structure that defines list entries
{
    int number; // Data item 
    struct Node* next; // Pointer to the next node (list entry)
}; // Note the semicolon at the end of the structure declaration 

int main()
{
    int i, count = 0;  // i is the input number, count is the number of nodes in the list 
    struct Node* start = NULL; // Pointer to the first node (header node) 
    struct Node* node = NULL;  // Pointer to the current node

    // Create the header node
    start = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the header node 
    if (start == NULL) // Check if memory allocation failed 
    {
        printf("Memory allocation failed.\n"); // Display error message and exit
        return 1;
    }
    start->next = NULL; // Set next of the header node to NULL
    node = start;       // Initialize node with the header node

    printf("\n * Single linked list\n\n");

    for (;;)
    {
        printf("%2d. Enter the number (-999 to exit): ", ++count); // Display the serial number and prompt for input 
        scanf("%d", &i);
        if (i == -999)
            break; // Exit the loop if -999 is entered 

        // Allocate memory for the new node
        node->next = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node 
        if (node->next == NULL) // Check if memory allocation failed 
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        node = node->next;   // Move to the new node
        node->number = i;    // Set the value for the new node
        node->next = NULL;   // Set the next of the new node to NULL
    }

    printf("\n\n * Currently, the list is as follows:\n\n");

    for (node = start->next, count = 0; node; node = node->next) // Traverse the list and display the contents of each node 
    {
        printf("\t %2d -> %5d\n", ++count, node->number); // Display the serial number and the value of the node 
    }

    if (!count) // Check if the list is empty
        printf("\t Empty\n");

    printf("\n * Total number of nodes: %d\n", count);

    // Free the allocated memory
    node = start; 
    while (node) // Traverse the list and free the memory allocated for each node
    {
        struct Node* temp = node; // Store the address of the current node in a temporary variable 
        node = node->next; // Move to the next node 
        free(temp); // Free the memory allocated for the current node
    }

    return 0;
}
