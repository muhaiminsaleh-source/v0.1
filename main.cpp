
#include "Person.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <random>

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

void printStudents(const vector<Person>& students)
{
    cout << '\n'
         << left << setw(15) << "Name"
         << setw(15) << "Surname"
         << right << setw(15) << "Final (Avg.)"
         << setw(15) << "Final (Med.)" << '\n';

    cout << string(60, '-') << '\n';

    for (const Person& student : students)
    {
        cout << left << setw(15) << student.getFirstName()
             << setw(15) << student.getSurname()
             << right << fixed << setprecision(2)
             << setw(15) << student.calculateAverage()
             << setw(15) << student.calculateMedian()
             << '\n';
    }
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

    // Skip the header row
    getline(file, line);

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);
        string name, surname;
        vector<int> marks;
        int mark;

        if (!(ss >> name >> surname))
        {
            cerr << "Warning: Invalid row skipped.\n";
            continue;
        }

        while (ss >> mark)
        {
            if (mark < 0 || mark > 10)
                break;

            marks.push_back(mark);
        }

        if (marks.size() < 2)
        {
            cerr << "Warning: Not enough valid marks for "
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
    uniform_int_distribution<int> markDistribution(0, 10);

    for (int i = 1; i <= count; i++)
    {
        vector<int> homework;

        // Generate five homework marks
        for (int j = 0; j < 5; j++)
            homework.push_back(markDistribution(generator));

        int exam = markDistribution(generator);

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

int main()
{
    vector<Person> students;
    int choice;

    cout << "Student Grade Calculator\n";
    cout << "1. Read students from Students.txt\n";
    cout << "2. Generate random students\n";
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
            cerr << "Could not load student data.\n";
            return 1;
        }
    }
    else if (choice == 2)
    {
        generateRandomStudents(students);

        if (students.empty())
            return 1;
    }
    else
    {
        cerr << "Please choose 1 or 2.\n";
        return 1;
    }

    sortStudents(students);
    printStudents(students);

    return 0;
}
