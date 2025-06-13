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


// brute : iterative
class Solution {
public:
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
};


// brute : recursive

class Solution {
public:
    ListNode* revLL(ListNode* before , ListNode* after , ListNode* temp){
        if(after==NULL){return before;}
        temp = after->next;
        after->next = before;
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
