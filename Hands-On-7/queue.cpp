#include <iostream>
#define MAX 100

class Queue {
private:
    int arr[MAX];
    int front, rear, size;

public:
    Queue() : front(0), rear(0), size(0) {}

     std::string isFull() {
         if(size == MAX){
            return "true";
        } 
        else{
            return "false";
        }
    }

    std::string isEmpty() {
        if(size == 0){
            return "true";
        }else{
            return "false";
        }
    }

    void enqueue(int x) {
        if (isFull()=="true") {
            std::cout << "Queue overflow\n";
            return;
        }
        arr[rear] = x;
        rear = (rear + 1) % MAX;
        size++;
    }

    int dequeue() {
        if (isEmpty()=="true") {
            std::cout << "Queue underflow\n";
            return -1;
        }
        int temp = arr[front];
        front = (front + 1) % MAX;
        size--;
        return temp;
    }

    int peek() {
        if (isEmpty()=="true") {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
};
int main(){
 Queue Q;
 std::cout<<"Element of Queue :";
    for (int i = 0; i < 10; ++i) {
        int a =rand() % 1000;
        std::cout<<a<<" ";
        Q.enqueue(a);  
    }
   std::cout<<std::endl<<"dequeue Example"<<" "<<"Removed Element :"<<Q.dequeue()<<std::endl;
   std::cout<<"Peak Example"<<" "<<"Element At Top :"<<Q.peek()<<std::endl;
   std::cout<<"Queue is Full :"<<Q.isFull()<<std::endl;
   std::cout<<"Queue is Empty:"<<Q.isEmpty()<<std::endl;
}