#include<bits/stdc++.h>
using namespace std;

// GFG
// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


// my try 1

class Solution {
  public:
    bool bfs(Node* root){
        if(root==NULL){return true;}

        if(!root->left && !root->right){return true;}
        
        int left = root->left ? root->left->data : 0;
        int right = root->right ? root->right->data : 0;
        

        if(root->data != left + right){
            return false;
        }

        return bfs(root->left) && bfs(root->right);

    }
    int isSumProperty(Node *root) {
        
        if(!root->left && !root->right){return 1;}
        
        return bfs(root) ? 1 : 0;

    }
};