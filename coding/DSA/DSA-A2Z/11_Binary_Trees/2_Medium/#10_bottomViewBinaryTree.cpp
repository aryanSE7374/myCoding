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


class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        map<int , int> nodes; // map to store tracersal : [vertical -> node]
        queue<pair<Node* , int>> todo; // { node , vertical }
        todo.push({root , 0}); // { root , 0th vertical }

        while (!todo.empty())
        {
            auto p = todo.front(); // queue element 
            todo.pop();

            Node* node = p.first; // node
            int x = p.second; // vertical
            
            // keep uptdating the node map value , if it is note seen yet the create a new one
            nodes[x] = node->data; 

            if(node->left){
                todo.push({node->left , x-1}); // dec verical 
            } 
            if(node->right){
                todo.push({node->right , x+1}); // inc vertical 
            } 

        }
        
        vector<int> res; 
        for(auto p : nodes){
            res.push_back(p.second);
        }
        return res;
        
    }
};
