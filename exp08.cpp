// Exp 8: STL containers (vector, map, unordered_map) + algorithms (sort, find_if, transform)
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
    string name;
    int marks;
};

int main() {
    vector<Student> students = {
        {"Aman", 78}, {"Riya", 92}, {"Karan", 55},
        {"Neha", 88}, {"Sana", 67}, {"Dev", 40}
    };

    // sort by marks (descending)
    sort(students.begin(), students.end(),
         [](const Student& a, const Student& b) { return a.marks > b.marks; });
    cout << "Sorted by marks:\n";
    for (auto& s : students) cout << "  " << s.name << " " << s.marks << endl;

    // find_if: first student below 50
    auto it = find_if(students.begin(), students.end(),
                      [](const Student& s) { return s.marks < 50; });
    if (it != students.end()) cout << "\nFirst failing student: " << it->name << endl;

    // transform: add 5 grace marks (max 100)
    transform(students.begin(), students.end(), students.begin(), [](Student s) {
        s.marks = min(100, s.marks + 5);
        return s;
    });
    cout << "\nAfter 5 grace marks:\n";
    for (auto& s : students) cout << "  " << s.name << " " << s.marks << endl;

    // map: ordered by name
    map<string, int> ordered;
    for (auto& s : students) ordered[s.name] = s.marks;
    cout << "\nmap (sorted by name):\n";
    for (auto& p : ordered) cout << "  " << p.first << " -> " << p.second << endl;

    // unordered_map: fast lookup by name
    unordered_map<string, int> lookup;
    for (auto& s : students) lookup[s.name] = s.marks;
    string query = "Riya";
    if (lookup.count(query)) cout << "\nunordered_map lookup: " << query << " = " << lookup[query] << endl;

    // average
    int total = 0;
    for (auto& s : students) total += s.marks;
    cout << "Class average: " << (double)total / students.size() << endl;
    return 0;
}