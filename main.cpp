#include "Person.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool compareByName(const Person& a, const Person& b) {
    if (a.getName() == b.getName()) {
        return a.getSurname() < b.getSurname();
    }
    return a.getName() < b.getName();
}

int main() {
    vector<Person> students;
    int choice;

    cout << "Select an option:\n";
    cout << "1. Enter data manually\n";
    cout << "2. Generate random homework and exam scores\n";
    cout << "3. Read from Students.txt\n";
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "How many students? ";
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; ++i) {
            Person p;
            cout << "Enter (Name Surname HW_Marks... Exam_Mark) in one line:\n";
            cin >> p;
            students.push_back(p);
        }
    } 
    else if (choice == 2) {
        int n, hwCount;
        cout << "How many students? ";
        cin >> n;
        cout << "How many homeworks per student? ";
        cin >> hwCount;
        for (int i = 0; i < n; ++i) {
            Person p;
            p.setName("Name" + to_string(i + 1));
            p.setSurname("Surname" + to_string(i + 1));
            p.generateRandomScores(hwCount);
            students.push_back(p);
        }
    } 
    else if (choice == 3) {
        ifstream file("Students.txt");
        if (!file) {
            cout << "Error: Cannot open Students.txt\n";
            return 1;
        }
        string headerLine;
        getline(file, headerLine);
        Person p;
        while (file >> p) {
            students.push_back(p);
        }
        file.close();
    } else {
        cout << "Invalid choice!\n";
        return 1;
    }

    sort(students.begin(), students.end(), compareByName);

    cout << "\n" << left << setw(15) << "Name" << setw(15) << "Surname" 
         << "Final (Avg.) | Final (Med.)\n";
    cout << "------------------------------------------------------\n";
    for (const auto& student : students) {
        cout << student << "\n";
    }

    return 0;
}
