#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }

        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        
        return node;
    }

    Node* getMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) return node;

        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->data) {
            node->right = deleteNode(node->right, key);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = getMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    int maxDepth(Node* node) {
        if (node == nullptr) return 0;
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }

    int minDepth(Node* node) {
        if (node == nullptr) return 0;

        if (node->left == nullptr && node->right == nullptr) return 1;

        if (node->left == nullptr) return 1 + minDepth(node->right);
        if (node->right == nullptr) return 1 + minDepth(node->left);

        return 1 + min(minDepth(node->left), minDepth(node->right));
    }

    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
};

int main() {
    BST tree;
    
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Initial Tree (In-order): ";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "Max Depth: " << tree.maxDepth(tree.root) << endl;
    cout << "Min Depth: " << tree.minDepth(tree.root) << endl;

    cout << "Deleting 20 (Leaf)..." << endl;
    tree.root = tree.deleteNode(tree.root, 20);
    tree.inOrder(tree.root);
    cout << endl;

    cout << "Deleting 30 (One Child)..." << endl;
    tree.root = tree.deleteNode(tree.root, 30);
    tree.inOrder(tree.root);
    cout << endl;

    cout << "Deleting 50 (Two Children)..." << endl;
    tree.root = tree.deleteNode(tree.root, 50);
    tree.inOrder(tree.root);
    cout << endl;

    return 0;
}