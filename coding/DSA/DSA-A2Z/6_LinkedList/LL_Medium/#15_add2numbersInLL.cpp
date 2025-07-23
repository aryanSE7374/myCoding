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

// my solution 1 : poor implmentation , less readable and modular
// solution1 took 0ms , 77.1 MB

// •	Time: O(max(n, m)).
// •	Space: O(max(n, m)) (for the result list).

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1; ListNode* curr2 = l2; 
        ListNode* result= new ListNode(); ListNode* curr = result;
        int carry=0;
        while ((curr1!=nullptr)||(curr2!=nullptr))
        {
            if (curr1==nullptr)
            {
                int sum = carry+curr2->val;
                if(sum>9){
                    curr->val=(sum%10);
                    carry=sum/10;
                }
                else{curr->val = sum;carry=0;}
            }
            else if (curr2==nullptr)
            {
                int sum = carry+curr1->val;
                if(sum>9){
                    curr->val=(sum%10);
                    carry=sum/10;
                }
                else{curr->val = sum;carry=0;}
            }
            else{
                int sum = carry + curr1->val + curr2->val;
                if(sum>9){
                    curr->val=(sum%10);
                    carry=sum/10;
                }
                else{curr->val = sum;carry=0;}
            }
            if(curr1!=nullptr){
                curr1 = curr1->next;
            }
            if(curr2!=nullptr){
                curr2 = curr2->next;
            }
            if((curr1==nullptr)&&(curr2==nullptr)){
                if(carry==0){break;}
                curr->next = (ListNode*)new ListNode();
                curr->next->val=1;
                break;
            }
            curr->next = (ListNode*)new ListNode();
            curr=curr->next;
        }
        return result;
    }
};


// my solution try 2 : better , readable and modular
// solution2 took 15ms , 77.2 MB

// •	Time: O(max(n, m)).
// •	Space: O(max(n, m)) (for the result list).

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* res = new ListNode(-1);
        
        ListNode* temp = res;
        int carry = 0;

        while(curr1!=NULL && curr2!=NULL){
            int sum = curr1->val + curr2->val;
            if(sum+carry>9){
                temp->next = new ListNode(sum+carry-10);
                carry=1; // since carry can never exceed 1 in addition of two numbers
            }
            else{
                temp->next = new ListNode(sum+carry);
                carry=0;
            }

            curr1 = curr1->next;
            curr2 = curr2->next;
            temp = temp->next;
        }

        while(curr1){
            if(curr1->val + carry > 9){
                temp->next = new ListNode(curr1->val + carry - 10);
                carry = 1;
            }
            else{
                temp->next = new ListNode(curr1->val+carry);
                carry=0;
            }

            curr1 = curr1->next;
            temp = temp->next;
        }

        while(curr2){
            if(curr2->val + carry > 9){
                temp->next = new ListNode(curr2->val + carry - 10);
                carry = 1;
            }
            else{
                temp->next = new ListNode(curr2->val+carry);
                carry=0;
            }

            curr2 = curr2->next;
            temp = temp->next;
        }

        if(carry){
            temp->next = new ListNode(carry);
        }

        ListNode* head = res->next;
        delete(res);
        return head;

    }
};


// chatGPT brute 
// have runtime overflow issues as long long cant store numbers with no of nodes upto 100

// •	Time: O(n + m + k), where n, m are the lengths of the input lists and k is the number of digits in the sum.
// •	Space: O(k) for the result list.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Convert the linked lists to numbers
        long long num1 = 0, num2 = 0, multiplier = 1;
        while (l1) {
            num1 += l1->val * multiplier;
            l1 = l1->next;
            multiplier *= 10;
        }
        multiplier = 1;
        while (l2) {
            num2 += l2->val * multiplier;
            l2 = l2->next;
            multiplier *= 10;
        }

        // Add the numbers and create the result list
        long long sum = num1 + num2;
        if (sum == 0) return new ListNode(0);

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while (sum > 0) {
            curr->next = new ListNode(sum % 10);
            sum /= 10;
            curr = curr->next;
        }

        return dummy->next;
    }
};


// optimal solution by chatGPT : Best and Clean

// •	Time: O(max(n, m)).
// •	Space: O(max(n, m)) for the resultant list.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0;

        // Traverse both lists
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            curr->next = new ListNode(sum % 10);
            carry = sum / 10;
            curr = curr->next;
        }

        return dummy->next;
    }
};

// Optimized Version of my Solution 1

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify list creation
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0;

        // Helper function to handle node sum logic
        auto addNode = [&](int val1, int val2) { // lambda function
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        };

        // Traverse both lists
        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            addNode(val1, val2);

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        // Handle leftover carry
        if (carry) {
            curr->next = new ListNode(carry);
        }

        return dummy->next;
    }
};


// Optimized Version of my Solution 2

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;

        // Consolidate logic for adding two lists
        auto processNode = [&](ListNode* node) {
            int sum = node->val + carry;
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            temp = temp->next;
        };

        // Traverse both lists
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            temp = temp->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

