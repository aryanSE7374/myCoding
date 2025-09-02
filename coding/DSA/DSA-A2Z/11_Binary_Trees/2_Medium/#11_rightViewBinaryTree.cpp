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

// my sol 1 : bfs

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root){return res;}
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){q.push(node->left);}
                if(node->right){q.push(node->right);}
                if(i==size-1){
                    res.push_back(node->val);
                }
            }
        }
        return res;
        
    }
};

// my try 2 : bfs

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root){return res;}
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            TreeNode* node;
            for(int i=0 ; i<size ; i++){
                node = q.front();
                q.pop();
                if(node->left){q.push(node->left);}
                if(node->right){q.push(node->right);}
            }
            res.push_back(node->val);
        }
        return res;
        
    }
};


// striver's solution : recursive/dfs
// idea : reverse preOrder traversal :- Root , Right , Left
// TC : O(N)
// SC : O(H)

class Solution {
public:
    vector<int> res;
    void reversePreOrder(TreeNode* node , int level){
        if(node==NULL){
            return;
        }

        if(level == res.size()){
            res.push_back(node->val);
        }

        reversePreOrder(node->right , level+1);
        reversePreOrder(node->left , level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        reversePreOrder(root , 0);
        return res;
    }
};