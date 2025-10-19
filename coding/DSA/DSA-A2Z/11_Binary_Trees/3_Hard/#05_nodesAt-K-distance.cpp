#include<bits/stdc++.h>
using namespace std;

// variation :  root to leaf path

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
    vector<int> k_level_elements_bfs(TreeNode* root , int level){
        
        vector<int> res;

        queue<TreeNode*> q;
        q.push(root);
        int k=0;
        while (!q.empty())
        {
            int size = q.size();
            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(k==level){
                    res.push_back(node->val);
                    continue;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            k++;
        }

        return res;

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> ans;
        
        unordered_map<TreeNode* , TreeNode*> parent;
        parent[root] = NULL;

        // dfs

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    parent[node->left] = node;
                }
                if(node->right){
                    q.push(node->right);
                    parent[node->right] = node;
                }
            }
        }


        // step1 : bfs till kth level
        ans = k_level_elements_bfs(target , k);


        // step 2 : i=1 to k -> bfs(k-i)
        TreeNode* node = parent[target];

        for(int i=1 ; i<k ; i++){
            if(node == NULL){
                // node is the targer is the root element
                return ans;
            }

            vector<int> temp = k_level_elements_bfs(node , k-i );
            ans.insert(ans.end() , temp.begin() , temp.end());
            node = parent[node];
        }

        if(node!=NULL)
            ans.push_back(node->val); // i=Kth parent


        return ans;

    }
};


// --------------------------------------------------------------------------------- //

// try 2


class Solution {
public:
    vector<int> k_level_elements_bfs(TreeNode* root , int level , TreeNode* ignoreRoot){
        
        vector<int> res;

        queue<TreeNode*> q;
        q.push(root);
        int k=0;
        while (!q.empty())
        {
            int size = q.size();
            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(k==level){
                    res.push_back(node->val);
                    continue;
                }
                if(node->left != ignoreRoot){
                    if(node->left){
                        q.push(node->left);
                    }
                }
                if(node->right != ignoreRoot){
                    if(node->right){
                        q.push(node->right);
                    }
                }
            }
            k++;
        }

        return res;

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> ans;
        if(k==0){
            return {target->val};
        }
        
        unordered_map<TreeNode* , TreeNode*> parent;
        parent[root] = NULL;

        // dfs

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    parent[node->left] = node;
                }
                if(node->right){
                    q.push(node->right);
                    parent[node->right] = node;
                }
            }
        }


        // step1 : bfs till kth level
        ans = k_level_elements_bfs(target , k , NULL);


        // step 2 : i=1 to k -> bfs(k-i)
        TreeNode* node = parent[target];
        TreeNode* childNode = target;

        for(int i=1 ; i<k ; i++){
            if(node == NULL){
                // node is the targer is the root element
                return ans;
            }

            vector<int> temp = k_level_elements_bfs(node , k-i , childNode );
            ans.insert(ans.end() , temp.begin() , temp.end());
            childNode = node;
            node = parent[node];
        }

        if(node!=NULL)
            ans.push_back(node->val); // i=Kth parent


        return ans;

    }

};


// --------------------------------------------------------------------------------- //

// striver's optimal solution

class Solution {
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target) {
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        markParents(root, parent_track, target);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            if(curr_level++ == k) break;
            for(int i=0; i<size; i++) {
                TreeNode* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};

// --------------------------------------------------------------------------------- //

// brute solution by chatGPT

class Solution {
    // Helper: Find path from root to a given node
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root) return false;
        path.push_back(root);
        if (root == target) return true;

        if (findPath(root->left, target, path) || findPath(root->right, target, path))
            return true;

        path.pop_back();
        return false;
    }

    // Helper: Find LCA using paths
    TreeNode* findLCA(TreeNode* root, TreeNode* a, TreeNode* b) {
        vector<TreeNode*> pathA, pathB;
        findPath(root, a, pathA);
        findPath(root, b, pathB);

        int i = 0;
        while (i < pathA.size() && i < pathB.size() && pathA[i] == pathB[i])
            i++;
        return pathA[i-1]; // last common node
    }

    // Helper: find depth of node from root
    int findDepth(TreeNode* root, TreeNode* target, int depth = 0) {
        if (!root) return -1;
        if (root == target) return depth;
        int left = findDepth(root->left, target, depth+1);
        if (left != -1) return left;
        return findDepth(root->right, target, depth+1);
    }

    // Compute distance using LCA
    int findDistance(TreeNode* root, TreeNode* u, TreeNode* v) {
        TreeNode* lca = findLCA(root, u, v);
        int du = findDepth(root, u);
        int dv = findDepth(root, v);
        int dlca = findDepth(root, lca);
        return du + dv - 2*dlca;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        if (!root) return result;

        // Traverse every node
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            int dist = findDistance(root, target, node);
            if (dist == k) result.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return result;
    }
};

// --------------------------------------------------------------------------------- //