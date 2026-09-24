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
    // Constructor
    Person();

    // Copy constructor
    Person(const Person& other);

    // Assignment-copy operator
    Person& operator=(const Person& other);

    // Destructor
    ~Person();

    // Input and output operators
    friend istream& operator>>(istream& in, Person& person);
    friend ostream& operator<<(ostream& out, const Person& person);

    // Calculate final grade using average
    double calculateAverage() const;

    // Calculate final grade using median
    double calculateMedian() const;

    // Get student information
    string getFirstName() const;
    string getSurname() const;
    double getFinalGrade() const;
};

#endif
