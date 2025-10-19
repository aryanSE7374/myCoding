#include <bits/stdc++.h> 
using namespace std;

// Following is the Binary Tree node structure
template <typename T = int>
class BinaryTreeNode
{
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};

//---------------------------------------------//

// my implementation

void dfs(BinaryTreeNode<int> *root){

    if(root==NULL){
        return;
    }

    int left = (root->left!=NULL) ? root->left->data : 0;
    int right = (root->right!=NULL) ? root->right->data : 0;

    if(root->data < left+right){
        root->data = left+right;
    }

    if(root->data > left+right){
        if((root->left!=NULL)) root->left->data = root->data;
        if((root->right!=NULL)) root->right->data = root->data;
    }

    // rec calls

    if((root->left!=NULL)) dfs(root->left);
    if((root->right!=NULL)) dfs(root->right);

    // backtrack to update root value

    int total = 0;
    total += (root->left!=NULL) ? root->left->data : 0;
    total += (root->right!=NULL) ? root->right->data : 0;

    // check so that leaf node won't become zero
    if (root->left != NULL || root->right != NULL) {
        root->data = total;
    }

}

void changeTree(BinaryTreeNode < int > * root) {
    
    if (root==NULL) return;
    dfs(root);

}  

//---------------------------------------------//

// striver's implementation


// Helper function to reorder the tree according to children-sum property
void reorder(BinaryTreeNode<int>* root) {
    if (root == NULL) return;

    int child = 0;
    if (root->left) child += root->left->data;
    if (root->right) child += root->right->data;

    // Step 1: Update root before recursion
    if (child >= root->data) {
        root->data = child;
    } else {
        if (root->left) root->left->data = root->data;
        else if (root->right) root->right->data = root->data;
    }

    // Step 2: Recurse
    reorder(root->left);
    reorder(root->right);

    // Step 3: Backtrack - update root after recursion
    int total = 0;
    if (root->left) total += root->left->data;
    if (root->right) total += root->right->data;

    if (root->left || root->right) root->data = total;
}

// Main function
void changeTree(BinaryTreeNode<int>* root) {
    if (root == NULL) return;
    reorder(root);
}


//---------------------------------------------//

// brute force solution : gemini

// Helper to perform one pass and returns true if tree was changed
bool fixTreePass(BinaryTreeNode<int> *root) {
    if (!root) return false;

    bool changed = false;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    // Level order traversal to fix nodes
    while (!q.empty()) {
        BinaryTreeNode<int>* node = q.front();
        q.pop();

        if (node->left == NULL && node->right == NULL) continue;

        int children_sum = 0;
        if (node->left) children_sum += node->left->data;
        if (node->right) children_sum += node->right->data;
        
        int old_node_data = node->data;
        int old_left_data = node->left ? node->left->data : 0;
        int old_right_data = node->right ? node->right->data : 0;
        
        if (node->data < children_sum) {
            node->data = children_sum;
        } else if (node->data > children_sum) {
            int diff = node->data - children_sum;
            if (node->left) {
                node->left->data += diff;
            } else if (node->right) {
                node->right->data += diff;
            }
        }
        
        // Check if any value was modified in this step
        if (old_node_data != node->data || 
           (node->left && old_left_data != node->left->data) ||
           (node->right && old_right_data != node->right->data)) {
            changed = true;
        }
        
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    return changed;
}

void changeTree(BinaryTreeNode < int > * root) {
    if (root == NULL) return;
    
    // Repeat passes until no more changes occur
    while (fixTreePass(root));
}

//---------------------------------------------//