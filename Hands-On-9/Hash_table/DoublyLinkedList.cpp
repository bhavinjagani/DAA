#include "DoublyLinkedList.h"
#include <iostream>

// Node constructor
Node::Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}

// DoublyLinkedList constructor
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Append a new node to the end of the list
void DoublyLinkedList::append(int key, int value) {
    Node* newNode = new Node(key, value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Remove a node by its key
bool DoublyLinkedList::remove(int key) {
    Node* current = head;
    while (current) {
        if (current->key == key) {
            if (current == head) {
                head = head->next;
                if (head) head->prev = nullptr;
            } else {
                current->prev->next = current->next;
                if (current->next) current->next->prev = current->prev;
            }
            if (current == tail) {
                tail = current->prev;
            }
            delete current;
            return true;
        }
        current = current->next;
    }
    return false;
}

// Search for a node by its key
Node* DoublyLinkedList::search(int key) {
    Node* current = head;
    while (current) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Destructor to free the memory of the list
DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}
