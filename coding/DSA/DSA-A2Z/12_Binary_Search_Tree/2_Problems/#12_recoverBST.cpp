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

 

// brute sol

class Solution {
public:

    void bfs(TreeNode* root , int x , TreeNode*& node){

        if(root == NULL) return;

        if(root->val == x){
            node = root;
            return ;
        }

        bfs(root->left , x , node);

        bfs(root->right , x , node);

    }

    void inTraversal(TreeNode* root , vector<int>& vec){

        if(root == NULL) return;

        inTraversal(root->left , vec);

        vec.push_back(root->val);

        inTraversal(root->right , vec);

    }

    void recoverTree(TreeNode* root) {

        vector<int> inorder;

        inTraversal(root , inorder);

        vector<int> incopy = inorder;

        sort(incopy.begin() , incopy.end());

        vector<int> v;

        int n = inorder.size();
        for(int i=0 ; i<n ; i++){
            if(incopy[i]!=inorder[i]) v.push_back(inorder[i]);
        }

        int x1 = v[0];
        int x2 = v[1];

        TreeNode* node1 ;
        TreeNode* node2 ;

        bfs(root , x1 , node1);
        bfs(root , x2 , node2);

        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;

    }
};


// ------------------------------------------------------------------------------------------ //

// striver's optimal solution
// TC : O(N)
// SC : O(H) ~ stack space for recursion calls

class Solution {
private:

    TreeNode* first; // first violation
    TreeNode* prev; // stores prev node to compare with
    TreeNode* middle; // adjacent to first
    TreeNode* last; // second violation

private:
    void inorder(TreeNode* root) {

        if (root == NULL) return;

        inorder(root->left);

        if (prev != NULL && (root->val < prev->val))
        {
            if ( first == NULL ) // if first violation
            {
                first = prev;
                middle = root;
            }
            else // last/second violation
                last = root;
        }

        prev = root;
        inorder(root->right);

    }
public:
    void recoverTree(TreeNode* root) {

        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);

        inorder(root);

        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};


// ------------------------------------------------------------------------------------------ //