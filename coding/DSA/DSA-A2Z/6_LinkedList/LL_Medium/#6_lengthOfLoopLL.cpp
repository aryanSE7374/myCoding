#include<bits/stdc++.h>
using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// brute 
// TC : O(N)
// SC : O(N)

// Function to return the length 
// of loop using hashing

int lengthOfLoop(Node* head) {
    // Hashmap to store visited
    // nodes and their timer values
    unordered_map<Node*, int> visitedNodes; 
    
    // Initialize pointer to
    // traverse the linked list
    Node* temp = head; 
    
    // Initialize timer to track
    // visited nodes
    int timer = 0; 

    // Traverse the linked list till
    // temp reaches nullptr
    while (temp != NULL) {
        
        // If revisiting a node return
        // the difference of timer values
        if (visitedNodes.find(temp) != visitedNodes.end()) {
            // Calculate the length of the loop
            int loopLength = timer - visitedNodes[temp];
            
            // Return the length of the loop
            return loopLength; 
        }
        // Store the current node and
        // its timer value in the hashmap
        visitedNodes[temp] = timer;
        
        // Move to the next node
        temp = temp->next;
        
         // Increment the timer
        timer++;
    }

    // If traversal is completed and
    // we reach the end of the list (null)
    // means there is no loop
    return 0;
}



int main() {
    // Create a sample linked
    // list with a loop
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Create a loop from
    // fifth to second
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // This creates a loop
    fifth->next = second; 

    int loopLength = lengthOfLoop(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
}


// optimal try 1 : WRONG

int lengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            slow = head;
            Node* temp = fast;
            int l = 0;
            while (slow!=fast)
            {
                slow = slow->next;
                fast = fast->next;
                l++;
            }
            int d = 0;
            while(slow!=temp){
                slow = slow->next;
                d++;
            }
            return l+d;
        }
    }
    return 0;
}


// optimal try 2 
// TC : O(N)
// SC : O(1)

int lengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            // loop detected
            slow = head;
            Node* temp = fast;
            int l = 0;
            while (slow!=fast)
            {
                slow = slow->next;
                fast = fast->next;
                l++;
            }
            if(slow!=temp){
                int d = 0;
                while(slow!=temp){
                    slow = slow->next;
                    d++;
                }
                return l+d;
            }
            else{ // slow == temp  : (edge cases)
                slow = slow->next;
                int d=1;
                while(slow!=temp){
                    slow = slow->next;
                    d++;
                }
                return d;
            }
        }
    }
    return 0;
}

// optimal solution
// TC : O(N)
// SC : O(1)

class Solution {
  public:
    // Helper function to return the length of the loop
    // when slow and fast pointers meet
    int findLength(Node* slow, Node* fast) {
        int cnt = 1;  // Start count from 1
        fast = fast->next;  // Move fast one step
        while (slow != fast) {
            cnt++;
            fast = fast->next;
        }
        return cnt;  // Return the length of the loop
    }

    // Function to find the length of a loop in the linked list
    int countNodesinLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;

        // Step 1: Traverse the list to detect a loop
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Move slow one step
            fast = fast->next->next;    // Move fast two steps

            // Step 2: If slow and fast meet, a loop exists
            if (slow == fast) {
                return findLength(slow, fast);  // Return loop length
            }
        }

        // Step 3: If fast reaches the end, there is no loop
        return 0;
    }
};