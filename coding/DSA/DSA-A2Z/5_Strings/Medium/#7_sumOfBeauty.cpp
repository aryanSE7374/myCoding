#include<bits/stdc++.h>
using namespace std;

/*

// wrong solution (interpretation wrong)

class Solution {
public:
    int beautySum(string s) {
        unordered_map<char , int> mpp;
        for(char c : s){
            mpp[c]++;
        }
        int maxi = 0;
        int mini = s.length();
        for(auto it : mpp){
            maxi = max(it.second , maxi);
            mini = min(it.second , mini);
        }
        return maxi-mini;
    }
};

*/


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

struct ListNode {  
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
    }
};