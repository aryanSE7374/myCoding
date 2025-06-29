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

// my try 1 : accepted on LC
// better than brute

class Solution {
public:
    ListNode* searchNodeInSet(set<ListNode*> setA , set<ListNode*> setB){
        for(auto it : setA){
            if(setB.find(it)!=setB.end()){
                return it;
            }
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == headB){return headA;}
        set<ListNode*> setA;
        set<ListNode*> setB;
        ListNode* temp = headA;
        while (temp)
        {
            setA.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp)
        {
            setB.insert(temp);
            temp = temp->next;
        }
        int a = setA.size();
        int b = setB.size();
        if(a<b){
            return searchNodeInSet(setA , setB);
        }
        else{
            return searchNodeInSet(setB , setA);
        }
    }
};


// using unordered set failed because we hashed both the linked lists , hence we've solution2 

// class Solution {
// public:
//     ListNode* searchNodeInSet(unordered_set<ListNode*> setA , unordered_set<ListNode*> setB){
//         for(auto it : setA){
//             if(setB.find(it)!=setB.end()){
//                 return it;
//             }
//         }
//         return NULL;
//     }
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if(headA == headB){return headA;}
//         unordered_set<ListNode*> setA;
//         unordered_set<ListNode*> setB;
//         ListNode* temp = headA;
//         while (temp)
//         {
//             setA.insert(temp);
//             temp = temp->next;
//         }
//         temp = headB;
//         while (temp)
//         {
//             setB.insert(temp);
//             temp = temp->next;
//         }
//         int a = setA.size();
//         int b = setB.size();
//         if(a<b){
//             return searchNodeInSet(setA , setB);
//         }
//         else{
//             return searchNodeInSet(setB , setA);
//         }
//     }
// };

// striver's 4 solutions


// Solution 1: Brute Force

// Complexity Analysis:
// 	1.	Time Complexity: O(m * n)
// 	•	m: Length of headA, n: Length of headB.
// 	•	For each node in headB, traverse headA.
// 	2.	Space Complexity: O(1)
// 	•	No additional data structures used.

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* tempB = headB;
        while (headB != nullptr) {
            ListNode* tempA = headA;
            while (tempA != nullptr) {
                if (tempA == headB) return headB; // Intersection found
                tempA = tempA->next;
            }
            headB = headB->next;
        }
        return nullptr; // No intersection
    }
};


// Solution 2: Hashing

// Complexity Analysis:
// 	1.	Time Complexity: O(m + n)
// 	•	Traverse headA to insert its nodes into the hash set (O(m)).
// 	•	Traverse headB to check for intersection (O(n)).
// 	2.	Space Complexity: O(m)
// 	•	Hash set stores up to m nodes.

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> visited;
        
        // hashed listA
        while (headA != nullptr) {
            visited.insert(headA);
            headA = headA->next;
        }
        
        // iterate over listB and search for each node of listB into hashed set of listA
        while (headB != nullptr) {
            if (visited.find(headB) != visited.end()) return headB; // Intersection found
            headB = headB->next;
        }
        return nullptr; // No intersection
    }
};


// Solution 3: Length Difference
// Complexity Analysis:
// 	1.	Time Complexity: O(m + n)
// 	•	Compute lengths of both lists (O(m + n)).
// 	•	Traverse the adjusted lists (O(m + n)).
// 	2.	Space Complexity: O(1)
// 	•	No additional data structures used.


class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = 0, lenB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        
        // Calculate lengths of both lists
        while (tempA != nullptr) { lenA++; tempA = tempA->next; }
        while (tempB != nullptr) { lenB++; tempB = tempB->next; }
        
        // Adjust starting points for both lists
        while (lenA > lenB) { headA = headA->next; lenA--; }
        while (lenB > lenA) { headB = headB->next; lenB--; }
        
        // Traverse both lists simultaneously
        while (headA != nullptr && headB != nullptr) {
            if (headA == headB) return headA; // Intersection found
            headA = headA->next;
            headB = headB->next;
        }
        
        return nullptr; // No intersection
    }
};


// Solution 4: Two Pointers
// Complexity Analysis:
// 	1.	Time Complexity: O(m + n)
// 	•	Each pointer traverses at most m + n nodes.
// 	2.	Space Complexity: O(1)
// 	•	No additional data structures used.

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;
        
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        
        while (d1 != d2) {
            d1 = d1 == nullptr ? headB : d1->next;
            d2 = d2 == nullptr ? headA : d2->next;
        }
        
        return d1; // Either intersection or nullptr
    }
};