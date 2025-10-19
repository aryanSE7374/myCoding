#include<bits/stdc++.h>
using namespace std;

// GFG

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

/*

•	Time: O(h) where h = height of BST (≈ O(log n) for balanced, O(n) for skewed)
•	Space: O(h) recursive stack

*/

// my try 1 : passed

class Solution {
  public:
    void helperSucc(Node *root , int x , Node*& ans){

        if(root == NULL ) return;

        if(root->data > x){
            if( ans == NULL || root->data < ans->data){
                ans = root;
            }
            // ans = (root->data < ans->data) ? root : ans;
            // ans = min(ans , root->data);
            helperSucc(root->left , x , ans);
        }

        helperSucc(root->right , x , ans);

    }

    void helperPred(Node *root , int x , Node*& ans){

        if(root == NULL ) return;

        if(root->data < x){
            if( ans == NULL || root->data > ans->data){
                ans = root;
            }
            // ans = (root->data > ans->data) ? root : ans;
            // ans = max(ans , root->data);
            helperPred(root->right , x , ans);
        }

        helperPred(root->left , x , ans);

    }

    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node* inOrderSuccessor(Node *root, int x) {
        
        Node* ans = NULL;

        helperSucc(root , x , ans);

        return ans;
        
    }

    // returns the inorder predecessor of the Node x in BST (rooted at 'root')
    Node* inOrderPredecessor(Node *root, int x) {
        
        Node* ans = NULL;

        helperPred(root , x , ans);

        return ans;
        
    }

    vector<Node*> findPreSuc(Node* root, int key) {

        vector<Node*> vec(2 , NULL);

        vec[0] = inOrderPredecessor(root , key);
        vec[1] = inOrderSuccessor(root , key);;
        
        return vec;
        
    }
};