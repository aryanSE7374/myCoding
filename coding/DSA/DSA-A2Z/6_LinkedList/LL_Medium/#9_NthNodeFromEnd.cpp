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


// brute try
// two traversals
// TC :   O(L)+O(L-N) ~ O(2L)
// SC : O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){return NULL;}
        ListNode* curr = head;
        int len=0;
        while (curr!=NULL)
        {
            len++;
            curr = curr->next;
        }
        
        // edge case handling : the first node
        // eg :  [1,2,3,4,5,6,7] n=7 
        
        if(len==n){
            ListNode* newHead = head->next;
            delete(head);
            return newHead;
        }

        //  change curr to head in order to traverse again
        curr = head;
        // nth node from last = len-n+1 th from start 
        /*
        eg : 1->2->3->4->[5]->6->7->|
                          3   2  1 
        len = 7 ; n = 3;
        result = 5; 
        7-3+1 = 5
        */ 

        //so,in order to delete the kth node you have to be at (k-1)th Node
        // and store kth in a temp variable

        for (int i = 1; i < len-n; i++)
        {
            curr = curr->next;
        }

        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete(temp);

        return head;
    }
};


// optimal try
// TC : O(L)
// SC: O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head->next==NULL){return NULL;}

        ListNode* slow = head;
        ListNode* fast = head;

        while(n--){
            fast = fast->next;
            if(fast==NULL){
                // to check the n=len edge case
                ListNode* newHead = head->next;
                delete(head);
                return newHead;
            }
        }

        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete(temp);
        return head;
    }
};

