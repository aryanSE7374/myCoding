#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



// brute solution
// •	Time Complexity: O(2n) (twice traversal).
// •	Space Complexity: O(1) (no extra space).

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: if the list is empty or has only one node
        if (!head || !head->next) {
            delete head;
            return nullptr;
        }

        // Step 1: Calculate the number of nodes in the list
        ListNode* temp = head;
        int n = 0;
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        // Step 2: Find the position of the middle node
        int res = n / 2;

        // Step 3: Traverse to the node just before the middle node
        temp = head;
        while (res > 1) {
            res--;
            temp = temp->next;
        }

        // Step 4: Delete the middle node
        ListNode* middle = temp->next;
        temp->next = temp->next->next;
        delete middle;

        // Return the head of the updated list
        return head;
    }
};

// my try 1 
// TC : O(N/2) ~ O(N) (single traversal)
// SC : O(1)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // edge case for single node
        if(head->next == NULL ){return NULL;}

        // initializing two heling pointers slow and fast
        ListNode* slow = head;
        ListNode* fast = head->next->next; 
        // fast initialized at 3rd node because slow should stay 
        // one node before the middle node in order to delete it

        // traverse one node before the middle node
        while (fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // delete slow->next i.e. the middle node
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);
        return head;
        
    }
};
