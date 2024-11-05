#include <iostream>
#include <stdexcept>

class DynamicArray {
private:
    int* data;          
    size_t capacity;     
    size_t length;      

    void resize() {
        capacity = capacity * 2;     
        int* newData = new int[capacity];
        
        for (size_t i = 0; i < length; i++) {
            newData[i] = data[i];    
        }

        delete[] data;               
        data = newData;              
    }

public:
    
    DynamicArray() : capacity(2), length(0) {
        data = new int[capacity];    
    }

    ~DynamicArray() {
        delete[] data;               
    }

    
    size_t size() const {
        return length;
    }

    
    void push_back(int value) {
        if (length == capacity) {
            resize();                
        }
        data[length++] = value;      
    }

    
    void pop_back() {
        if (length == 0) {
            throw std::out_of_range("Array is empty");
        }
        length--;                   
    }

    
    int operator[](size_t index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    
    int& operator[](size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

   
    void clear() {
        length = 0;                 
    }
};

int main() {
    DynamicArray arr;

    arr.push_back(5);
    arr.push_back(40);
    arr.push_back(20);
    arr.push_back(90);

    
    std::cout << "Array elements: ";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr.pop_back();

    std::cout << "After pop_back, array elements: ";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
