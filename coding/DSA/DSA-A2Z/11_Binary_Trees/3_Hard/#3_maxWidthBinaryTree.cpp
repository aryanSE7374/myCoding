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


// aniket's solution

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        queue< unsigned long long> q1;
        queue<TreeNode*> q2;
        q1.push(0);
        q2.push(root);

        unsigned long long int maxi=1;

        while(q2.size()>0){

            unsigned long long int size=q2.size();
            unsigned long long int left,right;

            for(long long int i=0; i<size; i++){
            
                if(i==0){
                    left=q1.front();
                }

                if(i==size-1){
                    right=q1.front();
                }

                TreeNode* temp=q2.front();
                unsigned long long int value=q1.front();
                q1.pop();
                q2.pop();

                if(temp->left){
                    q2.push(temp->left);
                    q1.push(2*value);
                }

                if(temp->right){
                    q2.push(temp->right);
                    q1.push(2*value+1);
                }
            }

            maxi=max(maxi,right-left+1);
            // unnecessary condition check : optimization to prevent index overflow.
            // if(q2.size()==1){
            //     q1.pop();
            //     q1.push(1);
            // }
        }

        return maxi;
        
    }
};

