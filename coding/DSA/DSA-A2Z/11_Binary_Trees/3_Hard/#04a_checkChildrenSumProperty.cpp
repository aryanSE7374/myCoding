#include<bits/stdc++.h>
using namespace std;

// GFG
// https://www.geeksforgeeks.org/problems/children-sum-parent/1

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


// my try 1 : accepted

class Solution {
  public:
    bool dfs(Node* root){
        if(root==NULL){return true;}

        if(!root->left && !root->right){return true;}
        
        int left = root->left ? root->left->data : 0;
        int right = root->right ? root->right->data : 0;
        

        if(root->data != left + right){
            return false;
        }

        return dfs(root->left) && dfs(root->right);

    }
    int isSumProperty(Node *root) {
        
        if(!root->left && !root->right){return 1;}
        
        return dfs(root) ? 1 : 0;

    }
};

// ------------------------------------------------------------------------------------------ //

// try 2

class Solution {
  public:
    bool isLeaf(Node* node) {
        return (!node->left && !node->right);
    }
    bool isSumProperty(Node *root) {
        if ( root == NULL || isLeaf(root) ) return true;
        
        int lVal = (root->left) ? root->left->data : 0;
        int rVal = (root->right) ? root->right->data : 0;
        
        if ( lVal + rVal != root->data ) return false;
        
        return isSumProperty(root->left) && isSumProperty(root->right);
        
    }
};


// ------------------------------------------------------------------------------------------ //