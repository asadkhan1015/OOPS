// Exp 10: CSV reader/writer with fstream + seekg, seekp, tellg, tellp
// Every record is padded to the same width, so we can jump to record N directly.
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

const int REC_SIZE = 40;               // each line = 39 chars + '\n'
const string FILE_NAME = "students.csv";

struct Student {
    int id;
    string name;
    int marks;
};

string toLine(const Student& s) {
    string line = to_string(s.id) + "," + s.name + "," + to_string(s.marks);
    line.resize(REC_SIZE - 1, ' ');    // pad with spaces
    return line;
}

Student parseLine(string line) {
    while (!line.empty() && line.back() == ' ') line.pop_back();   // remove padding
    stringstream ss(line);
    string id, name, marks;
    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, marks, ',');
    return Student{stoi(id), name, stoi(marks)};
}

void writeAll(const vector<Student>& list) {
    ofstream out(FILE_NAME, ios::binary);
    for (auto& s : list) out << toLine(s) << '\n';
    cout << "Wrote " << list.size() << " records. tellp = " << out.tellp() << " bytes\n";
}

void readAll() {
    ifstream in(FILE_NAME, ios::binary);
    string line;
    cout << "\nID   Name       Marks\n";
    while (getline(in, line)) {
        Student s = parseLine(line);
        cout << left << setw(5) << s.id << setw(11) << s.name << s.marks << endl;
    }
    in.clear();
    cout << "End of file reached. tellg = " << in.tellg() << endl;
}

Student readRecord(int n) {            // n starts from 0
    ifstream in(FILE_NAME, ios::binary);
    in.seekg(n * REC_SIZE, ios::beg);  // jump straight to record n
    string line;
    getline(in, line);
    return parseLine(line);
}

void updateMarks(int n, int newMarks) {
    Student s = readRecord(n);
    s.marks = newMarks;
    fstream io(FILE_NAME, ios::in | ios::out | ios::binary);
    io.seekp(n * REC_SIZE, ios::beg);  // jump to record n and overwrite it
    io << toLine(s) << '\n';
}

int main() {
    vector<Student> list = {
        {101, "Aman", 78}, {102, "Riya", 92}, {103, "Karan", 55}, {104, "Neha", 88}
    };

    writeAll(list);
    readAll();

    Student s = readRecord(2);
    cout << "\nRecord #3 via seekg: " << s.name << " (" << s.marks << ")\n";

    updateMarks(2, 70);
    cout << "After update, Karan has: " << readRecord(2).marks << " marks\n";

    readAll();
    return 0;
}