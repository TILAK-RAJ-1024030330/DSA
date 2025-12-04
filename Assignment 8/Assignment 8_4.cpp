#include <iostream>
#include <climits> 

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool checkBST(Node* node, long long minVal, long long maxVal) {
    if (node == nullptr) {
        return true;
    }

    if (node->data <= minVal || node->data >= maxVal) {
        return false;
    }

    return checkBST(node->left, minVal, node->data) && 
           checkBST(node->right, node->data, maxVal);
}

bool isBST(Node* root) {
    return checkBST(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* validRoot = new Node(10);
    validRoot->left = new Node(5);
    validRoot->right = new Node(20);
    
    Node* invalidRoot = new Node(10);
    invalidRoot->left = new Node(5);
    invalidRoot->right = new Node(20);
    invalidRoot->right->left = new Node(6); 

    if (isBST(validRoot)) 
        cout << "Tree 1 is a Valid BST" << endl;
    else 
        cout << "Tree 1 is NOT a BST" << endl;

    if (isBST(invalidRoot)) 
        cout << "Tree 2 is a Valid BST" << endl;
    else 
        cout << "Tree 2 is NOT a BST" << endl;

    return 0;
}
