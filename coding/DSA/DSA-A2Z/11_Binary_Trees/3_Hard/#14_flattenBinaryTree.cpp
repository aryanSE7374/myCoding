#include<bits/stdc++.h>
using namespace std;

// Leetcode

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// approach 1 : recursive solution
// can take one more recursion parameter instead of the global variable

class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten (root->right);
        flatten (root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};


// -------------------------------------------------------------------------------- //

// approach 2 : based on morris traveral

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while ( curr != NULL ) {
            if ( curr->left != NULL ) {
                // go to the rightmost node of the LST
                TreeNode* prev = curr->left; // head of LST
                while ( prev->right != NULL ) prev = prev->right;

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                curr = curr->right;
            }
            else {
                curr = curr->right;
            }
        }
    }
};