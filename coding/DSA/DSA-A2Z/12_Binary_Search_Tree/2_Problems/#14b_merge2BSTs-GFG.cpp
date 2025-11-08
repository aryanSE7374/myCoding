#include<bits/stdc++.h>
using namespace std;

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
// TC : O(N*logN)
// SC : O(N)

class Solution {
  public:

    void inorder(Node* root , vector<int>& vec) {

        if(root == NULL) return;

        inorder(root->left , vec);

        vec.push_back(root->data);

        inorder(root->right , vec);

    }

    vector<int> merge(Node *root1, Node *root2) {
        
        vector<int> vec1;
        vector<int> vec2;

        inorder(root1 , vec1);
        inorder(root2 , vec2);

        vector<int> res;
        res.reserve(vec1.size()+vec2.size());
        res.insert(res.end() , vec1.begin() , vec1.end());
        res.insert(res.end() , vec2.begin() , vec2.end());

        sort(res.begin() , res.end());

        return res;

    }
};