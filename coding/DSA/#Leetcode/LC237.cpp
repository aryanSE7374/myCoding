#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
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