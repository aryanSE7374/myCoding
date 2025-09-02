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


// my try 1 : solved

class Solution {
public:
    void dfs(TreeNode* node , string str , vector<string>& vec){
        if(node==NULL){return;}
        if(node->left==NULL && node->right==NULL){
            str+=to_string(node->val);
            vec.push_back(str);
            return;
        }
        dfs(node->left , str+to_string(node->val)+"->" , vec);
        dfs(node->right , str+to_string(node->val)+"->" , vec);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        dfs(root , "" , vec );
        return vec;

    }
};



// GFG style

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

// my try 1 : passed

class Solution {
  public:
    void dfs(Node* node , vector<int>& path , vector<vector<int>>& vec){
        if(node==NULL){return;}
        if(node->left==NULL && node->right==NULL){
            path.push_back(node->data);
            vec.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(node->data);
        dfs(node->left , path , vec);
        path.pop_back();
        path.push_back(node->data);
        dfs(node->right , path, vec);
        path.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> vec;
        vector<int> path = {};
        dfs(root , path , vec );
        return vec;
    }
};