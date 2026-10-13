```cpp
#include "Person.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <random>
#include <limits>

using namespace std;

void sortStudents(vector<Person>& students)
{
    sort(students.begin(), students.end(),
        [](const Person& a, const Person& b)
        {
            if (a.getSurname() == b.getSurname())
                return a.getFirstName() < b.getFirstName();

            return a.getSurname() < b.getSurname();
        });
}

bool readStudentsFromFile(vector<Person>& students)
{
    ifstream file("Students.txt");

    if (!file.is_open())
    {
        cerr << "Error: Could not open Students.txt\n";
        return false;
    }

    string line;
    getline(file, line); // Skip header

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);
        string name, surname;
        vector<int> marks;
        int mark;

        if (!(ss >> name >> surname))
            continue;

        bool valid = true;

        while (ss >> mark)
        {
            if (mark < 0 || mark > 10)
            {
                valid = false;
                break;
            }

            marks.push_back(mark);
        }

        if (!valid || !ss.eof() || marks.size() < 2)
        {
            cerr << "Skipping invalid row: "
                 << name << " " << surname << '\n';
            continue;
        }

        int exam = marks.back();
        marks.pop_back();

        Person student;
        student.setData(name, surname, marks, exam);
        students.push_back(student);
    }

    return !students.empty();
}

void generateRandomStudents(vector<Person>& students)
{
    int count;

    cout << "How many students should be generated? ";

    if (!(cin >> count) || count <= 0)
    {
        cerr << "Invalid number of students.\n";
        return;
    }

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, 10);

    for (int i = 1; i <= count; i++)
    {
        vector<int> homework;

        // Generate five homework marks
        for (int j = 0; j < 5; j++)
            homework.push_back(distribution(generator));

        int exam = distribution(generator);

        Person student;
        student.setData(
            "Name" + to_string(i),
            "Surname" + to_string(i),
            homework,
            exam
        );

        students.push_back(student);
    }
}

void enterStudentsManually(vector<Person>& students)
{
    int count;

    cout << "How many students do you want to enter? ";

    if (!(cin >> count) || count <= 0)
    {
        cerr << "Invalid number of students.\n";
        return;
    }

    for (int i = 0; i < count; i++)
    {
        Person student;

        cout << "\nStudent " << i + 1 << '\n';
        cout << "Enter homework marks one by one.\n";
        cout << "Enter -1 when all homework marks are entered.\n";

        if (!(cin >> student))
        {
            cerr << "Invalid input. Please restart the program.\n";
            return;
        }

        students.push_back(student);
    }
}

void printStudents(const vector<Person>& students, int method)
{
    cout << '\n'
         << left << setw(15) << "Name"
         << setw(15) << "Surname"
         << right << setw(15) << "Final (Avg.)"
         << " | " << setw(12) << "Final (Med.)"
         << " | " << setw(15) << "Selected Grade"
         << '\n';

    cout << string(80, '-') << '\n';

    for (const Person& student : students)
    {
        double average = student.calculateAverage();
        double median = student.calculateMedian();
        double selectedGrade = (method == 1) ? average : median;

        cout << left << setw(15) << student.getFirstName()
             << setw(15) << student.getSurname()
             << right << fixed << setprecision(2)
             << setw(15) << average
             << " | " << setw(12) << median
             << " | " << setw(15) << selectedGrade
             << '\n';
    }

    cout << "\nSelected calculation method: "
         << (method == 1 ? "Average" : "Median") << '\n';
}

int main()
{
    vector<Person> students;
    int choice;

    cout << "Student Grade Calculator\n";
    cout << "1. Read students from Students.txt\n";
    cout << "2. Generate random students\n";
    cout << "3. Enter students manually\n";
    cout << "Choose an option: ";

    if (!(cin >> choice))
    {
        cerr << "Invalid choice.\n";
        return 1;
    }

    if (choice == 1)
    {
        if (!readStudentsFromFile(students))
        {
            cerr << "No valid student records found.\n";
            return 1;
        }
    }
    else if (choice == 2)
    {
        generateRandomStudents(students);

        if (students.empty())
            return 1;
    }
    else if (choice == 3)
    {
        enterStudentsManually(students);

        if (students.empty())
            return 1;
    }
    else
    {
        cerr << "Please choose 1, 2, or 3.\n";
        return 1;
    }

    int method;

    cout << "\nChoose final grade calculation method:\n";
    cout << "1. Average\n";
    cout << "2. Median\n";
    cout << "Your choice: ";

    if (!(cin >> method) || (method != 1 && method != 2))
    {
        cerr << "Invalid calculation method.\n";
        return 1;
    }

    sortStudents(students);
    printStudents(students, method);

    return 0;
}
```
