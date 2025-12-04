#include <iostream>
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
    BST() { root = nullptr; }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    Node* searchRecursive(Node* node, int key) {
        if (node == nullptr || node->data == key)
            return node;
        
        if (key < node->data)
            return searchRecursive(node->left, key);
        
        return searchRecursive(node->right, key);
    }

    bool searchIterative(Node* node, int key) {
        while (node != nullptr) {
            if (key == node->data) return true;
            
            if (key < node->data)
                node = node->left;
            else
                node = node->right;
        }
        return false;
    }

    Node* getMin(Node* node) {
        if (node == nullptr) return nullptr;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* getMax(Node* node) {
        if (node == nullptr) return nullptr;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    Node* getSuccessor(Node* root, int key) {
        Node* current = searchRecursive(root, key);
        if (current == nullptr) return nullptr;


        if (current->right != nullptr) {
            return getMin(current->right);
        }

        Node* successor = nullptr;
        Node* ancestor = root;
        while (ancestor != current) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }

    Node* getPredecessor(Node* root, int key) {
        Node* current = searchRecursive(root, key);
        if (current == nullptr) return nullptr;

        if (current->left != nullptr) {
            return getMax(current->left);
        }

        Node* predecessor = nullptr;
        Node* ancestor = root;
        while (ancestor != current) {
            if (current->data > ancestor->data) {
                predecessor = ancestor;
                ancestor = ancestor->right;
            } else {
                ancestor = ancestor->left;
            }
        }
        return predecessor;
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

    cout << "Search 40 (Recursive): " << (tree.searchRecursive(tree.root, 40) ? "Found" : "Not Found") << endl;
    cout << "Search 99 (Iterative): " << (tree.searchIterative(tree.root, 99) ? "Found" : "Not Found") << endl;

    cout << "Min Element: " << tree.getMin(tree.root)->data << endl;
    cout << "Max Element: " << tree.getMax(tree.root)->data << endl;

    Node* succ = tree.getSuccessor(tree.root, 40);
    if (succ) cout << "Successor of 40: " << succ->data << endl;
    else cout << "Successor of 40: None" << endl;

    Node* pred = tree.getPredecessor(tree.root, 50);
    if (pred) cout << "Predecessor of 50: " << pred->data << endl;
    
    return 0;
}
