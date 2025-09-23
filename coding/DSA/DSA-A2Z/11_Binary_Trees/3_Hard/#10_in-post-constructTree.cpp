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


// GPT


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return buildTree(postorder, 0, postorder.size() - 1,
                         inorder, 0, inorder.size() - 1, inMap);
    }

private:
    TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        map<int, int>& inMap) {
        if (postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;
        int numsRight = inEnd - inRoot;

        // IMPORTANT: build right subtree first
        root->right = buildTree(postorder, postEnd - numsRight, postEnd - 1,
                                inorder, inRoot + 1, inEnd, inMap);
        root->left = buildTree(postorder, postStart, postStart + numsLeft - 1,
                               inorder, inStart, inRoot - 1, inMap);

        return root;
    }
};


// striver's sol

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size())
            return NULL;

        map<int, int> hm;

        for (int i = 0; i < inorder.size(); ++i)
            hm[inorder[i]] = i;

        return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, hm);
    }

    TreeNode* buildTreePostIn(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int> &hm){
        if (ps > pe || is > ie) return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);

        int inRoot = hm[postorder[pe]];
        int numsLeft = inRoot - is;

        root->left = buildTreePostIn(inorder, is, inRoot - 1,
                                    postorder, ps, ps + numsLeft - 1, hm);

        root->right = buildTreePostIn(inorder, inRoot + 1, ie,
                                     postorder, ps + numsLeft, pe - 1, hm);

        return root;
    }
};


// striver's code version 2

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return buildTree(postorder, 0, postorder.size() - 1,
                         inorder, 0, inorder.size() - 1, inMap);
    }

private:
    TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        map<int, int>& inMap) {
        if (postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(postorder, postStart, postStart + numsLeft - 1,
                               inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(postorder, postStart + numsLeft, postEnd - 1,
                                inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};