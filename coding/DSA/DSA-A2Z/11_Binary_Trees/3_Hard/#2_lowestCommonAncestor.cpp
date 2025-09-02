// LCA

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



// my solution try 1 : accepted

// TC : O(3*N)
// SC : O(2*N) -> 2N extra space to store the paths


class Solution {
public:

    bool getPath(TreeNode *root ,  TreeNode* x , vector<TreeNode*> &res ){
        
        if(root==NULL){
            return false;
        }
        
        res.push_back(root);

        if(root == x){
            return true;
        }

        if( getPath(root->left , x , res) || getPath(root->right , x , res)){
            return true;
        }

        res.pop_back();

        return false;

    }


    vector<TreeNode*> pathToNode(TreeNode *root, TreeNode* x)
    {
        vector<TreeNode*> res;
        getPath(root , x , res );
        return res;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vec1 = pathToNode(root , p);
        vector<TreeNode*> vec2 = pathToNode(root , q);
        int len = min(vec1.size() , vec2.size());
        int i = 0;
        while(i<len){
            if(vec1[i]!=vec2[i]){
                break;
            }
            i++;
        }
        return vec1[i-1];
    }
};



// optimal try : accepted
// TC : O(N)
// SC : O(N)



class Solution {
public:

    TreeNode* LCA(TreeNode* root , TreeNode* p , TreeNode* q){
        
        if(root == NULL){return NULL;}

        if(root == p || root == q){return root;}


        TreeNode* leftLCA = LCA(root->left , p , q);
        TreeNode* rightLCA = LCA(root->right , p , q);

        if ( !leftLCA && !rightLCA ){return NULL;} // both are NULL

        if(leftLCA!=NULL && rightLCA!=NULL){ return root; } // both not NULL

        else return (leftLCA!=NULL) ? leftLCA : rightLCA; // exactly one not NULL

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root , p , q);
    }
};



// striver's optimal solution

// TC : O(N)
// SC : O(N)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if( root == NULL || root == p || root == q ){ return root; }

        TreeNode* left = lowestCommonAncestor(root->left , p , q);
        TreeNode* right = lowestCommonAncestor(root->right , p , q);

        if(left == NULL){ 
            return right;
        }

        else if(right == NULL){
            return left;
        }

        else return root; // both are not NULL => we found our LCA

    }
};

