
#include "Person.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    vector<Person> students;
    ifstream file("Students.txt");

    if (!file.is_open())
    {
        cerr << "Error: Could not open Students.txt\n";
        return 1;
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
            cerr << "Warning: Invalid student row skipped.\n";
            continue;
        }

        while (ss >> mark)
            marks.push_back(mark);

        // Five homework marks and one exam mark are expected
        if (marks.size() < 2)
        {
            cerr << "Warning: Not enough marks for "
                 << name << " " << surname << '\n';
            continue;
        }

        int exam = marks.back();
        marks.pop_back();

        Person student;
        student.setData(name, surname, marks, exam);
        students.push_back(student);
    }

    file.close();

    if (students.empty())
    {
        cerr << "No student records found.\n";
        return 1;
    }

    // Sort students by surname, then first name
    sort(students.begin(), students.end(),
        [](const Person& a, const Person& b)
        {
            if (a.getSurname() == b.getSurname())
                return a.getFirstName() < b.getFirstName();

            return a.getSurname() < b.getSurname();
        });

    cout << left << setw(15) << "Name"
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

    return 0;
}
