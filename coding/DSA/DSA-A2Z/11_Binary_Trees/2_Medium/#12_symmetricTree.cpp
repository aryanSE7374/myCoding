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


// my brute try

// TC : O(m+n)
// SC : O(m+n) + o(m+n) aux space


class Solution {
public:
    void preOrderLeft(TreeNode* root , vector<int>& res ){
        if(root==NULL){
            res.push_back(-101); // any no. that is out of bounds of constraints
            return;
        }
        res.push_back(root->val);
        preOrderLeft(root->left , res);
        preOrderLeft(root->right , res);
    }
    void preOrderRight(TreeNode* root , vector<int>& res ){
        if(root==NULL){
            res.push_back(-101); // any no. that is out of bounds of constraints
            return;
        }
        res.push_back(root->val);
        preOrderRight(root->right , res);
        preOrderRight(root->left , res);
    }
    bool isSymmetric(TreeNode* root) {
        vector<int> left , right;
        preOrderLeft(root->left , left);
        preOrderRight(root->right , right);
        if(left.size()!=right.size()){return false;}
        for(int i=0 ; i<left.size() ; i++){
            if(left[i]!=right[i]){return false;}
        }
    }
};



// my optimal try 1

class Solution {
public:
    bool recSymmetricCheck(TreeNode* p , TreeNode* q){
        if(!p || !q){
            return (p==q);
        }
        return (p->val == q->val) && recSymmetricCheck(p->left , q->right) && recSymmetricCheck(p->right , q->left);
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* p = root->left;
        TreeNode* q = root->right;

        if(!p || !q){
            return (p==q);
        }

        return recSymmetricCheck(p,q);
    }
};


// striver' optimal implementation

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return (root == NULL) ? true : isSymmetricHelp(root->left , root->right);
    }
    bool isSymmetricHelp(TreeNode* left , TreeNode* right){
        if(left==NULL || right==NULL){
            return left==right;
        }
        if(left->val != right->val){return false;}
        return isSymmetricHelp(left->left , right->right) && isSymmetricHelp(left->right , right->left);
    }

};