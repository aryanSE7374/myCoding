#include<bits/stdc++.h>
using namespace std;

// GFG

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// my solution

class Solution {
  public:

    void helper(Node *root , Node* x , int& ans){

        if(root == NULL ) return;

        if(root->data > x->data){
            ans = min(ans , root->data);
            helper(root->left , x , ans);
        }

        helper(root->right , x , ans);

    }
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        
        int ans = INT_MAX;

        helper(root , x , ans);

        return (ans==INT_MAX)?-1:ans;
        
    }
};


// striver's solution (iterative)

class Solution {
  public:

    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        
        Node* successor = NULL;
        
        while(root != NULL) {
            if(x->data >= root->data) {
                root = root->right;
            }
            else{
                successor = root;
                root = root->left;
            }
        }
        
        return (successor != NULL) ? successor->data : -1;
        
    }
};
