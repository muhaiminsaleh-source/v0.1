#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
private:
    string firstName;
    string surname;
    vector<int> homework;
    int exam;
    double finalGrade;

public:
    Person();

    Person(const Person& other);

    Person& operator=(const Person& other);

    ~Person();

    friend istream& operator>>(istream& in, Person& person);
    friend ostream& operator<<(ostream& out, const Person& person);

    double calculateAverage() const;

    double calculateMedian() const;

    string getFirstName() const;
    string getSurname() const;
    double getFinalGrade() const;
};

#endif
