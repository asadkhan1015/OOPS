// Exp 3: All constructor types + Rule of 5
// Check leaks:  g++ -g exp03_constructors_rule_of_5.cpp -o exp03 && valgrind --leak-check=full ./exp03
#include <iostream>
#include <utility>
using namespace std;

class Buffer {
    int* data;
    int size;
public:
    // 1. Default
    Buffer() : data(nullptr), size(0) { cout << "Default\n"; }

    // 2. Parameterized
    Buffer(int n, int val) : data(new int[n]), size(n) {
        for (int i = 0; i < n; i++) data[i] = val;
        cout << "Parameterized\n";
    }

    // 3. Copy constructor (deep copy)
    Buffer(const Buffer& o) : data(new int[o.size]), size(o.size) {
        for (int i = 0; i < size; i++) data[i] = o.data[i];
        cout << "Copy\n";
    }

    // 4. Move constructor (steal the pointer)
    Buffer(Buffer&& o) noexcept : data(o.data), size(o.size) {
        o.data = nullptr;
        o.size = 0;
        cout << "Move\n";
    }

    // 5. Copy assignment
    Buffer& operator=(const Buffer& o) {
        cout << "Copy assignment\n";
        if (this != &o) {
            delete[] data;
            size = o.size;
            data = new int[size];
            for (int i = 0; i < size; i++) data[i] = o.data[i];
        }
        return *this;
    }

    // 6. Move assignment
    Buffer& operator=(Buffer&& o) noexcept {
        cout << "Move assignment\n";
        if (this != &o) {
            delete[] data;
            data = o.data;
            size = o.size;
            o.data = nullptr;
            o.size = 0;
        }
        return *this;
    }

    // 7. Destructor
    ~Buffer() {
        cout << "Destructor (size=" << size << ")\n";
        delete[] data;
    }

    void show() const {
        for (int i = 0; i < size; i++) cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    Buffer a;                       // default
    Buffer b(3, 7);                 // parameterized
    Buffer c = b;                   // copy
    Buffer d = move(b);             // move
    a = c;                          // copy assignment
    Buffer e(2, 1);
    e = move(c);                    // move assignment

    cout << "a: "; a.show();
    cout << "d: "; d.show();
    cout << "e: "; e.show();
    return 0;
}