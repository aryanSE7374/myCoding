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
    int widthOfBinaryTree(TreeNode* root) {
        
        // level order traversal with null storage
        // constraints : -100 <= Node.val <= 100 hence we use -101 for storing null

        queue<TreeNode*> q;
        // TreeNode* node = root;
        q.push(root);
        // int maxWidth = 1;
        vector<int> level;
        while(!q.empty()){
            int size = q.size();
            level.clear();
            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node==NULL){
                    q.push(NULL);
                    q.push(NULL);
                    level.push_back(-101);
                    continue;
                }

                if(node->left){q.push(node->left);}
                else{q.push(NULL);}

                if(node->right){q.push(node->right);}
                else{q.push(NULL);}

                level.push_back(node->val);
            }
        }

        int i=level.size()-1;
        for( ; i>=0 ; i--){
            if(level[i]>(-101)) break;
        }

        return i+1;

    }
};


// try 2


// levelorder
vector<vector<int>> lastLevel(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==NULL){return ans;}
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0 ; i<size ; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node==NULL) {
                level.push_back(-101);
            }
            else{
                if(node->left!=NULL){q.push(node->left);}
                else{q.push(NULL);}
                if(node->right!=NULL){q.push(node->right);}
                else{q.push(NULL);}
                level.push_back(node->val);
            }
        }
        ans.push_back(level);
    }
    return ans;
}

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        // level order traversal with null storage
        // constraints : -100 <= Node.val <= 100 hence we use -101 for storing null

        vector<vector<int>> vec = lastLevel(root);
        int len = vec.size();

        vector<int> level = vec[len-1];

        int i=level.size()-1;
        for( ; i>=0 ; i--){
            if(level[i]>(-101)) break;
        }

        return i+1;
    }
};
