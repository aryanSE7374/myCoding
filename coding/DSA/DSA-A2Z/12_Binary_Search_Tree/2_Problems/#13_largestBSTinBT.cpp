#include<bits/stdc++.h>
using namespace std;

// GFG

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// ------------------------------------------------------------------------------------------ //

// my brute try : wrong approach

/*

class Solution {
  public:

    // Return the size of the largest sub-tree which is also a BST

    void inTraversal(Node* root , vector<int>& vec){

        if(root == NULL) return;

        inTraversal(root->left , vec);

        vec.push_back(root->data);

        inTraversal(root->right , vec);

    }

    int largestBst(Node *root) {
        // Your code here
        vector<int> vec;
        inTraversal(root , vec);

        int n = vec.size();
        
        int l=0 , r=0;
        int maxi = 1;

        while(r<n){
            if(vec[l]<=vec[r]){
                r++;
                maxi = max(maxi , r-l+1);
            }
            else{
                l=r;
                r++;
            }
        }

        return maxi;
        
    }
};

*/

// ------------------------------------------------------------------------------------------ //

// brute idea : 


class Solution {
  public:

    // Helper to check if a subtree is a valid BST
    bool isValidBST(Node* root, long long minVal, long long maxVal) {
        if (root == NULL) return true;
        
        if (root->data <= minVal || root->data >= maxVal)
            return false;
        
        return isValidBST(root->left, minVal, root->data) &&
               isValidBST(root->right, root->data, maxVal);
    }

    // Helper to count nodes in a subtree
    int countNodes(Node* root) {
        if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Main recursive function to find largest BST
    int largestBst(Node *root) {
        if (root == NULL) return 0;

        // If current subtree is a BST, return its size
        if (isValidBST(root, LLONG_MIN, LLONG_MAX))
            return countNodes(root);

        // Otherwise, find in left and right subtrees
        return max(largestBst(root->left), largestBst(root->right));
    }
};

// ------------------------------------------------------------------------------------------ //

// editorial based optimal solution

class Solution {
private:
    struct NodeValue {
        int maxNode;
        int minNode;
        int maxSize;

        NodeValue(int minVal, int maxVal, int size) {
            this->minNode = minVal;
            this->maxNode = maxVal;
            this->maxSize = size;
        }
    };

    NodeValue largestBstHelper(Node* root) {
        // An empty tree is a BST of size 0.
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // Get values from left and right subtree of current tree.
        NodeValue left = largestBstHelper(root->left);
        NodeValue right = largestBstHelper(root->right);

        // Current node is greater than max in left and smaller than min in right, it is a BST
        if (left.maxNode < root->data && root->data < right.minNode) {
            // It is a BST.
            return NodeValue(
                min(root->data, left.minNode), 
                max(root->data, right.maxNode), 
                left.maxSize + right.maxSize + 1
            );
        }

        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return NodeValue(
            INT_MIN, 
            INT_MAX, 
            max(left.maxSize, right.maxSize)
        );
    }

public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        return largestBstHelper(root).maxSize;
    }
};



// ------------------------------------------------------------------------------------------ //
