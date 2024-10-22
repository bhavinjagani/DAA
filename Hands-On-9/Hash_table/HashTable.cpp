#include "HashTable.h"
#include <iostream>

int MultiplicationHash::hash(int key, int tableSize) {
    const double A = 0.6180339887; 
    double fractionalPart = key * A - (int)(key * A);
   
    return (int)(tableSize * fractionalPart);
}

int DivisionHash::hash(int key, int tableSize) {
    return key % tableSize;
}

HashTable::HashTable(int size, HashFunction* hf) : currentSize(0), capacity(size), hashFunction(hf) {
    table = new DoublyLinkedList*[capacity];
    for (int i = 0; i < capacity; ++i) {
        table[i] = new DoublyLinkedList();
    }
}

void HashTable::resize(int newSize) {
    DoublyLinkedList** newTable = new DoublyLinkedList*[newSize];
    for (int i = 0; i < newSize; ++i) {
        newTable[i] = new DoublyLinkedList();
    }

    for (int i = 0; i < capacity; ++i) {
        Node* current = table[i]->head;
        while (current) {
            int newIndex = hashFunction->hash(current->key, newSize);
            newTable[newIndex]->append(current->key, current->value);
            current = current->next;
        }
        delete table[i];
    }

    delete[] table;
    table = newTable;
    capacity = newSize;
}

// Insert a key-value pair
void HashTable::insert(int key, int value) {
    if (currentSize >= capacity) {
        resize(2 * capacity);
    }
    int index = hashFunction->hash(key, capacity);
     std::cout<<"index",index;
    table[index]->append(key, value);
    ++currentSize;
}

// Remove a key from the hash table
bool HashTable::remove(int key) {
    int index = hashFunction->hash(key, capacity);
    bool removed = table[index]->remove(key);
    if (removed) {
        --currentSize;
        if (currentSize <= capacity / 4) {
            resize(capacity / 2);
        }
    }
    return removed;
}

// Search for a key in the hash table
Node* HashTable::search(int key) {
    int index = hashFunction->hash(key, capacity);
    return table[index]->search(key);
}

// Destructor
HashTable::~HashTable() {
    for (int i = 0; i < capacity; ++i) {
        delete table[i];
    }
    delete[] table;
}
