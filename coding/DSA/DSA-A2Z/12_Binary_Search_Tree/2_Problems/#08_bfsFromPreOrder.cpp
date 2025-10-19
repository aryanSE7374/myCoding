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


// my try 1

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


    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> inorder(n,0);
        for(int i=0 ; i<n ; i++){
            inorder[i] = preorder[i];
        }
        sort(inorder.begin() , inorder.end());

        TreeNode* root = buildTree(preorder , inorder);

        return root;

    }
};



// striver's optimal solution
// TC : O(3*N) - a node is processed 3 times during traversal
// SC : O(H)
 
class Solution {
public:

    // helper function
    TreeNode* build(vector<int>& pre , int& i , int bound){

        if(i==pre.size() || pre[i]>bound) return NULL;

        TreeNode* root = new TreeNode(pre[i++]);

        root->left = build(pre , i , root->val);

        root->right = build(pre , i , bound);

        return root;

    }

    // main function

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder , i , INT_MAX);
    }
};

