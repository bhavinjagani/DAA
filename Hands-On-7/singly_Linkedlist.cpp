#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtHead(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void removeElemet(int x) {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }
        if (head->data == x) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != x) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            std::cout << "Element not found\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void searchElement(int x) {
        Node* temp = head;
        int position = 1;
        while (temp != nullptr) {
            if (temp->data == x) {
                std::cout << "Element " << x << " found at position " << position << "\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        std::cout << "Element not found\n";
    }

    void print() {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};
int main(){
  SinglyLinkedList list;
    list.insertAtHead(4);
    list.insertAtHead(3);
    list.insertAtHead(2);
     for (int i = 0; i < 10; ++i) {
        list.insertAtHead(rand() % 1000);  
    }
     
    std::cout<<"List Element:"<<" ";
    list.print();
    list.removeElemet(2);
    std::cout<<"List Elements After Removing 2:"<<" ";
    list.print();
    std::cout<<"Search Element:3"<<" ";
    list.searchElement(3);

}