#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <chrono>
#include <string>
#include "Person.h"
#include "FileHandler.h"

using namespace std;

bool isFailed(const Person& p) {
    return p.getFinalGrade() < 5.0;
}

bool isPassed(const Person& p) {
    return p.getFinalGrade() >= 5.0;
}

bool fileExists(string filename) {
    ifstream f(filename);
    return f.good();
}

void runStrategy1(int count) {
    string filename = "students_" + to_string(count) + ".txt";
    cout << "\n=== Strategy 1 (" << count << " records) ===\n";

    vector<Person> vStudents, vPassed, vFailed;
    readFile(filename, vStudents);
    auto start = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < vStudents.size(); i++) {
        if (isFailed(vStudents[i])) vFailed.push_back(vStudents[i]);
        else vPassed.push_back(vStudents[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "Vector split: " << chrono::duration<double>(end - start).count() << " s\n";

    deque<Person> dStudents, dPassed, dFailed;
    readFileDeque(filename, dStudents);
    start = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < dStudents.size(); i++) {
        if (isFailed(dStudents[i])) dFailed.push_back(dStudents[i]);
        else dPassed.push_back(dStudents[i]);
    }
    end = chrono::high_resolution_clock::now();
    cout << "Deque split:  " << chrono::duration<double>(end - start).count() << " s\n";

    list<Person> lStudents, lPassed, lFailed;
    readFileList(filename, lStudents);
    start = chrono::high_resolution_clock::now();
    for (auto it = lStudents.begin(); it != lStudents.end(); ++it) {
        if (isFailed(*it)) lFailed.push_back(*it);
        else lPassed.push_back(*it);
    }
    end = chrono::high_resolution_clock::now();
    cout << "List split:   " << chrono::duration<double>(end - start).count() << " s\n";
}

void runStrategy2(int count) {
    string filename = "students_" + to_string(count) + ".txt";
    cout << "\n=== Strategy 2 (" << count << " records) ===\n";

    vector<Person> vStudents, vFailed;
    readFile(filename, vStudents);
    auto start = chrono::high_resolution_clock::now();
    size_t keep = 0;
    for (size_t i = 0; i < vStudents.size(); i++) {
        if (isFailed(vStudents[i])) {
            vFailed.push_back(vStudents[i]);
        } else {
            vStudents[keep] = vStudents[i];
            keep++;
        }
    }
    vStudents.resize(keep);
    vStudents.shrink_to_fit();
    auto end = chrono::high_resolution_clock::now();
    cout << "Vector split: " << chrono::duration<double>(end - start).count() << " s\n";

    deque<Person> dStudents, dFailed;
    readFileDeque(filename, dStudents);
    start = chrono::high_resolution_clock::now();
    keep = 0;
    for (size_t i = 0; i < dStudents.size(); i++) {
        if (isFailed(dStudents[i])) {
            dFailed.push_back(dStudents[i]);
        } else {
            dStudents[keep] = dStudents[i];
            keep++;
        }
    }
    dStudents.resize(keep);
    dStudents.shrink_to_fit();
    end = chrono::high_resolution_clock::now();
    cout << "Deque split:  " << chrono::duration<double>(end - start).count() << " s\n";

    list<Person> lStudents, lFailed;
    readFileList(filename, lStudents);
    start = chrono::high_resolution_clock::now();
    for (auto it = lStudents.begin(); it != lStudents.end(); ) {
        if (isFailed(*it)) {
            lFailed.push_back(*it);
            it = lStudents.erase(it);
        } else {
            ++it;
        }
    }
    end = chrono::high_resolution_clock::now();
    cout << "List split:   " << chrono::duration<double>(end - start).count() << " s\n";
}

void runOptimized(int count) {
    string filename = "students_" + to_string(count) + ".txt";
    cout << "\n=== Optimized Vector with <algorithm> (" << count << " records) ===\n";

    vector<Person> students, failed;
    readFile(filename, students);

    auto start = chrono::high_resolution_clock::now();
    remove_copy_if(students.begin(), students.end(), back_inserter(failed), isPassed);
    students.erase(remove_if(students.begin(), students.end(), isFailed), students.end());
    students.shrink_to_fit();
    auto end = chrono::high_resolution_clock::now();

    cout << "Vector (<algorithm>) split: " << chrono::duration<double>(end - start).count() << " s\n";
}

int main() {
    int sizes[4] = {1000, 10000, 100000, 1000000};

    for (int i = 0; i < 4; i++) {
        string fname = "students_" + to_string(sizes[i]) + ".txt";
        if (!fileExists(fname)) {
            generateFile(fname, sizes[i]);
        }
    }

    int choice = -1;
    while (choice != 0) {
        cout << "\n--- MENU (v1.0) ---\n";
        cout << "1. Strategy 1 (Two new containers: passed & failed)\n";
        cout << "2. Strategy 2 (One new container: failed, shrink original)\n";
        cout << "3. Optimized Vector using <algorithm>\n";
        cout << "0. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < 4; i++) runStrategy1(sizes[i]);
        } else if (choice == 2) {
            for (int i = 0; i < 4; i++) runStrategy2(sizes[i]);
        } else if (choice == 3) {
            for (int i = 0; i < 4; i++) runOptimized(sizes[i]);
        } else if (choice == 0) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid option!\n";
        }
    }

    return 0;
}