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

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> preorder;
        TreeNode* curr = root;

        while ( curr != NULL ) {
            if ( curr->left == NULL ) {
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* prev = curr->left;
                while ( prev->right != NULL && prev->right != curr ) {
                    prev = prev->right;
                }

                if (prev->right == NULL ) {
                    prev->right = curr; // add the thread
                    preorder.push_back(curr->val); // process the node first, then explore left
                    curr = curr->left;
                } 
                else { // prev->right == curr
                    prev->right = NULL; // release the thread
                    curr = curr->right;
                }
            }
        }

        return preorder;

    }
};