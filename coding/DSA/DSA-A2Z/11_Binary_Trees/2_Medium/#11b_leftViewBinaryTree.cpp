#include<bits/stdc++.h>
using namespace std;

// GFG
// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

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

// try 1

class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> res;
        if(!root){return res;}
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();

            Node* node = q.front();
            q.pop();

            res.push_back(node->data);

            if(node->left){q.push(node->left);}
            if(node->right){q.push(node->right);}

            for(int i=1 ; i<size ; i++){
                node = q.front();
                q.pop();
                if(node->left){q.push(node->left);}
                if(node->right){q.push(node->right);}
            }
        }
        return res;
        
    }
};

// try 2 : more cleaner

class Solution {
  public:
    vector<int> leftView(Node *root) {

        vector<int> res;
        if(!root){return res;}
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            Node* node;
            for(int i=0 ; i<size ; i++){
                node = q.front();
                q.pop();
                if(i==0){res.push_back(node->data);}
                if(node->left){q.push(node->left);}
                if(node->right){q.push(node->right);}
            }
        }
        return res;
        
    }
};



// striver's idea of dfs/recursive appraoch

class Solution {
  public:
    vector<int> res;
    void reversePreOrder(Node* node , int level){
        if(node==NULL){
            return;
        }

        if(level == res.size()){
            res.push_back(node->data);
        }

        reversePreOrder(node->left , level+1);
        reversePreOrder(node->right , level+1);
    }
    vector<int> leftView(Node *root) {

        reversePreOrder(root , 0);
        return res;
        
    }
};