#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <chrono>
#include <string>
#include "Person.h"
#include "FileHandler.h"

using namespace std;

void testDeque(int count) {
    string filename = "students_" + to_string(count) + ".txt";
    cout << "\n--- DEQUE: " << count << " records ---\n";
    try {
        deque<Person> students, passed, failed;

        auto start = chrono::high_resolution_clock::now();
        readFileDeque(filename, students);
        auto end = chrono::high_resolution_clock::now();
        cout << "1. Read:  " << chrono::duration<double>(end - start).count() << " s\n";

        start = chrono::high_resolution_clock::now();
        sort(students.begin(), students.end(), compareByGrade);
        end = chrono::high_resolution_clock::now();
        cout << "2. Sort:  " << chrono::duration<double>(end - start).count() << " s\n";

        start = chrono::high_resolution_clock::now();
        for (const auto& s : students) {
            if (s.getFinalGrade() < 5.0) failed.push_back(s);
            else passed.push_back(s);
        }
        end = chrono::high_resolution_clock::now();
        cout << "3. Split: " << chrono::duration<double>(end - start).count() << " s\n";

        start = chrono::high_resolution_clock::now();
        writeFileDeque("failed_deque_" + to_string(count) + ".txt", failed);
        writeFileDeque("passed_deque_" + to_string(count) + ".txt", passed);
        end = chrono::high_resolution_clock::now();
        cout << "4. Write: " << chrono::duration<double>(end - start).count() << " s\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }
}

void testList(int count) {
    string filename = "students_" + to_string(count) + ".txt";
    cout << "\n--- LIST: " << count << " records ---\n";
    try {
        list<Person> students, passed, failed;

        auto start = chrono::high_resolution_clock::now();
        readFileList(filename, students);
        auto end = chrono::high_resolution_clock::now();
        cout << "1. Read:  " << chrono::duration<double>(end - start).count() << " s\n";

        start = chrono::high_resolution_clock::now();
        students.sort(compareByGrade);
        end = chrono::high_resolution_clock::now();
        cout << "2. Sort:  " << chrono::duration<double>(end - start).count() << " s\n";

        start = chrono::high_resolution_clock::now();
        for (const auto& s : students) {
            if (s.getFinalGrade() < 5.0) failed.push_back(s);
            else passed.push_back(s);
        }
        end = chrono::high_resolution_clock::now();
        cout << "3. Split: " << chrono::duration<double>(end - start).count() << " s\n";

        start = chrono::high_resolution_clock::now();
        writeFileList("failed_list_" + to_string(count) + ".txt", failed);
        writeFileList("passed_list_" + to_string(count) + ".txt", passed);
        end = chrono::high_resolution_clock::now();
        cout << "4. Write: " << chrono::duration<double>(end - start).count() << " s\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }
}

int main() {
    int sizes[5] = {1000, 10000, 100000, 1000000, 10000000};

    for (int i = 0; i < 5; i++) {
        generateFile("students_" + to_string(sizes[i]) + ".txt", sizes[i]);
    }

    for (int i = 0; i < 5; i++) testDeque(sizes[i]);
    for (int i = 0; i < 5; i++) testList(sizes[i]);

    return 0;
}
