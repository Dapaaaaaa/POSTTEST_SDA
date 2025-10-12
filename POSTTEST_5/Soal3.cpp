#include <iostream>
using namespace std;

// Stuktur Binary Tree
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

// Insert untuk membangun tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    
    return root;
}

// Nilai Maximal
int findMaxVal(Node* root) {
    if (root == nullptr) return -1; // Menandakan tree kosong
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->data;
}

// Program Utama
int main () {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    cout << "Nilai terkecil didalam tree adalah " << findMaxVal(root) << endl;
    return 0;
}