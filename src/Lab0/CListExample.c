#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Define a new type 'Node' based on the structure
typedef struct Node Node;

int main() {
    // Declare variables of the new type
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // Allocate memory for the nodes
    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));

    // Assign data and link nodes
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Print the data in the linked list
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Free allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}
