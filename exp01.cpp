// Exp 1: Data types, constants, variables, operators and I/O
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Data types
    int age = 20;
    float cgpa = 8.5f;
    double pi = 3.14159265;
    char grade = 'A';
    bool passed = true;
    string name = "Riya";

    // Constants
    const double GST = 0.18;
    #define COLLEGE "ABC Institute"

    cout << "Name: " << name << ", Age: " << age << ", CGPA: " << cgpa << endl;
    cout << "Grade: " << grade << ", Passed: " << passed << ", Pi: " << pi << endl;
    cout << "College: " << COLLEGE << ", GST: " << GST << endl;

    // Input
    int a, b;
    cout << "\nEnter two integers: ";
    cin >> a >> b;

    // Operators
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    if (b != 0) {
        cout << "a / b = " << a / b << endl;
        cout << "a % b = " << a % b << endl;
    }
    cout << "a > b ? " << (a > b) << endl;                       // relational
    cout << "a>0 && b>0 ? " << (a > 0 && b > 0) << endl;        // logical
    cout << "a & b = " << (a & b) << ", a | b = " << (a | b) << endl; // bitwise
    a++;                                                          // increment
    cout << "a after a++ = " << a << endl;
    cout << "Bigger = " << (a > b ? a : b) << endl;              // ternary
    return 0;
}