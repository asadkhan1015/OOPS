// Exp 4: Single + Multilevel inheritance (Person -> Student -> GraduateStudent)
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    void showPerson() const { cout << "Name: " << name << ", Age: " << age << endl; }
};

// Single inheritance: Person -> Student
class Student : public Person {
protected:
    int rollNo;
    float cgpa;
public:
    Student(string n, int a, int r, float c) : Person(n, a), rollNo(r), cgpa(c) {}
    void showStudent() const {
        showPerson();
        cout << "Roll No: " << rollNo << ", CGPA: " << cgpa << endl;
    }
};

// Multilevel inheritance: Person -> Student -> GraduateStudent
class GraduateStudent : public Student {
    string thesisTopic;
    string supervisor;
public:
    GraduateStudent(string n, int a, int r, float c, string t, string s)
        : Student(n, a, r, c), thesisTopic(t), supervisor(s) {}
    void showGraduate() const {
        showStudent();
        cout << "Thesis: " << thesisTopic << ", Supervisor: " << supervisor << endl;
    }
};

int main() {
    cout << "--- Single inheritance ---\n";
    Student s("Aman", 19, 101, 8.2f);
    s.showStudent();

    cout << "\n--- Multilevel inheritance ---\n";
    GraduateStudent g("Neha", 23, 501, 9.1f, "Deep Learning for Crops", "Dr. Rao");
    g.showGraduate();
    return 0;
}