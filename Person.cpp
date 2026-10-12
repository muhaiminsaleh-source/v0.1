```cpp
#include "Person.h"
#include <algorithm>
#include <iomanip>
#include <limits>

Person::Person()
{
    firstName = "";
    surname = "";
    exam = 0;
    finalGrade = 0.0;
}

Person::Person(const Person& other)
{
    firstName = other.firstName;
    surname = other.surname;
    homework = other.homework;
    exam = other.exam;
    finalGrade = other.finalGrade;
}

Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        firstName = other.firstName;
        surname = other.surname;
        homework = other.homework;
        exam = other.exam;
        finalGrade = other.finalGrade;
    }

    return *this;
}

Person::~Person()
{
}

istream& operator>>(istream& in, Person& person)
{
    cout << "Enter first name: ";
    in >> person.firstName;

    cout << "Enter surname: ";
    in >> person.surname;

    person.homework.clear();

    int mark;

    cout << "Enter homework marks (-1 to finish): ";

    while (in >> mark && mark != -1)
    {
        if (mark < 0 || mark > 10)
        {
            cout << "Mark must be between 0 and 10. Try again: ";
            continue;
        }

        person.homework.push_back(mark);
        cout << "Enter next homework mark (-1 to finish): ";
    }

    if (in.fail())
        return in;

    cout << "Enter exam mark (0-10): ";

    while (in >> person.exam)
    {
        if (person.exam >= 0 && person.exam <= 10)
            break;

        cout << "Invalid mark. Enter a mark from 0 to 10: ";
    }

    if (in)
        person.finalGrade = person.calculateAverage();

    return in;
}

ostream& operator<<(ostream& out, const Person& person)
{
    out << left << setw(12) << person.firstName
        << setw(15) << person.surname
        << right << fixed << setprecision(2)
        << person.finalGrade;

    return out;
}

double Person::calculateAverage() const
{
    if (homework.empty())
        return 0.6 * exam;

    double sum = 0.0;

    for (int mark : homework)
        sum += mark;

    double average = sum / homework.size();

    return 0.4 * average + 0.6 * exam;
}

double Person::calculateMedian() const
{
    if (homework.empty())
        return 0.6 * exam;

    vector<int> sortedHomework = homework;

    sort(sortedHomework.begin(), sortedHomework.end());

    int n = static_cast<int>(sortedHomework.size());
    double median;

    if (n % 2 == 1)
    {
        median = sortedHomework[n / 2];
    }
    else
    {
        median = (sortedHomework[n / 2 - 1]
                + sortedHomework[n / 2]) / 2.0;
    }

    return 0.4 * median + 0.6 * exam;
}

string Person::getFirstName() const
{
    return firstName;
}

string Person::getSurname() const
{
    return surname;
}

double Person::getFinalGrade() const
{
    return finalGrade;
}

void Person::setData(const string& name,
                     const string& lastName,
                     const vector<int>& hw,
                     int examMark)
{
    firstName = name;
    surname = lastName;
    homework = hw;
    exam = examMark;

    finalGrade = calculateAverage();
}
```
