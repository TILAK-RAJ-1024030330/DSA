#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void preOrder(Node* node) {
    if (node == nullptr) return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node* node) {
    if (node == nullptr) return;

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void postOrder(Node* node) {
    if (node == nullptr) return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Pre-order (Root-Left-Right): ";
    preOrder(root);
    cout << endl;

    cout << "In-order (Left-Root-Right):  ";
    inOrder(root);
    cout << endl;

    cout << "Post-order (Left-Right-Root): ";
    postOrder(root);
    cout << endl;

    return 0;
}
