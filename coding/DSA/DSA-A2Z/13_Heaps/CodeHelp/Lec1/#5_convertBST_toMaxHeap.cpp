#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
// GFG

struct Node {
    int data;
    Node *left, *right;
};


// try 1 : failed


class Solution {
  public:
  void inorder(Node* root , vector<int>& vec){

    if(!root){
        return;
    }

    inorder(root->left ,vec);
    vec.push_back(root->data);
    inorder(root->right ,vec);

  }
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        vector<int> vec;
        inorder(root , vec);

        priority_queue<int> pq(vec.begin() , vec.end());

        int n = vec.size();
        delete(root->left);
        delete(root->right);
         
        root->left = NULL;
        root->right = NULL;
        

        queue<Node*> q;
        root->data = vec[0];
        q.push(root);
        int i=0;
        while(!q.empty() && i<n){

            Node* node = q.front();
            q.pop();

            
            i++;
            if(i<n){
                node->left = new Node();
                node->left->data = vec[i];
            }
            
            i++;

            
            if(i<n){
                node->right = new Node();
                node->right->data = vec[i];
            }

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

        }

    }
};

// --------------------------------------------------------------------------- //

// try 2 : failed

class Solution {
  public:

    void inorder(Node* root , vector<int>& vec){

        if(!root){
            return;
        }

        inorder(root->left ,vec);
        vec.push_back(root->data);
        inorder(root->right ,vec);

    }

    void postOrderHelper(Node* root , vector<int>& vec , int n , int i){

        if(root == NULL) return;

        root->data = vec[i];
        postOrderHelper(root->left,vec,n,2*i+1);
        postOrderHelper(root->right,vec,n,2*i+2);

    }

    void convertToMaxHeapUtil(Node* root) {

        vector<int> vec;
        inorder(root , vec);

        priority_queue<int> pq(vec.begin() , vec.end());

        int n = vec.size();

        // for(int i=0 ; i<n ; i++){
        //     vec[i] = pq.top();
        //     pq.pop();
        // }

        postOrderHelper(root,vec,n,0);

    }
};

// --------------------------------------------------------------------------- //

// try 3 : correct and optimal solution

class Solution {
  public:

    void inorder(Node* root , vector<int>& vec){

        if(!root){
            return;
        }

        inorder(root->left ,vec);
        vec.push_back(root->data);
        inorder(root->right ,vec);

    }

    void postOrderHelper(Node* root , vector<int>& vec , int& i){

        if(root == NULL) return;

        postOrderHelper(root->left,vec,i);
        postOrderHelper(root->right,vec,i);
        root->data = vec[i++];

    }

    void convertToMaxHeapUtil(Node* root) {

        vector<int> vec;
        inorder(root , vec);

        int n = vec.size();

        int i=0;
        postOrderHelper(root,vec,i);

    }
};


// --------------------------------------------------------------------------- //