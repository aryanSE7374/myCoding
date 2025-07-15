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


// brute : O(N + N/2)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode* curr = head;
        while(curr != NULL){
            curr = curr->next;
            n++;
        }
        curr = head;
        int mid = n/2;
        for (int i = 0; i < mid; i++)
        {
            curr = curr->next;
        }
        return curr;
    }
};

//my Algo :  better : O(N)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n=1;
        int mid=1;
        ListNode* currPtr = head;
        ListNode* midPtr = head;
        while (currPtr != NULL)
        {
            if(mid<(n+2)/2){
                mid++;
                midPtr = midPtr->next;
            }
            n++;
            currPtr = currPtr->next;
        }
        return midPtr;
    }
};


// tortoise and hare algo : O(N)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};