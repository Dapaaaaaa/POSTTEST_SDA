#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

// Menambahkan dokumen ke antrian (enqueue)
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    if (front == nullptr) { // Queue kosong
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Menghapus dokumen dari antrian (dequeue)
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    Node* temp = front;
    string doc = temp->document;
    front = front->next;
    if (front == nullptr) rear = nullptr; // Queue kosong setelah dequeue
    delete temp;
    return doc;
}

// Memproses semua dokumen dalam antrian
void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}
