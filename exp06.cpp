// Exp 6: Compile-time polymorphism - function overloading + operator overloading
#include <iostream>
using namespace std;

// Function overloading
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
int add(int a, int b, int c) { return a + b + c; }

class Complex {
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& o) const { return Complex(real + o.real, imag + o.imag); }
    Complex operator-(const Complex& o) const { return Complex(real - o.real, imag - o.imag); }
    Complex operator*(const Complex& o) const {
        return Complex(real * o.real - imag * o.imag, real * o.imag + imag * o.real);
    }
    bool operator==(const Complex& o) const { return real == o.real && imag == o.imag; }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? " + " : " - ") << (c.imag >= 0 ? c.imag : -c.imag) << "i";
        return out;
    }
};

int main() {
    cout << "add(2,3)       = " << add(2, 3) << endl;
    cout << "add(2.5,3.5)   = " << add(2.5, 3.5) << endl;
    cout << "add(1,2,3)     = " << add(1, 2, 3) << endl;

    Complex a(3, 4), b(1, -2);
    cout << "\na = " << a << "\nb = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a == b ? " << (a == b) << endl;
    return 0;
}