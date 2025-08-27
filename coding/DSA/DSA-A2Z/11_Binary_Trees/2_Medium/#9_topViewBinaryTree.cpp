#include<bits/stdc++.h>
using namespace std;

// GFG

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

// my try 1

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        map<int , map<int , int>> nodes; // map to store tracersal : [vertical -> [level -> {node}]]
        queue<pair<Node* , pair<int , int>>> todo; // {node , {vertical , level} }
        todo.push({root , {0,0}});

        while (!todo.empty())
        {
            auto p = todo.front(); // queue element 
            todo.pop();

            Node* node = p.first; // node
            int x = p.second.first; // vertical
            int y = p.second.second; // level
            if(nodes[x].find(y)==nodes[x].end()){nodes[x][y] = node->data;}
            // nodes[x][y].insert(node->data); // insert value into the map 

            if(node->left){
                todo.push({node->left , {x-1 , y+1}}); // dec verical , inc level
            } 
            if(node->right){
                todo.push({node->right , {x+1 , y+1}}); // inc vertical , dec level
            } 

        }
        
        vector<int> res; 
        for(auto p : nodes) {
            for (auto q : p.second){
                res.push_back(q.second);
                break;
            }
        }
        return res;
        
    }
};



// striver's optimal solution
// TC : O(N*logN)
// SC : O(N)

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        map<int , int> nodes; // map to store tracersal : [vertical -> node]
        queue<pair<Node* , int>> todo; // { node , vertical }
        todo.push({root , 0}); // { root , 0th vertical }

        while (!todo.empty())
        {
            auto p = todo.front(); // queue element 
            todo.pop();

            Node* node = p.first; // node
            int x = p.second; // vertical
            if(nodes.find(x)==nodes.end()){ // insert value into the map only if it is not seen yet on the vertical
                nodes[x] = node->data;
            } 

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
