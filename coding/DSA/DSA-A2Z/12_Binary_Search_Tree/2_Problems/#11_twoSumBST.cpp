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
// TC : O(N)
// SC : O(N) 

 
class Solution {
public:
    void bfs(TreeNode* root , vector<int>& vec){

        if(root == NULL) return;

        bfs(root->left , vec);

        vec.push_back(root->val);

        bfs(root->right , vec);

    }
    bool findTarget(TreeNode* root, int k) {

        vector<int> inorder;

        bfs(root , inorder);

        int l = 0 , r = inorder.size()-1;

        while(l<r){

            if( inorder[l]+inorder[r] == k ) return true;

            if( inorder[l]+inorder[r] < k ) l++;

            else r--;

        }

        return false;

    }
};



// -------------------------------------------------------------------- //

// striver's optimal and clean solution
// TC : O(N)
// SC : O(H) ~ O(logN) in avg case


class BSTIterator {
private:
    stack<TreeNode*> myStack;
    // reverse -> true -> before
    // reverse -> false -> next
    bool reverse = true;

    void pushAll(TreeNode *node) {
        for (;node != NULL; ) {
            myStack.push(node);
            if (reverse == true) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }

public:
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext(){
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if (!reverse) pushAll(tmpNode->right); // reverse->false : next()
        else pushAll(tmpNode->left); // reverse->true : before()
        return tmpNode->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false); // reverse->false : next()
        BSTIterator r(root, true); // reverse->true : before()
        
        int i = l.next();
        int j = r.next();

        while(i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.next();
        }

        return false;
        
    }
};



// -------------------------------------------------------------------- //