#include<bits/stdc++.h>
using namespace std;

// LC 3510
// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/ 

// brute froce for easy version
// TC : O(n^2)
// SC : O(n)

struct Node {

    Node* prev = NULL;
    Node* next = NULL;

    int data ;

};

class Solution {
public:

    bool isSorted ( Node* head ) {

        while ( head->next != NULL ) {
            if ( (head->data) > (head->next->data) ) return false;
            head = head -> next ;
        }

        return true ;

    }

    int minimumPairRemoval(vector<int>& nums) {

        int n = nums.size();

        if ( n==1 ) return 0;

        const int INF = 1e9 + 7 ;

        Node* head = new Node ;
        head->data = nums[0];

        Node* curr = head ;

        // create linked list

        for ( int i=1 ; i<n ; i++) {

            Node* temp = new Node;
            temp->data = nums[i];

            curr->next = temp ;
            temp-> prev = curr ;
            curr = temp ;

        }

        int ops = 0 ;

        // perform and count operations

        while ( ( head->next != NULL ) && !isSorted( head ) ){

            ops++ ;
            
            curr = head->next ;
            int mini = INF ;
            Node* minNode = curr ;

            // find min node

            while ( curr != NULL ) {

                int sum = ( curr->data ) + ( curr->prev->data ) ;

                if ( mini > sum ) {
                    mini = sum ;
                    minNode = curr ;
                }

                curr = curr -> next ;

            }

            // delete min Node

            Node* temp = minNode->prev ;

            minNode -> data = mini ;

            minNode -> prev = minNode -> prev -> prev ;

            if ( minNode -> prev == NULL ) {
                head = minNode ;
            }
            else {
                minNode -> prev -> next = minNode ;
            }

            delete temp ;

        }

        return ops ;
        
    }
};


// optimal solution
// TC : O(  )
// SC : O(  )

struct Node {

    Node* prev = NULL;
    Node* next = NULL;

    int data ;

};

class Solution {
public:

    bool isSorted ( Node* head ) {

        while ( head->next != NULL ) {
            if ( (head->data) > (head->next->data) ) return false;
            head = head -> next ;
        }

        return true ;

    }

    int minimumPairRemoval(vector<int>& nums) {

        int n = nums.size();

        if ( n==1 ) return 0;

        const int INF = 1e9 + 7 ;

        Node* head = new Node ;
        head->data = nums[0];

        Node* curr = head ;

        // create linked list

        for ( int i=1 ; i<n ; i++) {

            Node* temp = new Node;
            temp->data = nums[i];

            curr->next = temp ;
            temp-> prev = curr ;
            curr = temp ;

        }

        int ops = 0 ;

        // perform and count operations

        while ( ( head->next != NULL ) && !isSorted( head ) ){

            ops++ ;
            
            curr = head->next ;
            int mini = INF ;
            Node* minNode = curr ;

            // find min node

            while ( curr != NULL ) {

                int sum = ( curr->data ) + ( curr->prev->data ) ;

                if ( mini > sum ) {
                    mini = sum ;
                    minNode = curr ;
                }

                curr = curr -> next ;

            }

            // delete min Node

            Node* temp = minNode->prev ;

            minNode -> data = mini ;

            minNode -> prev = minNode -> prev -> prev ;

            if ( minNode -> prev == NULL ) {
                head = minNode ;
            }
            else {
                minNode -> prev -> next = minNode ;
            }

            delete temp ;

        }

        return ops ;
        
    }
};
