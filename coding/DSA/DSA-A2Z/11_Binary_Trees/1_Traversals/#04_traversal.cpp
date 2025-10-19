#include <iostream>
using namespace std;

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

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// Pre-order: Root -> Left -> Right
void preOrder(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// In-order: Left -> Root -> Right
void inOrder(Node* root) {
    if (root == nullptr) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// Post-order: Left -> Right -> Root
void postOrder(Node* root) {
    if (root == nullptr) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 

int main() {
    /*
          1
         / \
        2   3
       / \
      4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Pre-order traversal: ";
    preOrder(root);
    cout << "\n";

    cout << "In-order traversal: ";
    inOrder(root);
    cout << "\n";

    cout << "Post-order traversal: ";
    postOrder(root);
    cout << "\n";

    return 0;
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 