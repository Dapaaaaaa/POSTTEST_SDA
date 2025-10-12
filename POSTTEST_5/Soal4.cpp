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

// Post Order Transversal (kiri, kanan, akar / left, right, root)
void postOrderTransveral(Node* root) {
    if (root == nullptr) return; // Menandakan tree kosong
    postOrderTransveral(root->left);
    postOrderTransveral(root->right);
    cout << root->data << " ";
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

    cout << "Post Order Traversal dari tree adalah : ";
    postOrderTransveral(root);
    cout << endl;
    return 0;
}