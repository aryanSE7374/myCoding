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



// try 1 : fail

class Solution {
public:
    void bfs(TreeNode* root , bool& ans){

        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL){
            return;
        }

        if( (root->left!=NULL && root->left->val >= root->val) ||  ( root->right!=NULL && root->right->val <= root->val ) ) {
            ans = false;
        }


        bfs(root->left , ans);
        bfs(root->right , ans);

    }

    bool isValidBST(TreeNode* root) {
        bool ans = true;
        bfs(root , ans);
        return ans;
    }
};



// try 2 : pass


class Solution {
public:
    void bfs(TreeNode* root , vector<int>& ans){

        if(root == NULL) return;

        bfs(root->left , ans);

        ans.push_back(root->val);

        bfs(root->right , ans);

    }

    bool isValidBST(TreeNode* root) {

        vector<int> ans;
        bfs(root , ans);

        int n = ans.size();

        if(n==1) return true;
        for(int i=1 ; i<n ; i++ ){
            if(ans[i-1]>=ans[i]) return false;
        }
        return true;
        
    }
};


// try 3 : using hints - passed
// complex and verbose implementation


class Solution {
public:
    bool bfs(TreeNode* root , long long l , long long r){

        if(root == NULL) return true;

        if(root->left == NULL && root->right == NULL){
            return true;
        }

        if( ( root->left!=NULL && ( ( root->left->val >= root->val )  || (  l >= root->left->val ) ) ) ||  
        ( root->right!=NULL && ( ( root->right->val <= root->val ) || (  r <= root->right->val ) ) ) 
        ) {
            return false;
        }


        return bfs(root->left , l , root->val) && bfs(root->right , root->val , r);

    }

    bool isValidBST(TreeNode* root) {
        return bfs(root , LLONG_MIN , LLONG_MAX);
    }
};



// striver's optimized clean solution

class Solution {
public:
    bool bfs(TreeNode* root , long long l , long long r){

        if(root == NULL) return true;

        if( ( root->val <= l ) || ( root->val >= r ) ) return false;

        return bfs(root->left , l , root->val) && bfs(root->right , root->val , r);

    }

    bool isValidBST(TreeNode* root) {
        return bfs(root , LLONG_MIN , LLONG_MAX);
    }
};
