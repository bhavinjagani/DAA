#include "HashTable.h"
#include <iostream>

int main() {
    // Choose a hash function (multiplication or division)
    MultiplicationHash mulHash;
    HashTable hashTable(4, &mulHash); // Initialize hash table with the chosen hash function

    // Insert key-value pairs
    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(3, 10);
    hashTable.insert(3, 30);
    hashTable.insert(4, 40);

    hashTable.insert(10, 50);
    hashTable.insert(11, 60);
    hashTable.insert(12, 70);   
    // Search for a key
    Node* result = hashTable.search(3);
    if (result) {
        std::cout << "Key: " << result->key << ", Values: ";
        while (result != nullptr) {
            std::cout << result->value << " ";
            result = result->next;
        }
        
    } else {
        std::cout << "Key not found" << std::endl;
    }
    return 0;
}
