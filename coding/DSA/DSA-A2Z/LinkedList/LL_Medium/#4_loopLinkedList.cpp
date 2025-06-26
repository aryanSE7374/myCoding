#include<bits/stdc++.h>
using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// brute try

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode* , int> map;
        ListNode* curr = head;
        while (curr!=NULL)
        {
            if(++map[curr]>1){return true;}
            curr = curr->next;
        }
        return false;   
    }
};


// brute soln
// Use this Solution for its clarity and beginner-friendly approach.
// Time Complexity: O(N * 2 * log(N) )  As the loop iterates through N nodes, 
// the total time complexity is determined by the product of the traversal (O(N)) and 
// the average-case complexity of the hashmap operations (insert and search), resulting in O(N * 2 * log(N)). 
/*
•	Per Node: For each node, the algorithm performs a lookup and potentially an insertion in the unordered_map, both of which take O(\log(N))
    in the worst case (if the map internally resolves collisions with a red-black tree).
•	For N Nodes: As the algorithm processes all N nodes in the linked list, the total time complexity is: O(N * 2 * log(N))
*/
// Space Complexity: O(N)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Initialize a pointer 'temp' at the head of the linked list
        ListNode* temp = head; 
        
        // Create a map to keep track of encountered nodes
        unordered_map<ListNode*, int> nodeMap;  

        // Traverse the linked list
        while (temp != nullptr) {
            // If the node is already in the map, there is a loop
            if (nodeMap.find(temp) != nodeMap.end()) {
                return true;
            }
            // Store the current node in the map
            nodeMap[temp] = 1;
            
            // Move to the next node
            temp = temp->next;  
        }

        // If the list is successfully traversed without a loop, return false
        return false;
    }
};


// optimal solution : the Tortoise and Hare Algorithm


class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Initialize two pointers, slow and fast, to the head of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the linked list with the slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            // Move slow one step
            slow = slow->next;
            // Move fast two steps
            fast = fast->next->next;

            // Check if slow and fast pointers meet
            if (slow == fast) {
                return true; // Loop detected
            }
        }

        // If fast reaches the end of the list, there is no loop
        return false;
    }
};
 

// important insight : 

// The fast pointer can move k > 2 nodes per iteration to reduce the minimum number of iterations required to meet the slow pointer.
// However, care must be taken to avoid skipping, especially when the loop size L is smaller than k. Hence, k = 2 remains the most 
// robust and universally reliable choice for the Tortoise and Hare algorithm.