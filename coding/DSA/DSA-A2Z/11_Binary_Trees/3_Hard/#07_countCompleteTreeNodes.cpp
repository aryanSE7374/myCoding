#include<bits/stdc++.h>
using namespace std;

// variation :  root to leaf path

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



// brute solution
class Solution {
public:
    int dfs(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1+dfs(root->left)+dfs(root->right);
    }
    int countNodes(TreeNode* root) {
        return dfs(root);
    }
};


// better than O(N) Time

class Solution {
public:
    int findLeftHeight(TreeNode* root){
        TreeNode* node = root;
        int height = 0;
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }
    int findRightHeight(TreeNode* root){
        TreeNode* node = root;
        int height = 0;
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        // optional in the given constraints
        // if(root==NULL){
        //     return 0;
        // }
        
        int left = findLeftHeight(root);
        int right = findRightHeight(root);

        if(left == right){
            return (1<<left);
        }

        else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};