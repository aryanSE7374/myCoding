#include<bits/stdc++.h>
using namespace std;

// Leetcode

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};


// my try 1 : passed

class Solution {
public:
    void bfs(TreeNode* root , TreeNode* p , TreeNode* q , TreeNode* &ans){

        // if( root == NULL ) return ;

        if( root == p || root == q ) {
            ans = root;
            return;
        }

        else if( ( p->val < root->val && q->val < root->val ) ){
            bfs(root->left , p , q , ans);
        }

        else if( ( p->val > root->val && q->val > root->val ) ){
            bfs(root->right , p , q , ans);
        }

        else {
            ans = root;
            return;
        }

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        bfs(root,p,q,ans);
        return ans;
    }
};


// striver's solution


class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL) return NULL;

        int curr = root->val;

        if( (p->val < curr)&&(q->val < curr) ){
            return lowestCommonAncestor(root->left , p , q);
        }

        if( (p->val > curr)&&(q->val > curr) ){
            return lowestCommonAncestor(root->right , p , q);
        }

        return root;

    }
};