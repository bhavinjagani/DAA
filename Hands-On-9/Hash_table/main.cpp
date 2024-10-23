#include "HashTable.h"
#include <iostream>

int main() {
   
    MultiplicationHash mulHash;
    HashTable hashTable(4, &mulHash); 

    // Insert key-value pairs
    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(3, 10);
    hashTable.insert(3, 30);
    hashTable.insert(4, 40);

    hashTable.insert(4, 70);   
    // Search for a key
   
    hashTable.printHashTable();
    return 0;
}
