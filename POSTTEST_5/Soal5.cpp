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

// Pre Order Transversal (akar, kiri, kanan / root, left, right)
void preOrderTransveral(Node* root) {
    if (root == nullptr) return; // Menandakan tree kosong
    cout << root->data << " ";
    preOrderTransveral(root->left);
    preOrderTransveral(root->right);
}

// Program Utama
int main () {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Pre Order Traversal dari tree adalah : ";
    preOrderTransveral(root);
    cout << endl;
    return 0;
}