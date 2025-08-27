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

// my try 1
// TC : O(N+N) {extra N because of reverse on all alterating levels}
// SC : O(N+N) ~ O(N) {N to store result + N to store temp level list result}

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL){return res;}
        queue<TreeNode*> q;
        q.push(root);
        bool directionFlag = true; // true meres left to right
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL){q.push(node->left);}
                if(node->right!=NULL){q.push(node->right);}
                level.push_back(node->val);
            }
            if(directionFlag){
                res.push_back(level);
            }
            else{
                reverse(level.begin() , level.end());
                res.push_back(level);
            }
            directionFlag = !directionFlag;
        }
        return res;
    }
};


// striver's optimal solution
// TC : O(N) {no reversal needed , solved in just and exactly one traversal}
// SC : O(N+N) ~ O(N) {but sloghtly better because of no temporary traversal}

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL){return res;}
        queue<TreeNode*> q;
        q.push(root);
        bool directionFlag = true; // true meres left to right
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                int index = (directionFlag)?i:size-1-i;
                level[index] = node->val;
                // level.push_back(node->val);
                if(node->left!=NULL){q.push(node->left);}
                if(node->right!=NULL){q.push(node->right);}
            }
            res.push_back(level);
            directionFlag = !directionFlag;
        }
        return res;
    }
};