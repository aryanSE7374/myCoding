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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* node = root;
        vector<int> inorder;
        stack<TreeNode*> st;
        while(true){
            if(node!=NULL){
                st.push(node);
                node = node->left; // LEFT
            }
            else{
                if(st.empty()){break;}
                node = st.top();
                st.pop();
                inorder.push_back(node->val); // ROOT
                node = node->right; // RIGHT
            }
        }
        return inorder;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 