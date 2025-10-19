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

// brute solution
// TC : O(N^2)
// SC : O(N) {skewed tree case}

int maxDepth(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    return 1 + max( maxDepth(left) , maxDepth(right) );
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){return true;}
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        if( abs(leftHeight-rightHeight) > 1 ){
            return false;
        }
        bool isLeft = isBalanced(root->left);
        bool isRight = isBalanced(root->right);

        if(!isLeft || !isRight){return false;}

        return true;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// optimal solution
// TC : O(N)
// SC : O(N) {skewed tree case}

int dfsHeight(TreeNode* root) {

    if(root == NULL){
        return 0;
    }

    int leftHeight = dfsHeight(root->left);
    if(leftHeight == -1){return -1;}

    int rightHeight = dfsHeight(root->right);
    if(rightHeight == -1){return -1;}

    if( abs(leftHeight-rightHeight) > 1 ){
        return -1;
    }

    return 1 + max(  leftHeight , rightHeight);

}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
       return !( dfsHeight(root) == -1 ) ;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 