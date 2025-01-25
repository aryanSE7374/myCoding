#include<stdio.h>
#include<stdlib.h>

// self referential structure of singly linked list
struct sll_node
{
    int data;
    struct sll_node* next;
};

//function to create a new node
struct sll_node* createNode(int data){
    struct sll_node* newNode = (struct sll_node*)malloc(sizeof(struct sll_node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//function to print the linked list
void printList(struct sll_node* head){
    struct sll_node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> " , temp->data);
        temp=temp->next;
    }
    printf("\n");
}


// Function to insert a node at the end of the linked list 
//w/o using double pointer
void insertAtEnd(struct sll_node* head, int data) {
    struct sll_node* newNode = createNode(data);
    struct sll_node* temp = head;

    // If the linked list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Change the next of the last node
    temp->next = newNode;
}




int main(){
    //function for the creation of empty list

    struct sll_node* head;
    head = NULL;



    return 0;


}

