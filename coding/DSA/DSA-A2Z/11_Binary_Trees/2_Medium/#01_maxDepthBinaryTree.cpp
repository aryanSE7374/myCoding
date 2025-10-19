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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        return 1 + max( maxDepth(left) , maxDepth(right) );
    }
};

// another way

class Solution{
    public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        return 1 + max(  leftHeight , rightHeight);
    }
};