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

// ------------------------------------------------------------------------------------------------------------ // 

// other methods

// 1- dfs based code : 

class Solution {
public:

    void dfs ( TreeNode* root, int x_idx, int lvl, map<int, map<int, vector<int>>>& mpp ) {

        if ( root == NULL ) return;

        mpp[x_idx][lvl].push_back(root->val);

        dfs(root->left, x_idx - 1, lvl + 1, mpp);
        dfs(root->right, x_idx + 1, lvl + 1, mpp);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, map<int, vector<int>>> mpp; // (x_idx, level) -> value
        dfs(root, 0, 0, mpp);
        
        vector<vector<int>> verticalOrder;

        for ( auto& [x_idx, mpp2] : mpp ) {
            vector<int> level;
            for ( auto& [lvl, vals ] : mpp2 ) {
                sort(vals.begin(), vals.end());
                for ( auto& val : vals ) level.push_back(val);
            }
            verticalOrder.push_back(level);
        }

        return verticalOrder;

    }
};

// ------------------------------------------------------------------------------------------------------------ // 

// 2- bfs based code : 
class Solution {
public:

    void bfs ( TreeNode* root, map<int, map<int, vector<int>>>& mpp ) {

        queue<pair<TreeNode*, pair<int, int>>> q; // {root, {x_idx, lvl}}
        q.push( {root, {0, 0} } );

        while ( !q.empty() ) {

            auto frame = q.front();
            TreeNode* node = frame.first;
            int x_idx = frame.second.first;
            int lvl = frame.second.second;
            q.pop();

            mpp[x_idx][lvl].push_back(node->val);

            if (node->left != NULL) q.push( {node->left, {x_idx - 1, lvl + 1} } );
            if (node->right != NULL) q.push( {node->right, {x_idx + 1, lvl + 1} } );

        }

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, map<int, vector<int>>> mpp; // (x_idx, level) -> value
        bfs(root, mpp); // bfs tp update map
        
        vector<vector<int>> verticalOrder;

        for ( auto& [x_idx, mpp2] : mpp ) {
            vector<int> level;
            for ( auto& [lvl, vals ] : mpp2 ) {
                sort(vals.begin(), vals.end());
                for ( auto& val : vals ) level.push_back(val);
            }
            verticalOrder.push_back(level);
        }

        return verticalOrder;

    }
};

// ------------------------------------------------------------------------------------------------------------ // 

// 3 - chatGPT's code using multiset : 

class Solution {
public:

    vector<tuple<int,int,int>> nodes;
    // {col, row, value}

    void dfs(TreeNode* root, int row, int col) {

        if(root == nullptr) return;

        nodes.push_back({col, row, root->val});

        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        dfs(root, 0, 0);

        sort(nodes.begin(), nodes.end(),
            [](const auto& a, const auto& b) {

                auto [col1, row1, val1] = a;
                auto [col2, row2, val2] = b;

                // 1. column
                if(col1 != col2)
                    return col1 < col2;

                // 2. row
                if(row1 != row2)
                    return row1 < row2;

                // 3. value
                return val1 < val2;
            }
        );

        vector<vector<int>> ans;

        int prevCol = INT_MIN;

        for(auto& [col, row, val] : nodes) {

            if(col != prevCol) {
                ans.push_back({});
                prevCol = col;
            }

            ans.back().push_back(val);
        }

        return ans;
    }
};


// ------------------------------------------------------------------------------------------------------------ // 