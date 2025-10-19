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
    TreeNode* insertIntoBST(TreeNode* root, int x) {
        if(root == NULL){
            root = new TreeNode(x);
            return root;
        }
        TreeNode* curr = root;
        while(curr != NULL){
            if(x <= curr->val){
                if(curr->left != NULL){
                    curr = curr->left;
                }
                else{
                    curr->left = new TreeNode(x);
                    break;
                }
            }
            else{
                if(curr->right != NULL){
                    curr = curr->right;
                }
                else{
                    curr->right = new TreeNode(x);
                    break;
                }
            }
        }
        return root;
    }
};