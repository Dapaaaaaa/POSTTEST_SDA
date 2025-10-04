#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeHeadAndTailData(Node *&head_ref) {
    if (
        !head_ref || head_ref->next == head_ref
    ) return;
    
    Node* head = head_ref;
    Node* tail = head_ref->prev;
    swap(head->data, tail->data);
}


void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void insertEnd(Node *&head_ref, int data) {
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node *head = nullptr;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum tukar head dan tail: ";
    printList(head);

    // Output diharapkan: 1 2 3 4 5;

    exchangeHeadAndTailData(head);

    cout << "List setelah tukar head dan tail: ";
    printList(head);
    // Output diharapkan: 5 2 3 4 1

    return 0;
}
