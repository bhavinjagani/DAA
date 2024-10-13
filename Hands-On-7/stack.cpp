#include <iostream>
#define MAX 10

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1; 
    }

    std::string isFull() {
         if(top == MAX - 1){
            return "true";
        } 
        else{
            return "false";
        }
    }

    std::string isEmpty() {
        if(top == -1){
            return "true";
        }else{
            return "false";
        }
    }

    void push(int x) {
        if (isFull()=="true") {
            std::cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()=="true") {
            std::cout << "Stack underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()=="true") {
            std::cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
};

int main(){
    Stack S;
    std::cout<<"Element of stack :";
    for (int i = 0; i < 10; ++i) {
        int a =rand() % 1000;
        std::cout<<a<<" ";
        S.push(a);  
    }
   std::cout<<std::endl<<"Pop Example"<<" "<<"Removed Element :"<<S.pop()<<std::endl;
   std::cout<<"Peak Example"<<" "<<"Element At Top :"<<S.peek()<<std::endl;
   std::cout<<"Stack is Full :"<<S.isFull()<<std::endl;
   std::cout<<"Stack is Empty:"<<S.isEmpty()<<std::endl;
}