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

// my brute try
// TC : O(N)
// SC : O(N)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // inintial edge cases (nodes<=2) : no change cases
        if(head==NULL || head->next==NULL || head->next->next==NULL){return head;}

        ListNode* tempListOdd = new ListNode(head->val); // creating the odd auxillary list
        ListNode* tempListEven = new ListNode(head->next->val); // creating the even auxillary list
        
        
        // ListNode* tempOdd = tempListOdd; // store the head of the odd aux list
        // ListNode* tempEven = tempListEven; // store the head of the even aux list

        ListNode* currOdd = tempListOdd; // store the head of the odd aux list
        ListNode* currEven = tempListEven; // store the head of the even aux list

        cout<<head->val<<"->"<<head->next->val<<"->";

        ListNode* curr = head->next->next;
        

        while (curr!=NULL && curr->next!=NULL)
        {
            currOdd->next = new ListNode(curr->val);
            currEven->next = new ListNode(curr->next->val);

            currOdd = currOdd->next;
            currEven = currEven->next;

            cout<<curr->val<<"->"<<curr->next->val<<"->";
            curr = curr->next->next; // move curr pointer to two pointers
        }

        // getting rid of odd no. of total nodes edge case , where the last odd node isnt added to tempList yet
        if(curr!=NULL){ 
            currOdd->next = new ListNode(curr->val);
            currOdd = currOdd->next;
            cout<<curr->val<<"->|";
        }
        else{
            cout<<"|";
        }

        currOdd->next = tempListEven;
        return tempListOdd;
        
    }
};


// optimal try using two pointers approach (help by chatGPT)
// TC : O(N)
// SC : O(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){return head;}

        // 3 initial pointers
        ListNode* currOdd = head;
        ListNode* currEven = head->next;
        ListNode* evenHead = currEven;

        while(currOdd!=NULL && currOdd->next!=NULL && currEven!=NULL && currEven->next!=NULL){
            currOdd->next = currOdd->next->next;
            currEven->next = currEven->next->next;
            currOdd = currOdd->next;
            currEven = currEven->next;
        }

        currOdd->next = evenHead;
        return head;
        
    }
};


// chatGPT short and concise implementation
// TC : O(N)
// SC : O(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;             // Pointer for odd-indexed nodes
        ListNode* even = head->next;      // Pointer for even-indexed nodes
        ListNode* evenHead = even;        // Head of even-indexed nodes

        while (even && even->next) {
            odd->next = even->next;       // Link current odd to next odd
            odd = odd->next;              // Move odd pointer

            even->next = odd->next;       // Link current even to next even
            even = even->next;            // Move even pointer
        }

        odd->next = evenHead;             // Append even list to odd list
        return head;
    }
};

