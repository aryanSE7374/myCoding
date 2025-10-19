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


// NOTE : follow-up - find the kth largest element = find (N-k)th Smallest Element



// strier's solution

// Optimized solution (uses inorder & reverse inorder traversal)
class Solution {
private:

    // Helper: reverse inorder traversal → Kth largest
    void reverseInorder(TreeNode* node, int& counter, int k, int& ans) {
        if (!node || counter >= k) return;

        reverseInorder(node->right, counter, k, ans);
        counter++;
        if (counter == k) {
            ans = node->val;
            return;
        }
        reverseInorder(node->left, counter, k, ans);
    }

public:

    // Returns Kth largest element in BST
    int kthLargest(TreeNode* root, int k) {
        int ans = -1;
        int counter = 0;
        reverseInorder(root, counter, k, ans);
        return ans;
    }
};

