#include<bits/stdc++.h>
using namespace std;

// max element -> return root

// min element -> GFG
// return the extreme left node


// mini : GFG

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

class Solution {
  public:
    int minValue(Node* root) {
        Node* curr = root;
        while ( curr->left != NULL ) curr = curr->left;
        return curr->data;
    }
};