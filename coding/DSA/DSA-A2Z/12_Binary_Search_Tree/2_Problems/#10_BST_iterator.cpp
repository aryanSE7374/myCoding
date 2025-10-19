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


// brute

class BSTIterator {
public:
    void bfs(TreeNode* root ,  vector<int>& vec ){

        if(root == NULL) return;

        if(root->left != NULL) bfs(root->left , vec);

        vec.push_back(root->val);

        if(root->right != NULL) bfs(root->right , vec);

    }

    vector<int> inorder;
    int n;
    int i=0;

    BSTIterator(TreeNode* root) {
        bfs(root , inorder);
        n = inorder.size();
    }
    
    int next() {
        return inorder[i++];
    }
    
    bool hasNext() {
        return i<n ;
    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// -------------------------------------------------------------------------------- //

 // striver's optimal solution


class BSTIterator {
    stack<TreeNode*> myStack;

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode* node) {
        for (; node != NULL; myStack.push(node), node = node->left);
    }
};


// -------------------------------------------------------------------------------- //