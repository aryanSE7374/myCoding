#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// my try1

class Solution {
public:

    void treeHelper(vector<int>& preorder, vector<int>& inorder , unordered_map<int , int>& inMap , int l1 , int l2 , int len ,TreeNode* root){
        // if(!root){
        //     return;
        // }
        if(len==0){
            return;
        }
        if(len==1){
            root->val = preorder[l1];
            return;
        }
        // int root_val = preorder[l];
        root->val = preorder[l1];
        int pre_idx = l1;
        int in_idx = inMap[preorder[l1]];

        int lenLeft = in_idx-l2;
        int lenRight = len-lenLeft-1;


        if(lenLeft>0){
            root->left = new TreeNode();
            treeHelper(preorder,inorder,inMap,pre_idx+1,l2,lenLeft,root->left);
        }

        if(lenRight>0){
            root->right = new TreeNode();
            treeHelper(preorder,inorder,inMap,pre_idx+lenLeft+1,in_idx+1,lenRight,root->right);
        }

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        TreeNode* root = new TreeNode();
        int n = preorder.size();

        unordered_map<int , int> inMap;

        for(int i=0 ; i<n ; i++){
            inMap[inorder[i]] = i;
        }

        treeHelper(preorder, inorder , inMap,  0 , 0 , n , root);
        return root;
    }
};



// striver's clean solution

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1,
                                   inorder, 0, inorder.size() - 1, inMap);
        return root;
    }

private:
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        map<int, int>& inMap) {
        if (preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft,
                               inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd,
                                inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};

// can also use unirdered map here

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1,
                                   inorder, 0, inorder.size() - 1, inMap);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        unordered_map<int, int>& inMap) {
        if (preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft,
                               inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd,
                                inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};