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
    void inOrder(TreeNode* root , vector<int>& res ){
        if(root==NULL){
            return;
        }
        inOrder(root->left , res);
        res.push_back(root->val);
        inOrder(root->right , res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inOrder(root , res);
        return res;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// GFG

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



class Solution {
  public:
      void inOrder(Node* root , vector<int>& res ){
            if(root==NULL){
                return;
            }
            inOrder(root->left , res);
            res.push_back(root->data);
            inOrder(root->right , res);
        }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> res;
        inOrder(root , res);
        return res;
        
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 