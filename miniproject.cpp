#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---------- Student class ----------
class Student {
private:
    int rollNo;
    string name;
    string branch;
    float marks;

public:
    Student(int r, string n, string b, float m) {
        rollNo = r;
        name = n;
        branch = b;
        marks = m;
    }

    // Getters
    int getRollNo() { return rollNo; }
    string getName() { return name; }
    string getBranch() { return branch; }
    float getMarks() { return marks; }

    // Setters
    void setName(string n) { name = n; }
    void setBranch(string b) { branch = b; }
    void setMarks(float m) { marks = m; }

    void display() {
        cout << "Roll No: " << rollNo
             << " | Name: " << name
             << " | Branch: " << branch
             << " | Marks: " << marks << endl;
    }
};

// ---------- StudentManager class ----------
class StudentManager {
private:
    vector<Student> students;

    // Returns position of student in the list, or -1 if not found
    int findIndex(int roll) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getRollNo() == roll)
                return i;
        }
        return -1;
    }

public:
    void addStudent() {
        int roll;
        string name, branch;
        float marks;

        cout << "Roll No: ";
        cin >> roll;
        if (findIndex(roll) != -1) {
            cout << "This roll number already exists!\n";
            return;
        }
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Branch: ";
        getline(cin, branch);
        cout << "Marks: ";
        cin >> marks;

        students.push_back(Student(roll, name, branch, marks));
        cout << "Student added!\n";
    }

    void viewAll() {
        if (students.empty()) {
            cout << "No students yet.\n";
            return;
        }
        for (int i = 0; i < students.size(); i++)
            students[i].display();
    }

    void searchStudent() {
        int roll;
        cout << "Enter Roll No: ";
        cin >> roll;
        int i = findIndex(roll);
        if (i == -1) cout << "Student not found.\n";
        else students[i].display();
    }

    void updateStudent() {
        int roll;
        cout << "Enter Roll No to update: ";
        cin >> roll;
        int i = findIndex(roll);
        if (i == -1) {
            cout << "Student not found.\n";
            return;
        }
        string name, branch;
        float marks;
        cout << "New Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "New Branch: ";
        getline(cin, branch);
        cout << "New Marks: ";
        cin >> marks;

        students[i].setName(name);
        students[i].setBranch(branch);
        students[i].setMarks(marks);
        cout << "Student updated!\n";
    }

    void deleteStudent() {
        int roll;
        cout << "Enter Roll No to delete: ";
        cin >> roll;
        int i = findIndex(roll);
        if (i == -1) {
            cout << "Student not found.\n";
            return;
        }
        students.erase(students.begin() + i);
        cout << "Student deleted!\n";
    }
};

// ---------- Menu ----------
int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addStudent(); break;
            case 2: manager.viewAll(); break;
            case 3: manager.searchStudent(); break;
            case 4: manager.updateStudent(); break;
            case 5: manager.deleteStudent(); break;
            case 6: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }
    } while (choice != 6);

    return 0;
}