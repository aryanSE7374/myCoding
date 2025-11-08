#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

// GFG
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// approach 1

class Solution {

  public:

    bool helper(Node* root , int i , int n){

        if(root == NULL) return true;

        if(i>=n) return false;

        else{
            return helper(root->left , 2*i+1 , n) && helper(root->right , 2*i+2 , n);
        }

    }

    int countNodes(Node* root){

        if(root == NULL) return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);

    }
    bool isCompleteTree(Node* root , int nodeCount) {
        // int nodeCount = countNodes(root);
        return helper(root , 0 , nodeCount);
    }

    bool isMaxHeap(vector<int> arr){

        int n  = arr.size();

        for(int i=0 ; i<(n/2) ; i++){
            int l = 2*i + 1;
            int r = 2*i + 2;
            // if(arr[i]<arr[l] || arr[i]<arr[r]) return false;
            if(l < n && arr[i] < arr[l]) return false;
            if(r < n && arr[i] < arr[r]) return false;
        }

        return true;

    }

    void bfs(Node* root , vector<int>& vec){
        // Node* temp = root;
        if(root == NULL) return;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            vec.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }

    }

    bool isHeap(Node* tree) {
        
        int nodeCount = countNodes(tree);
        vector<int> levelOrder;
        bfs(tree , levelOrder);
        return isCompleteTree(tree , nodeCount) && isMaxHeap(levelOrder);
        
    }
};



// approach 2 : love babbar

class Solution {

  public:

    bool helper(Node* root , int i , int n){

        if(root == NULL) return true;

        if(i>=n) return false;

        else{
            return helper(root->left , 2*i+1 , n) && helper(root->right , 2*i+2 , n);
        }

    }

    int countNodes(Node* root){

        if(root == NULL) return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);

    }
    bool isCompleteTree(Node* root , int nodeCount) {
        // int nodeCount = countNodes(root);
        return helper(root , 0 , nodeCount);
    }

    bool isMaxOrder(Node* root){

        if(root == NULL) return true;

        if(root->right == NULL) {
            return ( root->left == NULL) || ( root->data >  root->left->data ) ;
        }

        else {
            return isMaxOrder(root->left) && isMaxOrder(root->right) && ( root->data >  root->left->data ) && ( root->data >  root->right->data ) ;
        }

    }


    bool isHeap(Node* tree) {
        
        int nodeCount = countNodes(tree);
        return isCompleteTree(tree , nodeCount) && isMaxOrder(tree);
        
    }
};

