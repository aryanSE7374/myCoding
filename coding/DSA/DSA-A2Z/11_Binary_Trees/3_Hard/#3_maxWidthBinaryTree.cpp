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


// without overflow handling : generates overflow issues


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        // using 0 based segment tree indexing

        if(!root){return 0;}
        long long ans = 0;

        queue< pair<TreeNode* , long long> > q;

        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            // int mmin = q.front().second; // min level idx : to make idx starting from 0
            long long first,last;
            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front().first;
                long long curr_idx = q.front().second;
                q.pop();

                if(i==0){first = curr_idx;}
                if(i==size-1){last = curr_idx;}

                if(node->left){
                    q.push({node->left , (1LL*2*curr_idx) + 1 });
                }
                if(node->right){
                    q.push({node->right , (1LL*2*curr_idx) + 2 });
                }
            }
            ans = max(ans , last - first+1);
        }

        return ans;

    }
};


// optimal code - striver
// overflow handling using mmin

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        // using 0 based segment tree indexing

        if(!root){return 0;}
        int ans = 0;

        queue< pair<TreeNode* , long long> > q;

        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second; // min level idx : to make idx starting from 0
            int first,last;
            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front().first;
                int curr_idx = q.front().second - mmin;
                q.pop();

                if(i==0){first = curr_idx;}
                if(i==size-1){last = curr_idx;}

                if(node->left){
                    q.push({node->left , (1LL*2*curr_idx) + 1 });
                }
                if(node->right){
                    q.push({node->right , (1LL*2*curr_idx) + 2 });
                }
            }
            ans = max(ans , last - first+1);
        }

        return ans;

    }
};
