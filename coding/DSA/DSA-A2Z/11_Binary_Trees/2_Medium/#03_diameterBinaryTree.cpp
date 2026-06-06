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


int maxDepth(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    return 1 + max(  leftHeight , rightHeight);
}

// my brute try
// TC : O(N^2)
// SC : O(N)

int findDiameter(TreeNode* root){
    if(root == NULL){return 0;}
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    return leftHeight + rightHeight;
}

int maxOf3(int a , int b , int c){
    if( (a>b) && (a>c)){return a;}
    else if(b>c){return b;}
    else return c;
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){ return 0;}
        return maxOf3(findDiameter(root) , diameterOfBinaryTree(root->left) , diameterOfBinaryTree(root->right));
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// my brute force 2
// TC : O(N^2)
// SC : O(N)

class Solution {
public:

    int height (TreeNode* node) {
        if (!node) return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        return 1 + max (lh, rh);
    }

    void updateMaxi(TreeNode* root, int& maxi) {
        if ( !root ) return;
        int lh = height(root->left);
        int rh = height(root->right);
        maxi = max (maxi, lh + rh);
        updateMaxi(root->left, maxi);
        updateMaxi(root->right, maxi);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        updateMaxi(root, maxi);
        return maxi;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// striver's brute solution
// TC : O(N^2)
// SC : O(N)

class Solution {
public:
    int maxi = 0;
    void updateMaxi(TreeNode* root){
        if(root == NULL){ return;}

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        maxi = max(maxi , leftHeight  + rightHeight);

        updateMaxi(root->left);
        updateMaxi(root->right);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        updateMaxi(root);
        return maxi;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 


// striver's optimal solution
// TC : O(N)
// SC : O(N)

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findHeight(root , diameter);
        return diameter;
    }
    int findHeight(TreeNode* root , int& diameter ){
        if(!root){return 0;}
        int leftHeight = findHeight(root->left , diameter);
        int rightHeight = findHeight(root->right , diameter);
        diameter = max(diameter , leftHeight + rightHeight); // update diameter
        return 1 + max(leftHeight , rightHeight);
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 