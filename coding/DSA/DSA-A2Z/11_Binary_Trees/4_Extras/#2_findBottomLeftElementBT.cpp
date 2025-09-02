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
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(i==0){ans = node->val;} // keep updating ans for the first element of each level
                if(node->left!=NULL){q.push(node->left);}
                if(node->right!=NULL){q.push(node->right);}
            }
        }
        return ans;
    }
};