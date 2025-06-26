#include<bits/stdc++.h>
using namespace std;

// brute
// Time Complexity : O(2N) 
// Space Complexity : O(N)

// Define a Node class for doubly linked list
class Node {
public:
    // Data stored in the node
    int data;   
    // Pointer to the next node in the list 
    //(forward direction)
    Node* next;     
    // Pointer to the previous node in the list
    //(backward direction)
    Node* back;     

    // Constructor for a Node with both data,
    //a reference to the next node,
    //and a reference to the previous node
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with data,
    //and no references to the next and
    //previous nodes (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array
// to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    // Create the head node with
    //the first element of the array
    
    Node* head = new Node(arr[0]);
    
    // Initialize 'prev' to the head node
    Node* prev = head;            

    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the
        //array and set its 'back' pointer to
        //the previous node
        
        Node* temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the
        //previous node to point to
        //the new node
        prev->next = temp; 
         // Move 'prev' to the newly created
         //node for the next iteration
        prev = temp;       
    }
    // Return the head of the doubly linked list
    return head;  
}

// Function to print the elements
//of the doubly linked list
void print(Node* head) {
    while (head != nullptr) {
        // Print the data in the tail node
        cout << head->data << " ";  
         // Move to the next node
        head = head->next;         
    }
}

 
// Funcion to reverse a doubly linked list
// Stack Brute Force Approach
Node* reverseDLL(Node* head){
    // if head is empty or there is only one element
    // we can directly just return the head
    if(head==NULL || head->next == NULL){
        return head;
    }
    
    // Initialise a stack st
    stack<int> st;
    
    // Initialise the node pointer temp at head
    Node* temp = head;
    
    // Traverse the doubly linked list via the temp pointer
    while(temp!=NULL){
        // insert the data of the current node into the stack
        st.push(temp->data);
        // traverse further
        temp = temp->next;
    }
    
    // Reinitialise temp to head
    temp = head;
    
    // Second iteration of the DLL to replace the values
    while(temp!=NULL){
        // Replace the value pointed via temp with
        // the value from the top of the stack
        temp->data = st.top();
        // Pop the value from the stack
        st.pop();
        // Traverse further
        temp = temp->next;
    }
    
    // Return the updated doubly linked 
    // where the values of nodes from both ends 
    // has been swapped
    return head;

}


int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);
    cout << endl << "Doubly Linked List Initially:  " << endl;
    print(head);
    cout << endl << "Doubly Linked List After Reversing " << endl;
    
     // Insert a node with value 10 at the end
    head = reverseDLL(head);
    print(head);
}


// optimal : TUF , O(N) , O(1)

// Function to reverse a doubly linked list
// In-place link exchange method
Node* reverseDLL(Node* head) {
    
    // Check if the list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
        // No change is needed;
        // return the current head
        return head; 
    }
    
     // Initialize a pointer to
     // the previous node
    Node* prev = NULL;  
    
    // Initialize a pointer to
    // the current node
    Node* current = head;   

    // Traverse the linked list
    while (current != NULL) {
        // Store a reference to
        // the previous node
        prev = current->back; 
        
        // Swap the previous and
        // next pointers
        current->back = current->next; 
        
        // This step reverses the links
        current->next = prev;          
        
        // Move to the next node
        // in the original list
        current = current->back; 
    }
    
    // The final node in the original list
    // becomes the new head after reversal
    return prev->back;
}


// GFG solution : O(N) , O(1)

class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // initialization
        if(head==NULL || head->next == NULL){return head;}
        DLLNode* curr = head;
        DLLNode* last = NULL;
        while(curr!=NULL){
            curr->prev = curr->next;
            curr->next = last;
            last = curr;
            curr = curr->prev;
        }
        return last;
    }
};

