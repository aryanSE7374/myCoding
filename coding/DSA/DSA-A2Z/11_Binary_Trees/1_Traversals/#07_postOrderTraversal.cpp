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
    void postOrder(TreeNode* root , vector<int>& res ){
        if(root==NULL){
            return;
        }
        postOrder(root->left , res);
        postOrder(root->right , res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postOrder(root , res);
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

    void postOrder(Node* root , vector<int>& res ){
        if(root==NULL){
            return;
        }
        postOrder(root->left , res);
        postOrder(root->right , res);
        res.push_back(root->data);
    }
    
    // Function to return a list containing the postorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        vector<int> res;
        postOrder(root , res);
        return res;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 