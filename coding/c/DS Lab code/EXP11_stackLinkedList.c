#include <stdio.h>
#include <stdlib.h>
struct Node {
   int data;
   struct Node* next;
};
struct Node* createNode(int value) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode->next = NULL;
   return newNode;
}
void push(struct Node** top, int value) {
   struct Node* newNode = createNode(value);
   newNode->next = *top;
   *top = newNode;
}
void pop(struct Node** top) {
   if (*top == NULL) {
       printf("Stack Underflow! Cannot pop.\n");
   } else {
       struct Node* temp = *top;
       printf("Popped %d from the stack.\n", (*top)->data);
       *top = (*top)->next;
       free(temp);}
}
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is: \n");
        while (top != NULL) {
            printf("%d\n", top->data);
            top = top->next;}
    }
}
int main() {
    struct Node* top = NULL;  
    int choice, value, n;
    printf("Author : Aryan Shrivastav \nIT-B , 06720803123\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    while (n>0){
        printf("Enter the value to push: ");
        scanf("%d", &value);
        push(&top, value);
        n--;
    }
    display(top);    
    pop(&top);        
    display(top);
    return 0;
}