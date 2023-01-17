#include <iostream>
using namespace std;

#define n 100

class Stack{
    int *arr;
    int top;

public:
    Stack(){
        arr = new int[n];
        top = -1;
    }
    void Push(int data){
        if (top == n - 1)
            cout << "Stack Overflow" << endl;
        top++;
        arr[top] = data;
    }
    void Pop(){
        if (top == -1)
            cout << "Stack Underflow" << endl;
        top--;
    }
    void Top(){
        cout << arr[top] << endl;
    }
    bool isEmpty(){
        return top == -1;
    }
    int isFull(){
        return top == n - 1;
    }
};

int main(){
    Stack s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.Top();
    s.Pop();
    s.Top();
    cout << s.isFull() << endl;
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    cout << s.isEmpty() << endl;
}
