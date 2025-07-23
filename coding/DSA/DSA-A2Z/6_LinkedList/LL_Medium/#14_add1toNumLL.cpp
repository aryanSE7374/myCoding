#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// my Solution

// Time Complexity: O(n), where n is the number of nodes in the linked list.
// 	    O(n) for reversing the list.
// 	    O(n) for processing the digits.
// 	    O(n) for re-reversing the list.
// Space Complexity: O(1), as the solution only uses a few pointers and variables

class Solution {
  public:
  // helper function to reverse the list
    Node* reverseList(Node* head) {
        if((head==NULL) || (head->next==NULL)){return head;}
        Node *before = head;
        Node *after = head->next;
        Node *temp = after->next;
        head->next = NULL;
        while(after!=NULL){
            temp = after->next;
            after->next = before;
            before = after;
            after = temp;
        }
        return before;
    }
    Node* addOne(Node* head) {
        // step1 : reverse the list to get the track of the last digit first
        head = reverseList(head);

        // temp variable to iterate over the reversed list
        Node* temp = head;

        // check the case of 9 where u have to update it to 0 and add one to the digit next to the last 9
        // while u r not at the last node or stop getting a 9 , keep iterating and updating the data to 0  
        while (temp->next && temp->data == 9)
        {
            temp->data = 0;
            temp = temp->next;
        }

        // if loop breaked because of the list end , update the diigt 9 to 0 and add a new digit 1 to it

        if(temp->data==9){
            temp->data = 0;
            temp->next = new Node(1);

            return reverseList(head);
        }
        
        // else u add 1 to the data
        temp->data++;
        return reverseList(head);
        
    }
};



// brute solution
// gives TLE on GFG
// •	Time Complexity: O(n) for both traversals (conversion and rebuilding the list).
// •	Space Complexity: O(1) for variables, excluding the new linked list.


class Solution {
  public:
    Node* addOne(Node* head) {
        // Convert Linked List to a number
        long long num = 0;
        Node* temp = head;
        while (temp != NULL) {
            num = num * 10 + temp->data;
            temp = temp->next;
        }

        // Add one to the number
        num += 1;

        // Convert number back to Linked List
        Node* newHead = NULL;
        Node* curr = NULL;
        do {
            int digit = num % 10;
            Node* newNode = new Node(digit);
            if (newHead == NULL) {
                newHead = newNode;
            } else {
                newNode->next = newHead;
                newHead = newNode;
            }
            num /= 10;
        } while (num > 0);

        return newHead;
    }
};


// recursive optimal solution *
// •	Time Complexity: O(n) for traversing the list recursively.
// •	Space Complexity: O(n) due to the recursion stack.


class Solution {
  public:
    // Helper function to recursively add 1
    int addOneHelper(Node* head) {
        // Base case: if the node is NULL, return carry as 1
        if (head == NULL) {
            return 1;
        }

        // Recursively add 1 to the next node
        int carry = addOneHelper(head->next);

        // Add carry to the current node's data
        int sum = head->data + carry;

        // Update the current node's data and calculate new carry
        head->data = sum % 10;
        return sum / 10; // Return carry
    }

    Node* addOne(Node* head) {
        // Add one using recursion
        int carry = addOneHelper(head);

        // If there is a carry after processing the entire list
        if (carry > 0) {
            Node* newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};