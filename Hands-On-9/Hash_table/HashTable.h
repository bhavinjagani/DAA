#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "DoublyLinkedList.h"

class HashFunction {
public:
    virtual int hash(int key, int tableSize) = 0;
};

class MultiplicationHash : public HashFunction {
public:
    int hash(int key, int tableSize) override;
};

class DivisionHash : public HashFunction {
public:
    int hash(int key, int tableSize) override;
};

class HashTable {
private:
    DoublyLinkedList** table;
    int currentSize;
    int capacity;
    HashFunction* hashFunction;

    void resize(int newSize);

public:
    HashTable(int size, HashFunction* hf);
    void insert(int key, int value);
    bool remove(int key);
    Node* search(int key);
    ~HashTable();
};

#endif
