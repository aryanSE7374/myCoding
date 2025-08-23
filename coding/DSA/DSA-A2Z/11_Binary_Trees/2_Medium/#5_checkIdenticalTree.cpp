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



// my brute try

// TC : O(m+n)
// SC : O(m+n) + o(m+n) aux space

class Solution {
public:
    void preOrder(TreeNode* root , vector<int>& res ){
        if(root==NULL){
            res.push_back(-100001); // any no. that is out of bounds of constraints
            return;
        }
        res.push_back(root->val);
        preOrder(root->left , res);
        preOrder(root->right , res);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pTraversal;
        vector<int> qTraversal;
        preOrder(p , pTraversal);
        preOrder(q,qTraversal);
        if(pTraversal.size()!=qTraversal.size()){return false;}
        for(int i=0 ; i<pTraversal.size() ; i++){
            if(pTraversal[i]!=qTraversal[i]){return false;}
        }
        return true;
    }
};


class Solution {
public:
    bool p_q_preOrder(TreeNode* p , TreeNode* q , bool& res ){
        if(res && p==NULL && q==NULL){return true;}
        if(res && p==NULL || q==NULL){res=false;return false;}
        // if((res && (p==NULL && q!=NULL)) || (res && (p!=NULL && q==NULL))){return false;}
        // if(!p && !q){
        //     return true;
        // }
        // if(!p || !q){return false;}
        if(res && (p->val != q->val)){res=false;return false;}
        return p_q_preOrder(p->left , q->left,res );
        return p_q_preOrder(p->right , q->right,res );
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res=true;
        return p_q_preOrder(p,q,res);
    }
};


class Solution{
public:
    void preOrder2(TreeNode* p ,TreeNode* q , bool& res ){
        if(!res) return;
        if(!p){
            if(!q){
                return;
            }
            else{
                res = false;
                return;
            }
        }
        if(!q){
            res=false;
            return;
        }
        if(p->val != q->val){res=false;return;}
        preOrder2(p->left , q->left, res);
        preOrder2(p->right , q->right, res);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res = true;
        preOrder2(p,q,res);
        return res;
    }

};


// striver's optimal solution

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q){
            return (p==q);
        }
        return (p->val == q->val) && isSameTree(p->left , q->left) && isSameTree(p->right , q->right);
    }
};