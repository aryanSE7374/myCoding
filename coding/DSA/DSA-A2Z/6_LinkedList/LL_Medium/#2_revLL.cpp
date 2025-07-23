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


// optimal : iterative
// Time Complexity: O(N) 
// Space Complexity: O(1)
class Solution {
public:

    // (reversed LL)<-[before]   [after]->[temp]->....[_NULL_]
    ListNode* reverseList(ListNode* head) {
        if((head==NULL) || (head->next==NULL)){return head;}
        ListNode *before = head;
        ListNode *after = head->next;
        ListNode *temp = after->next;
        head->next = NULL;
        while(after!=NULL){
            temp = after->next;
            after->next = before;
            before = after;
            after = temp;
        }
        return before;
    }

    // (reversed LL)<-[before]   [temp]->[after]->....[_NULL_]
    ListNode* reverseList2(ListNode* head) {
        if((head==NULL) || (head->next==NULL)){return head;}
        ListNode *before = head;
        ListNode *temp = head->next;
        ListNode *after = temp->next;
        head->next = NULL; // important step : CTM
        while(temp!=NULL){
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
        return before;
    }
};


// optimal : recursive
// Time Complexity: O(N) 
// Space Complexity: O(1)

class Solution {
public:

    // (reversed LL)<-[before]   [after]->[temp]->....[_NULL_]
    ListNode* revLL(ListNode* before , ListNode* after , ListNode* temp){
        // base case
        if(after==NULL){return before;}
        // changes in links
        temp = after->next;
        after->next = before;
        // variables updated in recursive call
        return revLL(after , temp , temp);
    }
    ListNode* reverseList(ListNode* head) {
        if((head==NULL) || (head->next==NULL)){return head;}
        ListNode *before = head;
        ListNode *after = head->next;
        ListNode *temp = after->next;
        head->next = NULL;
        return revLL(before , after , temp);
    }
};
