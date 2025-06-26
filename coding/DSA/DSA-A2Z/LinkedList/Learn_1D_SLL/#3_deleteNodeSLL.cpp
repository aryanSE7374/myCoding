#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// brute
// The brute method involves traversing the linked list from the head to find the previous node of the target, 
// then updating the next pointer of the previous node to skip the target node and freeing its memory.


// better/optimal
// Time Complexity: O(N) for traversing the linked list and updating the tail.
// Space Complexity: O(1), as we have not used any extra space.

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the value of the next node to the current node
        node->val = node->next->val;
        // Update the next pointer to skip the next node
        ListNode* temp = node->next;  // Temporary pointer to the node to be deleted
        node->next = node->next->next;
        delete temp;  // Free the memory of the skipped node
    }
};