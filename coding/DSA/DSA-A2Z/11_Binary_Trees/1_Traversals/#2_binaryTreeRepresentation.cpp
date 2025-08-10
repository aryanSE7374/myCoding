#include <iostream>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Helper function to create a new node
Node* createNode(int val) {
    return new Node(val);
}

int main() {
    /*
        Creating this tree:
              1
             / \
            2   3
           / \
          4   5
    */

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "Root node data: " << root->data << endl;
    cout << "Left child of root: " << root->left->data << endl;
    cout << "Right child of root: " << root->right->data << endl;
    cout << "Left child of root's left child: " << root->left->left->data << endl;

    return 0;
}