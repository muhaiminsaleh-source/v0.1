
#include "Person.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<Person> students;
    int numberOfStudents;

    cout << "Enter number of students: ";
    cin >> numberOfStudents;

    if (numberOfStudents <= 0)
    {
        cout << "Invalid number of students.\n";
        return 1;
    }

    for (int i = 0; i < numberOfStudents; i++)
    {
        Person student;

        cout << "\nStudent " << i + 1 << '\n';
        cin >> student;

        students.push_back(student);
    }

    sort(students.begin(), students.end(),
        [](const Person& a, const Person& b)
        {
            return a.getSurname() < b.getSurname();
        });

    cout << "\n"
         << left << setw(15) << "Name"
         << setw(15) << "Surname"
         << right << setw(15) << "Final (Avg.)"
         << setw(15) << "Final (Med.)"
         << '\n';

    cout << string(60, '-') << '\n';

    for (const Person& student : students)
    {
        cout << left << setw(15) << student.getFirstName()
             << setw(15) << student.getSurname()
             << right << setw(15)
             << fixed << setprecision(2)
             << student.calculateAverage()
             << setw(15)
             << student.calculateMedian()
             << '\n';
    }

    return 0;
}
