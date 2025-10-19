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


// my try 1 : ACCPETED

class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track ) {
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

    void dfs(TreeNode* root , int start , TreeNode* &target){
        if(!root){
            return;
        }
        if(root->val == start){
            target = root;
        }
        dfs(root->left , start , target);
        dfs(root->right , start , target);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        TreeNode* target;
        dfs(root , start , target);
        markParents(root, parent_track );

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) { 
            int size = queue.size();
            if(curr_level++ == 1e5) break;
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
        return curr_level-1;
    }
};


// --------------------------------------------------------------------------------- //

// striver's optimal solution

class Solution {
private:
    // Build a map from node pointers to parent pointers
    void mapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    // Find the node with value == start
    TreeNode* findTarget(TreeNode* root, int start) {
        if (!root) return nullptr;
        if (root->val == start) return root;
        TreeNode* l = findTarget(root->left, start);
        if (l) return l;
        return findTarget(root->right, start);
    }

    // BFS from the target node using parent + child links to compute the time to infect entire tree
    int bfsBurn(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parent) {
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        if (target) {
            q.push(target);
            visited[target] = true;
        }

        int minutes = 0;
        while (!q.empty()) {
            int sz = q.size();
            bool spread = false; // spread flag
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !visited[node->left]) {
                    spread = true;
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if (node->right && !visited[node->right]) {
                    spread = true;
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if (parent[node] && !visited[parent[node]]) {
                    spread = true;
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
            if (spread) minutes++;
        }
        return minutes;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        if (!root) return 0;
        unordered_map<TreeNode*, TreeNode*> parent;
        mapParents(root, parent);

        TreeNode* target = findTarget(root, start);
        if (!target) return 0;

        return bfsBurn(target, parent);
    }
};

// --------------------------------------------------------------------------------- //

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

// striver's optimal version

class Solution {
  public:
    // Helper 1: Map each node to its parent
    void mapParents(Node* root, unordered_map<Node*, Node*> &parent) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    // Helper 2: Find the node with given target value
    Node* findTarget(Node* root, int target) {
        if (!root) return NULL;
        if (root->data == target) return root;

        Node* leftSearch = findTarget(root->left, target);
        if (leftSearch) return leftSearch;

        return findTarget(root->right, target);
    }

    // Helper 3: BFS to simulate burning
    int burnTree(Node* target, unordered_map<Node*, Node*> &parent) {
        unordered_map<Node*, bool> visited;
        queue<Node*> q;

        q.push(target);
        visited[target] = true;

        int time = 0;

        while (!q.empty()) {
            int sz = q.size();
            bool burned = false;

            for (int i = 0; i < sz; i++) {
                Node* node = q.front();
                q.pop();

                if (node->left && !visited[node->left]) {
                    burned = true;
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if (node->right && !visited[node->right]) {
                    burned = true;
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if (parent[node] && !visited[parent[node]]) {
                    burned = true;
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }

            if (burned) time++;
        }

        return time;
    }

    // Main function
    int minTime(Node* root, int target) {
        if (!root) return 0;

        unordered_map<Node*, Node*> parent;
        mapParents(root, parent);

        Node* targetNode = findTarget(root, target);

        return burnTree(targetNode, parent);
    }
};

// --------------------------------------------------------------------------------- //