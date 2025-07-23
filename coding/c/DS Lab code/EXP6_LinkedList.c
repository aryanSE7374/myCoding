#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to delete a node at the beginning
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node at the end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete a node at a given position
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (position < 1) {
        printf("Position should be >= 1.\n");
        return head;
    }
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position is greater than the number of nodes.\n");
        return head;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
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

    // printf("Author : Aditya Om Gupta \nIT-B , 06020803123\n");
    // printf("Author : Aryan Shrivastav \nIT-B , 06720803123\n");
    // printf("Author : Satyam Jha \nIT-B , 06620803123 \n");

    struct Node* head = NULL;

    // Creating a linked list for testing
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    printf("Original Linked List: ");
    printList(head);

    head = deleteAtBeginning(head);
    printf("After deleting at beginning: ");
    printList(head);

    head = deleteAtEnd(head);
    printf("After deleting at end: ");
    printList(head);

    head = deleteAtPosition(head, 2);
    printf("After deleting at position 2: ");
    printList(head);

    return 0;
}



