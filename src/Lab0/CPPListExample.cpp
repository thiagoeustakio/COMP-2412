#include <iostream>

// Define a class for a linked list node
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

int main() {
    // Declare instances of the Node class
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    // Link the nodes
    head->next = second;
    second->next = third;

    // Print the data in the linked list
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
    
    // Free allocated memory
    delete head;
    delete second;
    delete third;

    return 0;
}
