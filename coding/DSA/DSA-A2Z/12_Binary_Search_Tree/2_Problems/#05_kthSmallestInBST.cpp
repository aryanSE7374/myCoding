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

// Time: O(N*logN) 
// Space: O(N)


class Solution {
public:
    void bfs(TreeNode* root , set<int>& stt){
        if(root == NULL) return;
        stt.insert(root->val);

        bfs(root->left , stt);
        bfs(root->right , stt);

    }
    int kthSmallest(TreeNode* root, int k) {
        set<int> stt;
        bfs(root , stt);
        for(auto &it : stt){
            k--;
            if(k==0) return it;
        }
        return -1;
    }
};


// my  optimal try : passed

// Time: O(H + K) ≈ O(N) in worst case, since traversal can stop early.
// Space: O(H) recursion stack (H = height of BST).



class Solution {
public:
    void bfs(TreeNode* root , int k , int& cnt , int& ans){

        // slight optimization 
        // if (!root || cnt >= k) return;
        if(root == NULL) return;

        bfs(root->left , k , cnt , ans);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        bfs(root->right , k , cnt , ans);

    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int cnt = 0;
        bfs(root , k , cnt ,  ans);
        return ans;
    }
};




// strier's solution

// Optimized solution (uses inorder & reverse inorder traversal)
class Solution {
private:
    // Helper: inorder traversal → Kth smallest
    void inorder(TreeNode* node, int& counter, int k, int& ans) {
        if (!node || counter >= k) return;

        inorder(node->left, counter, k, ans);
        counter++;
        if (counter == k) {
            ans = node->val;
            return;
        }
        inorder(node->right, counter, k, ans);
    }

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
    // Returns Kth smallest element in BST
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        int counter = 0;
        inorder(root, counter, k, ans);
        return ans;
    }

    // Returns Kth largest element in BST
    int kthLargest(TreeNode* root, int k) {
        int ans = -1;
        int counter = 0;
        reverseInorder(root, counter, k, ans);
        return ans;
    }
};


// Advanced : moris traversal based solution O(N) time and O(1) Space

 
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, ans = -1;
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                cnt++;
                if (cnt == k) ans = curr->val;
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = curr; // thread link
                    curr = curr->left;
                } else {
                    pred->right = NULL;
                    cnt++;
                    if (cnt == k) ans = curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

// ---------------------------------------------------------------------------------------------------------- //




// NOTE : follow-up - find the kth largest element = find (N-k)th Smallest Element

