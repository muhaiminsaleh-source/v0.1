#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>
#include "Person.h"
#include "FileHandler.h"

using namespace std;

void testFile(int count) {
    string filename = "students_" + to_string(count) + ".txt";
    cout << "\n--- Testing " << count << " records ---\n";

    try {
        generateFile(filename, count);

        vector<Person> students;
        vector<Person> passed;
        vector<Person> failed;

        // 1. Read time
        auto start = chrono::high_resolution_clock::now();
        readFile(filename, students);
        auto end = chrono::high_resolution_clock::now();
        cout << "1. Read time:  " << chrono::duration<double>(end - start).count() << " s\n";

        // 2. Sort time
        start = chrono::high_resolution_clock::now();
        sort(students.begin(), students.end(), compareByGrade);
        end = chrono::high_resolution_clock::now();
        cout << "2. Sort time:  " << chrono::duration<double>(end - start).count() << " s\n";

        // 3. Split time
        start = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].getFinalGrade() < 5.0) {
                failed.push_back(students[i]);
            } else {
                passed.push_back(students[i]);
            }
        }
        end = chrono::high_resolution_clock::now();
        cout << "3. Split time: " << chrono::duration<double>(end - start).count() << " s\n";

        // 4. Write time
        start = chrono::high_resolution_clock::now();
        writeFile("failed_" + to_string(count) + ".txt", failed);
        writeFile("passed_" + to_string(count) + ".txt", passed);
        end = chrono::high_resolution_clock::now();
        cout << "4. Write time: " << chrono::duration<double>(end - start).count() << " s\n";

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }
}

int main() {
    int sizes[5] = {1000, 10000, 100000, 1000000, 10000000};

    for (int i = 0; i < 5; i++) {
        testFile(sizes[i]);
    }

    return 0;
}
