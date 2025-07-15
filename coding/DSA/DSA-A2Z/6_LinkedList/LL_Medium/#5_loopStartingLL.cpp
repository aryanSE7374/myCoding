#include<bits/stdc++.h>
using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// brute try
// TC : O(N)
// SC : O(N)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode* , int> map;
        ListNode* curr = head;
        while (curr!=NULL)
        {
            if(++map[curr]>1){return curr;}
            curr = curr->next;
        }
        return NULL;   
    }
};

// brute sol
// TC : O(N)
// SC : O(N)

class Solution{
    public:
    // Function to detect a loop in a linked list
    // and return the starting node of the loop
    ListNode *detectCycle(ListNode *head) {
        
        // Use temp to traverse the linked list
        ListNode* temp = head;
        
        // hashmap to store all visited nodes
        unordered_map<ListNode*, int> mp;
        
        // Traverse the list using temp
        while(temp!=NULL){
            // check if temp has been encountered again
            if(mp.count(temp)!=0){
                // A loop is detected hence return temp
                return temp;
            }
            // store temp as visited
            mp[temp] = 1;
            // iterate through the list
            temp = temp->next;
        }

        // If no loop is detected, return nullptr
        return NULL; 
    }
};


// optimal try
// TC : O(N)
// SC : O(1)

class Solution{
    public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                while (fast!=NULL && fast->next!=NULL)
                {
                    if(slow==fast){
                        return slow;
                    }
                    slow = slow->next;
                    fast = fast->next;
                }
            }
        }
        return NULL; // no loop detected
        
    }
};

// optimal solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // TC : O(N)
// SC : O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Initialize slow and fast pointers to the head of the list
        ListNode* slow = head;  
        ListNode* fast = head;  

        // Phase 1: Detect the loop
        while (fast != nullptr && fast->next != nullptr) {
            // Move slow one step
            slow = slow->next;        
            
            // Move fast two steps
            fast = fast->next->next;  

            // If slow and fast meet, a loop is detected
            if (slow == fast) {
                // Reset the slow pointer to the head of the list
                slow = head; 

                // Phase 2: Find the first node of the loop
                while (slow != fast) {
                    // Move slow and fast one step at a time
                    slow = slow->next;  
                    fast = fast->next;  
                }
                
                // When slow and fast meet again, return the first node of the loop
                return slow;  
            }
        }

        // If no loop is found, return NULL
        return nullptr; 
    }
};