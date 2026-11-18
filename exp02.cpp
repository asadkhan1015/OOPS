// Exp 2: Class hierarchy (Vehicle), access specifiers, member functions
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:                       // only inside Vehicle
    int id;
protected:                     // Vehicle and its children
    string brand;
    int speed;
public:                        // everyone
    Vehicle(int i, string b) : id(i), brand(b), speed(0) {}
    void accelerate(int s) { speed += s; }
    void brake() { speed = 0; }
    int getId() const { return id; }
    void show() const {
        cout << "Vehicle #" << id << " " << brand << " speed=" << speed << endl;
    }
};

class Car : public Vehicle {
    int doors;
public:
    Car(int i, string b, int d) : Vehicle(i, b), doors(d) {}
    void honk() const { cout << brand << " says Beep Beep!" << endl; } // protected access
    void showCar() const {
        show();
        cout << "Doors: " << doors << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(int i, string b) : Vehicle(i, b) {}
    void wheelie() const { cout << brand << " is doing a wheelie!" << endl; }
};

int main() {
    Car c(1, "Toyota", 4);
    Bike b(2, "Yamaha");

    c.accelerate(60);
    c.showCar();
    c.honk();

    b.accelerate(40);
    b.show();
    b.wheelie();
    b.brake();
    b.show();

    // c.speed = 10;   // ERROR: protected
    // c.id = 5;       // ERROR: private
    return 0;
}