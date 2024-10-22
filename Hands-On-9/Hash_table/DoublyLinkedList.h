#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

struct Node {
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int k, int v);
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList();
    void append(int key, int value);
    bool remove(int key);
    Node* search(int key);
    ~DoublyLinkedList();
};

#endif
