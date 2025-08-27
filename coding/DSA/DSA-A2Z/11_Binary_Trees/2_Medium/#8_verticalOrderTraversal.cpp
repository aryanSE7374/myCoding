#include<bits/stdc++.h>
using namespace std;


// Leetcode

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // why multiset? because in a vertical , on a particular level there could me more than one identical nodes 
        map<int , map<int , multiset<int>>> nodes; // map to store tracersal : [vertical -> [level -> {node}]]
        queue<pair<TreeNode* , pair<int , int>>> todo; // {node , {vertical , level} }
        todo.push({root , {0,0}});

        while (!todo.empty())
        {
            auto p = todo.front(); // queue element 
            todo.pop();

            TreeNode* node = p.first; // node
            int x = p.second.first; // vertical
            int y = p.second.second; // level
            nodes[x][y].insert(node->val); // insert value into the map 

            if(node->left){
                todo.push({node->left , {x-1 , y+1}}); // dec verical , inc level
            } 
            if(node->right){
                todo.push({node->right , {x+1 , y+1}}); // inc vertical , dec level
            } 

        }
        
        vector<vector<int>> res; 
        for(auto p : nodes) {
            // p iterates for vertical as keys
            vector<int> col;
            for (auto q : p.second){
                col.insert(col.end() , q.second.begin() , q.second.end());
            }
            res.push_back(col);
        }

        return res;
        
    }
};