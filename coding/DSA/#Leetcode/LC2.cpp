#include<bits/stdc++.h>
using namespace std;
//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
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