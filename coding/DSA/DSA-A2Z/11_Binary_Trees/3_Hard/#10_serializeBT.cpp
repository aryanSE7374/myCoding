#include<bits/stdc++.h>
#include<sstream>
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




// my try 1

class Codec {
public:


    void bfs(TreeNode*  root , string& s ){

        queue<TreeNode*> q;
        q.push(root);


        while(!q.empty()){
            int size = q.size();
            for(int i=0 ; i<size ; i++){

                TreeNode* node = q.front();
                q.pop();
                
                if(node==NULL){
                    s.append("#$");
                    continue;
                }

                s.append(to_string(node->val) + '$');

                if(node->left){
                    q.push(node->left);
                }
                else{
                    q.push(NULL);
                }

                if(node->right){
                    q.push(node->right);
                }
                else{
                    q.push(NULL);
                }

            }
        }

        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "#";
        }
        string s = "";
        bfs(root , s);
        return s;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") return NULL;
        stringstream ss_data(data);
        vector<string> data_tokens;
        string token;
        while (getline(ss_data, token, '$')) { // Extracts tokens separated by ','
            data_tokens.push_back(token);
        }
        // data_tokens.pop_back();
        TreeNode* root = new TreeNode(stoi(data_tokens[0]));

        // TreeNode* parent = root;

        queue<TreeNode*> q;
        q.push(root);

        int i=1;

        while (!q.empty() && i < data_tokens.size())
        {
            TreeNode* node = q.front();
            q.pop();

            // left child
            if(data_tokens[i] != "#"){
                node->left = new TreeNode(stoi(data_tokens[i]));
                q.push(node->left);
            }
            i++;

            // right child
            if(i < data_tokens.size() && data_tokens[i] != "#"){
                node->right = new TreeNode(stoi(data_tokens[i]));
                q.push(node->right);
            }
            i++;

            // int data = (data_tokens[i]!="#") ? stoi(data_tokens[i]) : -10001 ;
            // i++;

            // node->left = ((node)&&(data!=-10001)) ? new TreeNode(data) : NULL;

            // data = (data_tokens[i]!="#") ? stoi(data_tokens[i]) : -10001 ;
            // i++;
            // node->right = ((node)&&(data!=-10001))  ? new TreeNode(stoi(data_tokens[i])) : NULL;
            
        }

        return root;


    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));






// sol 

