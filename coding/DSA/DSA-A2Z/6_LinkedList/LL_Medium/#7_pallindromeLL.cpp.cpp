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
// TC : O(N)
// SC : O(N) ; for auxillary string

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){return true;}
        ListNode* curr = head;
        string str = "";
        while(curr!=NULL){
            str+=curr->val;
            curr = curr->next;
        }
        int l=0 , h=str.length()-1;
        while (l<h)
        {
            if(str[l]!=str[h]){return false;}
            l++;
            h--;
        }
        return true;
    }
};

// brute solution 
// TC : O(N)
// SC : O(N) ; for auxillary stack

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Create an empty stack to store values
        stack<int> st;

        // Initialize a temporary pointer to the head of the linked list
        ListNode* temp = head;

        // Traverse the linked list and push values onto the stack
        while (temp != nullptr) {
            st.push(temp->val); // Push the data from the current node onto the stack
            temp = temp->next;  // Move to the next node
        }

        // Reset the temporary pointer back to the head of the linked list
        temp = head;

        // Compare values by popping from the stack and checking against linked list nodes
        while (temp != nullptr) {
            if (temp->val != st.top()) {
                return false; // If values don't match, it's not a palindrome
            }
            st.pop();         // Pop the value from the stack
            temp = temp->next; // Move to the next node in the linked list
        }

        // If all values match, it's a palindrome
        return true;
    }
};


// optimal solution
// TC : O(N)
// the time complexity is calculated as O(N/2 + N/2 + N/2 + N/2), 
// which simplifies to O(2N), ultimately representing O(N). 
// SC : O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    // Function to reverse a linked list using recursion
    ListNode* reverseLinkedList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // Base case: empty or single-node list
        }

        // Reverse the rest of the list
        ListNode* newHead = reverseLinkedList(head->next);

        // Reverse the link
        head->next->next = head;
        head->next = nullptr;

        return newHead; // Return the new head
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true; // Empty or single-node list is always a palindrome
        }

        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* newHead = reverseLinkedList(slow->next);

        // Compare both halves
        ListNode* first = head;
        ListNode* second = newHead;
        bool result = true;
        while (second != nullptr) {
            if (first->val != second->val) {
                result = false; // Values don't match; not a palindrome
                break;
            }
            first = first->next;
            second = second->next;
        }

        // Restore the list to its original state
        reverseLinkedList(newHead);

        return result;
    }
};



// optimal using iterative reverse LL function

class Solution {
public:
    // (reversed LL)<-[before]   [after]->[temp]->....[_NULL_]
    ListNode* reverseLinkedList(ListNode* head) {
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

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true; // Empty or single-node list is always a palindrome
        }

        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* newHead = reverseLinkedList(slow->next);

        // Compare both halves
        ListNode* first = head;
        ListNode* second = newHead;
        bool result = true;
        while (second != nullptr) {
            if (first->val != second->val) {
                result = false; // Values don't match; not a palindrome
                break;
            }
            first = first->next;
            second = second->next;
        }

        // Restore the list to its original state
        // slow->next = reverseLinkedList(newHead); // for more clarity 
        reverseLinkedList(newHead);

        return result;
    }
};

