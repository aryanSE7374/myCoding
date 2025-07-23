#include <stdio.h>
#define MAX 5  // Define the maximum size of the queue

int queue[MAX];  // Array to store queue elements
int front = -1;  // Front pointer
int rear = -1;   // Rear pointer

// Function to insert an element into the queue
void insert(int value) {
    if (rear == MAX - 1) {
        printf("Queue is full. Overflow condition!\n");
        return;
    } else {
        if (front == -1)  // If queue is initially empty
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

// Function to delete an element from the queue
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Underflow condition!\n");
        return;
    } else {
        printf("Deleted %d from the queue.\n", queue[front]);
        front++;
        if (front > rear) {  // Reset the queue when it becomes empty
            front = rear = -1;
        }
    }
}

// Function to display the elements of the queue
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Author : Aryan Shrivastav \nIT-B , 06720803123\n");
    printf("Author : Aditya Om Gupta \nIT-B , 06020803123\n");
    printf("Author : Shivam Singh \nIT-B , 05920803123\n");
    printf("Author : Aniket \nIT-B , 06320803123\n");
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}