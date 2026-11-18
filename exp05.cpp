// Exp 5: Runtime polymorphism - virtual functions + abstract base class
#include <iostream>
#include <cmath>
using namespace std;

class Shape {                         // abstract class
public:
    virtual double area() const = 0;  // pure virtual
    virtual string name() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    double area() const override { return M_PI * r * r; }
    string name() const override { return "Circle"; }
};

class Rectangle : public Shape {
    double l, w;
public:
    Rectangle(double l, double w) : l(l), w(w) {}
    double area() const override { return l * w; }
    string name() const override { return "Rectangle"; }
};

class Triangle : public Shape {
    double b, h;
public:
    Triangle(double b, double h) : b(b), h(h) {}
    double area() const override { return 0.5 * b * h; }
    string name() const override { return "Triangle"; }
};

int main() {
    Shape* shapes[3] = { new Circle(5), new Rectangle(4, 6), new Triangle(3, 8) };

    for (int i = 0; i < 3; i++)
        cout << shapes[i]->name() << " area = " << shapes[i]->area() << endl;

    for (int i = 0; i < 3; i++) delete shapes[i];   // virtual destructor makes this safe
    return 0;
}