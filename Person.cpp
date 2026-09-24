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
        person.homework.push_back(mark);
        cout << "Enter next homework mark (-1 to finish): ";
    }

    cout << "Enter exam mark: ";
    in >> person.exam;

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
    {
        return 0.6 * exam;
    }

    double sum = 0;

    for (int mark : homework)
    {
        sum += mark;
    }

    double average = sum / homework.size();

    return 0.4 * average + 0.6 * exam;
}

double Person::calculateMedian() const
{
    if (homework.empty())
    {
        return 0.6 * exam;
    }

    vector<int> sortedHomework = homework;

    sort(sortedHomework.begin(), sortedHomework.end());

    double median;
    int n = sortedHomework.size();

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
