#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Fungsi push: menambahkan elemen ke atas stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// Fungsi pop: menghapus elemen dari atas stack
char pop(Node*& top) {
    if (top == nullptr) return '\0'; // Stack kosong
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    // 1. Masukkan setiap karakter string ke stack
    for (char c : s) {
        push(stackTop, c);
    }

    // 2. Ambil karakter dari stack satu per satu (otomatis terbalik)
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }

    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; 
    // Output: ataD rutkurS
    return 0;
}
