// Exp 7: Generic Stack using templates (int, float, string)
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack {
    T* arr;
    int top;
    int capacity;
public:
    Stack(int cap = 10) : arr(new T[cap]), top(-1), capacity(cap) {}
    ~Stack() { delete[] arr; }
    Stack(const Stack&) = delete;             // keep it simple: no copying
    Stack& operator=(const Stack&) = delete;

    void push(const T& x) {
        if (isFull()) throw overflow_error("Stack is full");
        arr[++top] = x;
    }
    T pop() {
        if (isEmpty()) throw underflow_error("Stack is empty");
        return arr[top--];
    }
    T peek() const {
        if (isEmpty()) throw underflow_error("Stack is empty");
        return arr[top];
    }
    bool isEmpty() const { return top == -1; }
    bool isFull() const { return top == capacity - 1; }
};

template <typename T>
void test(const string& label, T a, T b, T c) {
    Stack<T> s(5);
    s.push(a); s.push(b); s.push(c);
    cout << label << " -> peek: " << s.peek() << " | popping: ";
    while (!s.isEmpty()) cout << s.pop() << " ";
    cout << endl;
}

int main() {
    test<int>("int   ", 10, 20, 30);
    test<float>("float ", 1.5f, 2.5f, 3.5f);
    test<string>("string", "apple", "banana", "cherry");
    return 0;
}