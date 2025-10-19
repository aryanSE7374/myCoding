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

    void preOrder(TreeNode* root , vector<int>& res ){
        if(root==NULL){
            return;
        }
        res.push_back(root->val);
        preOrder(root->left , res);
        preOrder(root->right , res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preOrder(root , res);
        return res;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// GeeksForGeeks


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    void preOrder(Node* root , vector<int>& res ){
        if(root==NULL){
            return;
        }
        res.push_back(root->data);
        preOrder(root->left , res);
        preOrder(root->right , res);
    }

    vector<int> preorder(Node* root) {
        vector<int> res;
        preOrder(root , res);
        return res;
        
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 