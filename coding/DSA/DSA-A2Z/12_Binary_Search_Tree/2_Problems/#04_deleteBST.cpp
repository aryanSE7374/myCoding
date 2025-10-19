#include<bits/stdc++.h>
using namespace std;

// Leetcode

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

// try

class Solution {
public:

    void deleteNodeLeft(TreeNode* curr){

    }

    void deleteNodeRight(TreeNode* curr){
        
    }

    TreeNode* deleteNode(TreeNode* root, int key){
        int x = key;

        if(root->val == x ){
            delete root;
            return NULL;
        } 

        TreeNode* curr = root;

        while( curr->left != NULL || curr->right != NULL ){
            
            if(curr->left->val == x){
                
            }

            if(curr->right->val == x){

            }


        }

    }
};

// striver's code

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key){
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            return helper(root);
        }

        TreeNode* dummy = root;
        while(root != NULL){
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        } 
        else if(root->right == NULL){
            return root->left;
        }

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        return findLastRight(root->right);
    }
};



// my modifications : more readable version

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key){

        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            return helper(root);
        }

        TreeNode* curr = root;

        while(curr != NULL){

            if( curr->left && curr->left->val == key){
                curr->left = helper(curr->left);
                return root;
            }

            if( curr->right && curr->right->val == key){
                curr->right = helper(curr->right);
                return root;
            }

            if(curr->val > key) curr = curr->left;

            else curr = curr->right;

        }

        return root;

    }

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        } 
        else if(root->right == NULL){
            return root->left;
        }

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        return findLastRight(root->right);
    }
};