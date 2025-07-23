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


// my try1
class Solution {
  public:
    Node* segregate(Node* head) {
        if(head->next == NULL){return head;}
        int n0 = 0 ;
        int n1 = 0 ;
        int n2 = 0 ;

        Node* curr = head;
        while(curr!=NULL){
            if(curr->data == 0){n0++;}
            else if(curr->data == 1){n1++;}
            else{n2++;}
            curr = curr->next;
        }
        curr = head;
        while(n0--){
            curr->data = 0;
            curr = curr->next;
        }
        while(n1--){
            curr->data = 1;
            curr = curr->next;
        }
        while(n2--){
            curr->data = 2;
            curr = curr->next;
        }
        return head;
    }
};

// my try by changing links 
// similar to Dutch National Flag algorithm
// Time Complexity: O(n) (one traversal for partitioning and constant-time linking).
// Space Complexity: O(1) (only dummy nodes and pointers used).

class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* dummy0 = new Node(-1);
        Node* dummy1 = new Node(-1);
        Node* dummy2 = new Node(-1);

        Node* curr = head;
        Node* curr0 = dummy0;
        Node* curr1 = dummy1;
        Node* curr2 = dummy2;

        while(curr!=NULL){
            if(curr->data == 0){
                curr0->next = curr;
                curr0 = curr;
            }
            else if(curr->data == 1){
                curr1->next = curr;
                curr1 = curr;
            }
            else{
                curr2->next = curr;
                curr2 = curr;
            }
            curr = curr->next;
        }
    

        /*  

        tree type if else 

                                     /-[yes]->
                         /-[yes]-> d2
                        /            \-[ no]->
            /-[yes]-> d1
           /           \             /-[yes]->
          /             \-[ no]-> d2 
         /                           \-[ no]->
       d0   
        \                            /-[yes]->
         \              /-[yes]-> d2
          \            /             \-[ no]->
           \-[ no]-> d1
                       \             /-[yes]->
                        \-[ no]-> d2
                                     \-[ no]-> [not possible due to test cases]


        */                      



        if(dummy0->next){ // dummy0->next is not null
            if(dummy1->next){ // dummy1->next is not null
                curr0->next = dummy1->next;
                if(dummy2->next){ // dummy2->next is not null
                    curr1->next = dummy2->next;
                    curr2->next = NULL;
                    return dummy0->next;
                }
                else{ // dummy2->next is null
                    curr1->next = NULL;
                    return dummy0->next;
                }
            }
            else{ // dummy1->next is null
                if(dummy2->next){ // dummy2->next is not null
                    curr0->next = dummy2->next;
                    curr2->next = NULL;
                    return dummy0->next;
                }
                else{ // dummy2->next is null
                    curr0->next = NULL;
                    return dummy0->next;
                }
            }
        }
        else{ // dummy0->next is null
            if(dummy1->next){ // dummy1->next is not null
                if(dummy2->next){ // dummy2->next is not null
                    curr1->next = dummy2->next;
                    curr2->next = NULL;
                    return dummy1->next;
                }
                else{ // dummy2->next is null
                    curr1->next = NULL;
                    return dummy1->next;
                }
            }
            else{ // dummy1->next is null
                // it's gauranteed by test cases and edge cases that dummy2->next can never be null
                curr2->next = NULL;
                return dummy2->next;
            }
        }

    }
};

// clean and concise implementation of the above solution

class Solution {
  public:
    Node* segregate(Node* head) {
        // Dummy nodes for 0s, 1s, and 2s
        Node* dummy0 = new Node(-1);
        Node* dummy1 = new Node(-1);
        Node* dummy2 = new Node(-1);

        // Pointers for the three lists
        Node* curr0 = dummy0;
        Node* curr1 = dummy1;
        Node* curr2 = dummy2;

        Node* curr = head;

        // Traverse the list and partition nodes
        while (curr != NULL) {
            if (curr->data == 0) {
                curr0->next = curr;
                curr0 = curr;
            } else if (curr->data == 1) {
                curr1->next = curr;
                curr1 = curr;
            } else {
                curr2->next = curr;
                curr2 = curr;
            }
            curr = curr->next;
        }


        // Final linking of lists using ternary operators
        curr0->next = dummy1->next ? dummy1->next : dummy2->next;
        curr1->next = dummy2->next;
        curr2->next = NULL;

        // Return the head of the new list
        Node* newHead = dummy0->next ? dummy0->next : (dummy1->next ? dummy1->next : dummy2->next);

        // Free memory allocated for dummy nodes
        delete dummy0;
        delete dummy1;
        delete dummy2;

        return newHead;
    }
};