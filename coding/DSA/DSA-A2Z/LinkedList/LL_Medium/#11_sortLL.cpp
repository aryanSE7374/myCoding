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


// my brute sol
// TC : O( 2N + NlogN )
// SC : O(N) for aux vector
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){return head;}
        vector<int> vec;
        ListNode* curr = head;
        while(curr!=NULL){
            vec.push_back(curr->val);
            curr = curr->next;
        }
        sort(vec.begin() , vec.end());
        curr = head;
        int i=0;
        while(curr!=NULL){
            curr->val = vec[i++];
            curr = curr->next;
        }
        return head;
    }
};

// my merge sort try


// merge two sorted linked lists

// Time Complexity: O(n1 + n2)
// Space Complexity: O(1)

ListNode* mergeSortedLL(ListNode* headL1 , ListNode* headL2 ){
    ListNode* l1 = headL1;
    ListNode* l2 = headL2;
    ListNode* dummyHead = new ListNode(); // val=0 , next = NULL
    // if(l1->val < l2->val){
    //     dummyHead->val = l1->val;
    // }
    // else{ // l1->val >= l2->val
    //     dummyHead->val = l2->val;
    // }
    ListNode* curr = dummyHead;

    while (l1!=NULL && l2!=NULL)
    {
        if(l1->val < l2->val){
            curr->next=l1;
            l1=l1->next;
        }
        else{ // l1->val >= l2->val
            curr->next=l2;
            l2=l2->next;
        }
        curr = curr->next;
    }
    while (l1!=NULL)
    {
        curr->next=l1;
        curr = curr->next;
        l1=l1->next;
    }
    while (l2!=NULL)
    {
        curr->next=l2;
        curr = curr->next;
        l2=l2->next;
    }
    return dummyHead->next;
}

// better code by chat GPT for merge 2 sorted LL
// Time Complexity: O(n1 + n2)
// Space Complexity: O(1)
// cons : will lose the track of original headL1 and headL2

ListNode* mergeSortedLL(ListNode* headL1, ListNode* headL2) {
    // Create a dummy node to serve as the start of the new list
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;

    // Traverse both lists until one is exhausted
    while (headL1 != nullptr && headL2 != nullptr) {
        if (headL1->val < headL2->val) {
            curr->next = headL1;
            headL1 = headL1->next;
        } else {
            curr->next = headL2;
            headL2 = headL2->next;
        }
        curr = curr->next;
    }

    // Attach the remaining part of the list, if any
    if (headL1 != nullptr) {
        curr->next = headL1;
    } else {
        curr->next = headL2;
    }

    // The merged list starts at dummy->next
    ListNode* newHead = dummy->next;
    delete dummy; // Clean up the dummy node
    return newHead;
}



// sort the LL using merge sort 
// TRY1 :- Accepted on leetcode
// •	Time Complexity: O(n*log n).
// •	Space Complexity: O(log n) for the recursion stack.
class Solution {
public:
    ListNode* mergeLL(ListNode* headL1 , ListNode* headL2 ){
        ListNode* l1 = headL1;
        ListNode* l2 = headL2;
        ListNode* dummyHead = new ListNode(); // val=0 , next = NULL

        ListNode* curr = dummyHead;

        while (l1!=NULL && l2!=NULL)
        {
            if(l1->val < l2->val){
                curr->next=l1;
                l1=l1->next;
            }
            else{ // l1->val >= l2->val
                curr->next=l2;
                l2=l2->next;
            }
            curr = curr->next;
        }
        while (l1!=NULL)
        {
            curr->next=l1;
            curr = curr->next;
            l1=l1->next;
        }
        while (l2!=NULL)
        {
            curr->next=l2;
            curr = curr->next;
            l2=l2->next;
        }
        return dummyHead->next;
    }

    ListNode* MS(ListNode* head){

        // base case : if only one node left in the linked list
        if(head->next == NULL){
            return head;
        }

        // find mid node 
        ListNode* slow = head; // slow
        ListNode* fast = head->next->next; // fast 
        while (fast!=NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head1 = head;
        ListNode* head2 = slow->next;
        slow->next = NULL;

        // recursice calls for left and right part
        head1 = MS(head1);
        head2 = MS(head2);

        // merge two parts 

        return mergeLL(head1 , head2);

    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){return head;}

        return MS(head);
    }
};


// striver's solution 
// •	Time Complexity: O(n*log n).
// •	Space Complexity: O(log n) for the recursion stack.

class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeLL(ListNode* headL1 , ListNode* headL2 ){
        ListNode* l1 = headL1;
        ListNode* l2 = headL2;
        ListNode* dummyHead = new ListNode(); // val=0 , next = NULL

        ListNode* curr = dummyHead;

        while (l1!=NULL && l2!=NULL)
        {
            if(l1->val < l2->val){
                curr->next=l1;
                l1=l1->next;
            }
            else{ // l1->val >= l2->val
                curr->next=l2;
                l2=l2->next;
            }
            curr = curr->next;
        }
        while (l1!=NULL)
        {
            curr->next=l1;
            curr = curr->next;
            l1=l1->next;
        }
        while (l2!=NULL)
        {
            curr->next=l2;
            curr = curr->next;
            l2=l2->next;
        }
        return dummyHead->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){return head;}
        ListNode* middle = findMiddle(head);
        ListNode* l = head;
        ListNode* r = middle->next;
        middle->next = NULL;

        l = sortList(l); // as it returns a sorted list with head = l 
        r = sortList(r);

        return mergeLL(l,r);

    }
};


// bottom up merge sort approach by chatGPT
// most optimal : slightly complex
// •	Time Complexity: O(n*log n).
// •	Space Complexity: O(1)

class Solution {
public:
    ListNode* mergeLL(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        int n = 0;
        ListNode* temp = head;
        while (temp) {
            ++n;
            temp = temp->next;
        }

        ListNode dummy(0);
        dummy.next = head;

        for (int size = 1; size < n; size *= 2) {
            ListNode* curr = dummy.next;
            ListNode* tail = &dummy;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, size);
                curr = split(right, size);
                tail->next = mergeLL(left, right);

                while (tail->next) tail = tail->next;
            }
        }

        return dummy.next;
    }

    ListNode* split(ListNode* head, int size) {
        while (--size && head) {
            head = head->next;
        }
        if (!head) return nullptr;
        ListNode* second = head->next;
        head->next = nullptr;
        return second;
    }
};


// comclusion 

// For coding challenges: Use Recursive Merge Sort for simplicity and readability.
// For production code: Use Iterative Merge Sort to save stack space.