#include <stdio.h>
#include <stdlib.h> // Include for malloc

struct Node // Declaration of structure that defines list entries
{
    int number;
    struct Node* next;
};

int main()
{
    int i, count = 0;
    struct Node* start = NULL; // Pointer to the first node (header node)
    struct Node* node = NULL;  // Pointer to the current node

    // Create the header node
    start = (struct Node*)malloc(sizeof(struct Node));
    if (start == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    start->next = NULL; // Set next of the header node to NULL
    node = start;       // Initialize node with the header node

    printf("\n * Single linked list\n\n");

    for (;;)
    {
        printf("%2d. Enter the number (-999 to exit): ", ++count);
        scanf("%d", &i);
        if (i == -999)
            break;

        // Allocate memory for the new node
        node->next = (struct Node*)malloc(sizeof(struct Node));
        if (node->next == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        node = node->next;   // Move to the new node
        node->number = i;    // Set the value for the new node
        node->next = NULL;   // Set the next of the new node to NULL
    }

    printf("\n\n * Currently, the list is as follows:\n\n");

    for (node = start->next, count = 0; node; node = node->next)
    {
        printf("\t %2d -> %5d\n", ++count, node->number);
    }

    if (!count)
        printf("\t Empty\n");

    printf("\n * Total number of nodes: %d\n", count);

    // Free the allocated memory
    node = start;
    while (node)
    {
        struct Node* temp = node;
        node = node->next;
        free(temp);
    }

    return 0;
}
