#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    return new_node;
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (head == NULL) {
        return new_node;
    }
    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return head;
}

// Function to insert a node at a given position
struct Node* insertAtPosition(struct Node* head, int position, int new_data) {
    if (position < 1) {
        printf("Position should be >= 1.\n");
        return head;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    if (position == 1) {
        new_node->next = head;
        return new_node;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position is greater than the number of nodes.\n");
        return head;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to test the above functions
int main() {

    printf("Author : Aryan Shrivastav \nIT-B , 06720803123\n");

    struct Node* head = NULL;

    printf("linkedlist: ");
    printList(head);
    head = insertAtEnd(head, 6);
    printf("linkedlist: ");
    printList(head);
    head = insertAtBeginning(head, 7);
    printf("linkedlist: ");
    printList(head);
    head = insertAtBeginning(head, 1);
    printf("linkedlist: ");
    printList(head);
    head = insertAtEnd(head, 4);
    printf("linkedlist: ");
    printList(head);
    head = insertAtPosition(head, 3, 8);
    printf("Linked List: ");
    printList(head);

    return 0;
}
